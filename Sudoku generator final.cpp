#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[10][10],lis[10][10][10],tail[10][10];

int Hor(int r,int c,int i)//r,c - row and column coordinates where number i is to be assigned
{
    for(int j=1; j<=9; j++)
        if(j!=c)
            if(arr[r][j]==i)
                return false;
    return true;
}//Checks if another instance of the assigned number is present in same row

int Vert(int r,int c,int i)
{
    for(int j=1; j<=9; j++)
        if(j!=r)
            if(arr[j][c]==i)
                return false;
    return true;
}//Checks if another instance of assigned number is present in same column

int Box(int r,int c,int i)
{
    for(int l=1; l<=3; l++)
        for(int m=1; m<=3; m++)
            if(r%3==0 && c%3==0)
            {
                if(arr[l+r-3][m+c-3]==i)
                    return false;
            }
            else if(r%3==0)
            {
                if(arr[l+r-3][m+c-(c%3)]==i)
                    return false;
            }
            else if(c%3==0)
            {
                if(arr[l+r-(r%3)][m+c-3]==i)
                    return false;
            }
            else
            {
                if(arr[l+r-(r%3)][m+c-(c%3)]==i)
                    return false;
            }
    return true;
}//Checks if another instance of assigned number is present in same box
int nextcell_row(int r,int c)
{
    if(c==9)
        return r+1;
    else
        return r;
}//Returns row coordinate of next cell

int nextcell_column(int r,int c)
{
    if(c==9)
        return 1;
    else
        return c+1;
}//Returns column coordinate of next cell

void add(int r,int c,int i)
{
    lis[r][c][tail[r][c]]=i;
    tail[r][c]++;

}

void del(int r,int c,int i)
{
    int ind;
    for(int j=1; j<tail[r][c]; j++)
        if(lis[r][c][j]==i)
        {
            ind=j;
            break;
        }
    for(int j=ind; j<(tail[r][c]-1); j++)
    {
        lis[r][c][j]=lis[r][c][j+1];
    }
    tail[r][c]--;
}

void formlist(int r,int c)
{
    for(int i=1; i<=9; i++)
    {
        if(Hor(r,c,i) && Vert(r,c,i) && Box(r,c,i))
            add(r,c,i);
    }
}

bool genrate(int r,int c)
{
    formlist(r,c);
    HERE:
        if(tail[r][c]==1)
            return false;
        if(r==9 && c==9)
        {
            arr[r][c]=lis[r][c][1];
            return true;
        }
        int num=lis[r][c][(rand()%(tail[r][c]-1))+1];
        arr[r][c]=num;
        if(genrate(nextcell_row(r,c),nextcell_column(r,c)))
            return true;
        else
        {
            del(r,c,num);
            arr[r][c]=0;
            goto HERE;
        }
}

int findsoln(int r,int c,int counter)
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

int solutions()
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

int main()
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
    for(int r=1; r<=9; r++)
    {
        for(int c=1; c<=9; c++)
        {
            cout<<arr[r][c]<<' ';
        }
        cout<<endl;
    }
    srand((unsigned)time(NULL));
    int counter=0;
    int j,r,c;
    while(counter<55)
    {
        //cout<<"HI";
        r=(rand()%9)+1;
        c=(rand()%9)+1;
        j=arr[r][c];
        arr[r][c]=0;
        counter++;
        if(solutions()==2)
        {
            arr[r][c]=j;
            counter--;
        }
    }
    cout<<endl<<endl;
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }

}

