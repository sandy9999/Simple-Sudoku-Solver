#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
int arr[10][10],lis[10][10][10],tail[10][10];
int lev;
void creategrid();

class Sudoku
{
  private:
  int solutions();
  int findsoln(int r,int c,int counter);
  int genrate(int r,int c);
  void formlist(int r,int c);
  void del(int r,int c,int i);
  void add(int r,int c,int i);
  int nextcell_column(int r,int c);
  int nextcell_row(int r,int c);
  int Hor(int r,int c,int i);
  int Vert(int r,int c,int i);
  int Box(int r,int c,int i);
  public:
  void solved();
  void unsolved();

};

void Sudoku::solved()
  {
     for(int r=1; r<=9; r++)
    {
	for(int c=1; c<=9; c++)
	{
	    arr[r][c]=0;
	    tail[r][c]=1;
	}
    }
    srand((unsigned)time(NULL));
    genrate(1,1);
 }
 void Sudoku::unsolved()
  {
    srand((unsigned)time(NULL));
    int counter=0;
    int j,r,c;
    while(counter<lev)
    {
	//cout<<"HI";
	r=(rand()%9)+1;
	c=(rand()%9)+1;
	j=arr[r][c];
      if(j!=0)
{	arr[r][c]=0;
	counter++;
	if(solutions()==2)
	{
	    arr[r][c]=j;
	    counter--;
	}
}
    }
  }


int Sudoku::Hor(int r,int c,int i) //r,c - row and column coordinates where number i is to be assigned
{
    for(int j=1; j<=9; j++)
	if(j!=c)
	    if(arr[r][j]==i)
		return 0;
    return 1;
}//Checks if another instance of the assigned number is present in same row

int Sudoku::Vert(int r,int c,int i)
{
    for(int j=1; j<=9; j++)
	if(j!=r)
	    if(arr[j][c]==i)
		return 0;
    return 1;
}//Checks if another instance of assigned number is present in same column

int Sudoku::Box(int r,int c,int i)
{
    for(int l=1; l<=3; l++)
	for(int m=1; m<=3; m++)
	    if(r%3==0 && c%3==0)
	    {
		if(arr[l+r-3][m+c-3]==i)
		    return 0;
	    }
	    else if(r%3==0)
	    {
		if(arr[l+r-3][m+c-(c%3)]==i)
		    return 0;
	    }
	    else if(c%3==0)
	    {
		if(arr[l+r-(r%3)][m+c-3]==i)
		    return 0;
	    }
	    else
	    {
		if(arr[l+r-(r%3)][m+c-(c%3)]==i)
		    return 0;
	    }
    return 1;
}//Checks if another instance of assigned number is present in same box
int Sudoku::nextcell_row(int r,int c)
{
    if(c==9)
	return r+1;
    else
	return r;
}//Returns row coordinate of next cell

int Sudoku::nextcell_column(int r,int c)
{
    r=r;
    if(c==9)
	return 1;
    else
	return c+1;
}//Returns column coordinate of next cell

void Sudoku::add(int r,int c,int i)
{
    lis[r][c][tail[r][c]]=i;
    tail[r][c]++;

}

void Sudoku::del(int r,int c,int i)
{
    int ind;
    for(int j=1; j<tail[r][c]; j++)
	if(lis[r][c][j]==i)
	{
	    ind=j;
	    break;
	}
    for(j=ind; j<(tail[r][c]-1); j++)
    {
	lis[r][c][j]=lis[r][c][j+1];
    }
    tail[r][c]--;
}

void Sudoku::formlist(int r,int c)
{
    for(int i=1; i<=9; i++)
    {
	if(Hor(r,c,i) && Vert(r,c,i) && Box(r,c,i))
	    add(r,c,i);
    }
}

int Sudoku::genrate(int r,int c)
{
    formlist(r,c);
    HERE:
	if(tail[r][c]==1)
	    return 0;
	if(r==9 && c==9)
	{
	    arr[r][c]=lis[r][c][1];
	    return 1;
	}
	int num=lis[r][c][(rand()%(tail[r][c]-1))+1];
	arr[r][c]=num;
	if(genrate(nextcell_row(r,c),nextcell_column(r,c)))
	    return 1;
	else
	{
	    del(r,c,num);
	    arr[r][c]=0;
	    goto HERE;
	}
}

