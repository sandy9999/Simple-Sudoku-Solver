#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, i,j;
   initgraph(&gdriver, &gmode,"c:/TURBOC3/bgi");
   int a[9][9],m,n,x=21,y=3;
   for(m=0;m<9;m++)
    for(n=0;n<9;n++)
    a[m][n]=0;
   for(m=0;m<9;m++,y+=2)
   { for(n=0;n<9;n++,x+=5)
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

   }
     getch();
   closegraph();
   return 0;
}





/*gotoxy(0,0);
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";
    cout<<"Screw turboScrew turboScrew turboScrew turboScrew turboScrew turbo\n";

    */
