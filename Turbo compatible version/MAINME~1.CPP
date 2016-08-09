#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>
#include "C:/TURBOC3/BIN/PROJECT/SUDOKUGE.CPP"
#include "C:/TURBOC3/BIN/PROJECT/DISP.CPP"

char a[9][9];
/*
void main()
{
/* int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
MENU:
clrscr(); disp();
int choice;
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
 fstream z("C:/TURBOC3/BIN/PUZZLE.txt",ios::in);
 while(!z.eof())
     {
     z.getline(s,1000);
     cout<<s<<endl;;
     }
     z.close();
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
 */

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
}