int Sudoku::findsoln(int r,int c,int counter)
{
    if(arr[r][c]==0)//If that position is blank in the puzzle
    {
	for(int i=1; i<=9 && counter<2; i++)
	{
	    if(Hor(r,c,i) && Vert(r,c,i) && Box(r,c,i))//If there is no instance of number i in that row, column or box
	    {
		if(r==9 && c==9)//If the last cell has been assigned a number, it means the puzzle has a solution
		{
		    return 1+counter;
		}
		arr[r][c]=i;//Temporarily assign i, for now, there is no loophole in the solution
		//cout<<arr[r][c]<<endl;
		counter=findsoln(nextcell_row(r,c),nextcell_column(r,c),counter);
	    }
	}
	arr[r][c]=0;
	return counter;
    }
    else if(r==9 && c==9)//If the last cell has been reached, and it already has an assigned value, that is still a solution for the puzzle, so return true
    {
	return 1+counter;
    }
    else
    {
	return findsoln(nextcell_row(r,c),nextcell_column(r,c),counter);
    }
}

int Sudoku::solutions()
{
    for(int r=1; r<=9; r++)
    {
	for(int c=1; c<=9; c++)
	{
	    if(arr[r][c]!=0)
	    {
		if(!(Hor(r,c,arr[r][c]) && Vert(r,c,arr[r][c]) && Box(r,c,arr[r][c])))
		    {
			return 0;
		    }
	    }
	}
    }
    return findsoln(1,1,0);//Calls cell (1,1)
}

int gen()
{
   char ch;
   Sudoku s;
   s.solved();
   fstream x("C:/TURBOC3/BIN/PROJECT/Soln.txt",ios::out);
   for(int i=1; i<=9; i++)
   {
     for(int j=1; j<=9; j++)
     {
      ch=arr[i][j]+'0';
      x.put(ch);
      x<<' ';
      }
      x<<endl;
   }
   x.close();
   s.unsolved();
  x.open("C:/TURBOC3/BIN/PROJECT/Puzzle.txt",ios::out);
   for(i=1; i<=9; i++)
   {
     for(int j=1; j<=9; j++)
      {
      ch=arr[i][j]+'0';
      x.put(ch);
      x<<' ';
      }
       x<<endl;
   }
   x.close();
   return 0;
}


