#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>
#include "C:/TURBOC3/BIN/PROJECT/SUDOKUGE.CPP"
#include "C:/TURBOC3/BIN/PROJECT/DISP.CPP"

int a[9][9];

void main()
{ clrscr();
for(int k=0; k<9; k++)
{
 for(int l=0; l<9; l++)
   a[k][l]=-1;
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
 for(i=0;i<9;i++)
  { for(j=0;j<9;j++)
    cout<<a[i][j];
    cout<<endl;
  }getch();
  }
