#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>
#include "C:/TURBOC3/BIN/PROJECT/SUDOKUGE.CPP"
#include "C:/TURBOC3/BIN/PROJECT/NAVIGATE.CPP"
void credits()
{
clrscr();
 int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
  setbkcolor(WHITE);
  setcolor(BLUE);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
  outtextxy(5,90,"CREDITS:");
  setcolor(CYAN);
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(5,200,"HARISH.T");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(5,240,"SANDHYA SARAVANAN");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(5,280,"ANISHKUMAR.SS");
getch();
closegraph();
}
void main()
{ clrscr();
  char h[6][25]={"WELCOME", "TO", "THE", "WORLD","OF", "SUDOKU"};
 int gdriver=DETECT,gmode,j=150,i;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
  setbkcolor(WHITE);
  setcolor(MAGENTA);
  for(i=0;i<3;i++)
  {getch();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(j,150,h[i]);
  j+=150;
  } j=200;
  for(i=3;i<5;i++)
  {
   getch();
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(j,190,h[i]);
  j+=150;
  }
  getch();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(250,230,"SUDOKU");
  getch();
 closegraph();

MENU:
clrscr();
 int sdriver=DETECT,smode;
    initgraph(&sdriver,&smode,"c:/turboc3/bgi");
int choice,diff;// Diff is the variable which accepts the difficulty level from the user
char ch, s[100];
setbkcolor(WHITE);
setcolor(GREEN);
settextstyle(BOLD_FONT, HORIZ_DIR, 2);
outtextxy(210,2,"SUDOKU");
settextstyle(BOLD_FONT, HORIZ_DIR, 2);
outtextxy(5,90,"MENU");
setcolor(BLUE);
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(5,140,"1.NEW GAME");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(5,180,"2.INSTRUCTIONS");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(5,220,"3.ABOUT THE GAME");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(5,260,"4.QUIT");
setcolor(RED);
settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
outtextxy(20,320,"ENTER YOUR CHOICE(1,2,3,4):");
gotoxy(49,22);
cin>>choice;
closegraph();
fstream x("C:/TURBOC3/BIN/PROJECT/Ins.txt",ios::in);
fstream y("C:/TURBOC3/BIN/PROJECT/About.txt",ios::in);
if(choice==1)
 { clrscr();
 int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
    setbkcolor(WHITE);
    setcolor(GREEN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 2);
outtextxy(5,90,"CHOOSE THE DIFFICULTY LEVEL(1,2,3)");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
setcolor(BLUE);
outtextxy(5,150,"1.EASY()");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(5,190,"2.MEDIUM()");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(5,230,"3.HARD()");
gotoxy(30,16);
   cin>>diff;
   closegraph();
   if(diff==1)
    lev=40;
   if(diff==2)
    lev=45;
   if(diff==3)
    lev=50;
   gen();
   navigation();
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
 int gdriver=DETECT,gmode,i=50;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
    setbkcolor(WHITE);
    setcolor(BLUE);
 if(!x)
  {
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   outtextxy(5,50,"file not found");}
 else
   while(!x.eof())
     {setcolor(RED);
     x.getline(s,80,'.');
     outtextxy(5,i,s);
     i+=25;
     }
     x.close();
     setcolor(BLUE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   outtextxy(20,450,"do you want to return to menu(y/n)");
   gotoxy(49,25);
   cin>>ch;
   if(ch=='y'||ch=='Y')
    goto MENU;
   else
    credits();
    closegraph();
 //link to the text file containing the instructions
 }
else if(choice==3)
 {  clrscr();
  int gdriver=DETECT,gmode,i=50;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
    setbkcolor(WHITE);
    setcolor(BLUE);
  if(!y)
   {
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   outtextxy(5,50,"file not found");}
  else
   while(!y.eof())
     {setcolor(RED);
     y.getline(s,80,'.');
     outtextxy(5,i,s);
     i+=25;
     }
     y.close();
     setcolor(BLUE);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   outtextxy(20,450,"do you want to return to menu(y/n)");
   gotoxy(49,25);
   cin>>ch;
   if(ch=='y'||ch=='Y')
    goto MENU;
   else
    credits();
    closegraph();
 //link to the text file containg the brief history of the game
 }
else if(choice==4)
 {
   credits();
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