void main()
{
/* int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");  */
MENU:
clrscr();
int choice,diff;// Diff is the variable which accepts the difficulty level from the user
char ch, s[100];
cout<<"\n\n\t\t\t\t  SUDOKU"  ;
cout<<"\n\n\tMENU"<<endl;
cout<<"\n1.New Game\t\n2.Instructions\t\n3.About the game\t\n4.Quit" ;
cout<<"\n\nEnter your Choice (1/2/3/4)";
cin>>choice;
fstream x("C:/TURBOC3/PROJECTS/SUDOKU/Ins.txt",ios::in);
fstream y("C:/TURBOC3/PROJECTS/SUDOKU/About.txt",ios::in);
if(choice==1)
 { clrscr();
   cout<<"\nChoose the difficulty level\n\n1.Easy()\n\n2.Medium()\n\n3.Hard()\n";
   cin>>diff;
   if(diff==1)
    lev=45;
   if(diff==2)
    lev=50;
   if(diff==3)
    lev=54;
   gen();
int a[10][10],user[10][10],s[10][10],key[100];
char quit;
   int curc=21,curr=2,noc=21,nor=3;
 char ch='y';
 gotoxy(curc,curr);
 cout<<'_';
 while(ch!='q'||ch!='Q')
 { ch=getch();
  if(isdigit(ch))
  {
  //cout<<a[key[nor]][key[noc]];
  gotoxy(noc,nor);
  if(a[key[nor]][key[noc]]==0)
  {
  gotoxy(noc,nor);
  cout<<ch;
  gotoxy(noc,nor);
  user[key[nor]][key[noc]]=ch-'0';
  }
  }
  if(ch=='s')
  {
   gotoxy(curc,curr);
   cout<<' ';
   if(nor!=23)
   {
   curr+=2;
   nor+=2;
   }
   if(nor-2==5 || nor-2==10 || nor-2==15 || nor-2==20)
   {
   curr++;
   nor++;
   }
   gotoxy(curc,curr);
   cout<<'_';
   creategrid();
   gotoxy(curc,curr);
   }
   if(ch=='w')
   {
   gotoxy(curc,curr);
   cout<<' ';
   if(nor!=3)
   {
   curr-=2;
   nor-=2;
   }
   if(nor+2==23 || nor+2==18 || nor+2==13 || nor+2==8)
   {
   curr--;
   nor--;
   }
   gotoxy(curc,curr);
   cout<<'_';
   creategrid();
   gotoxy(curc,curr);
   }

   if(ch=='d'||ch=='D')
   {
    gotoxy(curc,curr);
    cout<<' ';
    if(noc!=61)
    {
    curc+=5;
    noc+=5;
    }
    gotoxy(curc,curr);
    cout<<'_';
    creategrid();
    gotoxy(curc,curr);
    }
   if(ch=='a'||ch=='A')
   {
    gotoxy(curc,curr);

    cout<<' ';
    if(noc!=21)
    {
    curc-=5;
    noc-=5;
    }
    gotoxy(curc,curr);
    cout<<'_';
    creategrid();
    gotoxy(curc,curr);
    }
    else if(ch=='q'||ch=='Q')
     { cout<<"Are you sure you want to quit(y/n)";
       cin>>quit;
       if(quit=='y'||quit=='Y')
       break;
     }
    else if(ch=='c' || ch=='C')
    {
       int flag=1;
       for(int k=0; k<9; k++)
	for(int l=0; l<9; l++)
	if(user[k][l]!=s[k][l] && user[k][l]!=-1)
	{ flag=0;
	}
       if(flag==1)
       {
       gotoxy(66,10);
       cout<<"Correct! Go on";
       }
       else
       {
       gotoxy(66,10);
       cout<<"Wrong! Check !";
       }


    }
    else
    gotoxy(curc,curr);
    }
   }

   void creategrid()
   {
      int ct1=0,ct2,i,j;
      for(i=150;ct1<9;i+=40,ct1++)
      {
       ct2=0;
       for(j=20;ct2<9;j+=40,ct2++)
       rectangle(i,j,i+40,j+40);
       }
   }

void puzzleinput()
{
key[21]=0;
key[26]=1;
key[31]=2;
key[36]=3;
key[41]=4;
key[46]=5;
key[51]=6;
key[56]=7;
key[61]=8;
key[3]=0;
key[5]=1;
key[8]=2;
key[10]=3;
key[13]=4;
key[15]=5;
key[18]=6;
key[20]=7;
key[23]=8;

for(int k=0; k<9; k++)
{
 for(int l=0; l<9; l++)
 {
   a[k][l]=-1;
   user[k][l]=-1;
 }
}
  char ch;
 fstream z("C:/TURBOC3/BIN/PROJECT/PUZZLE.txt",ios::in);
 if(!z)
 cout<<"No file\n";
 int i=0,j;

 while(!z.eof())
 {
       while(i<9)
       {
	   j=0;
	   while(j<9)
	   {
	       z.get(ch);
	       if(ch>='0' && ch<='9')
	       {
		   switch(ch)
	{case '0':
	   a[i][j]=0;
	   break;
	case '1':
	   a[i][j]=1;
	   user[i][j]=1;
	   break;
	case '2':
	   a[i][j]=2;
	   user[i][j]=2;
	   break;
	case '3':
	   a[i][j]=3;
	   user[i][j]=3;
	   break;
	case '4':
	   a[i][j]=4;
	   user[i][j]=4;
	   break;
	case '5':
	   a[i][j]=5;
	   user[i][j]=5;
	   break;
	case '6':
	   a[i][j]=6;
	   user[i][j]=6;
	   break;
	case '7':
	   a[i][j]=7;
	   user[i][j]=7;
	   break;
	case '8':
	   a[i][j]=8;
	   user[i][j]=8;
	   break;
	case '9':
	   a[i][j]=9;
	   user[i][j]=9;
	   break;
	default:
	 cout<<"DEFAULT";
	 }
	 j++;
	       }

	   }
	   i++;
       }
       z.get(ch);
 }

  z.close();
  z.open("C:/TURBOC3/BIN/PROJECT/SOLN.txt",ios::in);
 if(!z)
 cout<<"No file\n";
 i=0;

 while(!z.eof())
 {
       while(i<9)
       {
	   j=0;
	   while(j<9)
	   {
	       z.get(ch);
	       if(ch>='0' && ch<='9')
	       {
		   switch(ch)
	{case '0':
	   s[i][j]=0;
	   break;
	case '1':
	   s[i][j]=1;
	   break;
	case '2':
	   s[i][j]=2;
	   break;
	case '3':
	   s[i][j]=3;
	   break;
	case '4':
	   s[i][j]=4;
	   break;
	case '5':
	   s[i][j]=5;
	   break;
	case '6':
	   s[i][j]=6;
	   break;
	case '7':
	   s[i][j]=7;
	   break;
	case '8':
	   s[i][j]=8;
	   break;
	case '9':
	   s[i][j]=9;
	   break;
	default:
	 cout<<"DEFAULT";
	 }
	 j++;
	       }

	   }
	   i++;
       }
       z.get(ch);
 }
  z.close();
   }

   int navigation(void)
   {
    int gdriver=DETECT,gmode,i,j;
    initgraph(&gdriver,&gmode,"C:/TURBOC3/BGI");
    puzzleinput();
    int m,n,x=21,y=3;
    /*for(m=0;m<9;m++)
     for(n=0;n<9;n++)
     a[m][n]=0;*/
     for(m=0;m<9;m++,y+=2)
     {
      for(n=0;n<9;n++,x+=5)
      {
       gotoxy(x,y);
       if(a[m][n]!=0)
       cout<<a[m][n];
       else
	cout<<' ';
       }
       if(m==1)
       y++;
       if(m==3)
       y++;
       if(m==5)
       y++;
       if(m==7)
       y++;
       x=21;
      }
      creategrid();
      getch();
      navigate();
      closegraph();
      return 0;
goto MENU;
/* fstream z("C:/TURBOC3/BIN/PUZZLE.txt",ios::in);
 while(!z.eof())
     {
     z.getline(s,1000);
     cout<<s<<endl;;
     }
     z.close();  */
 }
else if(choice==2)
 { clrscr();
 if(!x)
   cout<<"file not found";
 else
   while(!x.eof())

     {
     x.getline(s,80,'.');
     cout<<s<<endl;
     }
     x.close();
    cout<<"\n\nDo you want return to menu? (y/n)";
   cin>>ch;
   if(ch=='y'||ch=='Y')
    goto MENU;
   else
    exit(0);

 //link to the text file containing the instructions
 }
else if(choice==3)
 {  clrscr();
  if(!y)
   cout<<"file not found";
  else
   while(!y.eof())
     {
     y.getline(s,80,'.');
     cout<<s<<endl;;
     }
     y.close();
   cout<<"\n\n Do you want return to menu? (y/n)";
   cin>>ch;
   if(ch=='y'||ch=='Y')
    goto MENU;
   else
    exit(0);
 //link to the text file containg the brief history of the game
 }
else if(choice==4)
 {
   exit(0);
 }
getch();

}

/*
void main()
{ clrscr();
  for(int k=0; k<9; k++)
  for(int l=0; l<9; l++)
  a[k][l]=-1;
  int i,j=0;
  char ch;
 fstream z("C:/TURBOC3/BIN/PROJECT/PUZZLE.txt",ios::in);
   while(!z.eof())
   { z.get(ch);

       switch(ch)
	{case '0':
	   a[i][j]=0;break;
	case '1':
	   a[i][j]=1;break;
	case '2':
	   a[i][j]=2;break;
	case '3':
	   a[i][j]=3;break;
	case '4':
	   a[i][j]=4;break;
	case '5':
	   a[i][j]=5;break;
	case '6':
	   a[i][j]=6;break;
	case '7':
	   a[i][j]=7;break;
	case '8':
	   a[i][j]=8;break;
	case '9':
	   a[i][j]=9;break;
	default:
	 cout<<"BLA";
	 }
	 j++;
    if(j%9==0)
    {
      i++;
      j=0;
    }
   }
 z.close();
 for(i=0;i<9;i++)
  { for(j=0;j<9;j++)
    cout<<a[i][j];
    cout<<endl;
  } getch();
}*/
