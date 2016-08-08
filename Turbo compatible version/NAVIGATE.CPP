#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
void navigate()
{
 int i=21,j=3;
 char ch,prev;
 gotoxy(i,j);
 cout<<'_';
 while(ch!='q'||ch!='Q')
 { ch=getch();
  if(!isalpha(ch))
  prev=ch;
  if(isdigit(ch))
  {cout<<ch;
  gotoxy(i,j);
  }
  if(ch=='s')
  {
   gotoxy(i,j);
   if(prev=='_')
   cout<<' ';
   if(j!=23)
   j+=2;
   gotoxy(i,j);
   cout<<'_';
   gotoxy(i,j);
   }
   if(ch=='w')
   {
   gotoxy(i,j);
   if(prev=='_')
   cout<<' ';
   if(j!=3)
   j-=2;
   gotoxy(i,j);
   cout<<'_';
   gotoxy(i,j);
   }

   if(ch=='d'||ch=='D')
   {
    gotoxy(i,j);
    if(prev=='_')
    cout<<' ';
    if(i!=66)
    i+=5;
    gotoxy(i,j);
    cout<<'_';
    gotoxy(i,j);
    }
   if(ch=='a'||ch=='A')
   {
    gotoxy(i,j);
    if(prev=='_')

    cout<<' ';
    if(i!=21)
    i-=5;
    gotoxy(i,j);
    cout<<'_';
    gotoxy(i,j);
    }
    else if(ch=='q'||ch=='Q')
    exit(0);
    else
    gotoxy(i,j);
    }
   }
   int main(void)
   {
    int gdriver=DETECT,gmode,i,j;
    initgraph(&gdriver,&gmode,"c:/turboc3/bgi");
    int a[9][9],m,n,x=21,y=3;
    for(m=0;m<9;m++)
     for(n=0;n<9;n++)
     a[m][n]=0;
     for(m=0;m<9;m++,y+=2)
     {
      for(n=0;n<9;n++,x+=5)
      {
       gotoxy(x,y);
       cout<<a[m][n];
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
      int ct1=0,ct2;
      for(i=150;ct1<9;i+=40,ct1++)
      {
       ct2=0;
       for(j=20;ct2<9;j+=40,ct2++)
       rectangle(i,j,i+40,j+40);
       }getch();
      navigate();
      closegraph();
      return 0;
      }




