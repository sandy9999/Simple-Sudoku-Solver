//Hit c to check
#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include <fstream.h>
int a[10][10],user[10][10],s[10][10],key[100];
void creategrid();
char quit;

void navigate()
{
 int curc=21,curr=2,noc=21,nor=3;
 char ch='y';
 gotoxy(curc,curr);
 cout<<'_';
 while(ch!='q'||ch!='Q')
 { ch=getch();
  if(isdigit(ch)&&ch!='0')
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
     {gotoxy(26,25);
      cout<<"Are you sure you want to quit(y/n)";
       cin>>quit;
       if(quit=='y'||quit=='Y')
       return;
       else
       {gotoxy(26,25);
      cout<<"                                    ";
      }

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
      setcolor(WHITE);
      for(i=150;ct1<9;i+=40,ct1++)
      {
       ct2=0;
       for(j=20;ct2<9;j+=40,ct2++)
       rectangle(i,j,i+40,j+40);}
       int m,n;
       ct1=0;
       for(m=150;ct1<4;m+=120,ct1++)
       {setcolor(RED);
       line(m,20,m,380);}
       ct1=0;
       for(n=20;ct1<4;n+=120,ct1++)
       {
	setcolor(RED);
	line(150,n,510,n);}

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
      }




