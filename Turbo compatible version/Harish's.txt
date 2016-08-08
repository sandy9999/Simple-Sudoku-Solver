#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
void  main()
{
 clrscr();
char ch;
int  i=24,j=3;
gotoxy(i,j);
cout<<"7";
gotoxy(i+1,j+1);
cout<<"8";
gotoxy(i+2,j+2);
cout<<"2";
gotoxy(i,j);
while(ch!='q'||ch=='Q')
{
 ch=getch();
if(isdigit(ch))
{cout<<ch;
gotoxy(i,j);}
else if(ch=='a'||ch=='A')
{
 if(i!=24)
i-=1;
gotoxy(i,j);
}
else if(ch=='w'||ch=='W')
{
 if(j!=3)
j-=1;
gotoxy(i,j);
}
else if(ch=='s'||ch=='S')
{
 if(j!=11)
j+=1;
gotoxy(i,j);
}
else if(ch=='d'||ch=='D')
{
 if(i!=32)
i+=1;
 gotoxy(i,j);
}
else if(ch=='q'||ch=='Q')
exit(0);
else
gotoxy(i,j);
}
}







