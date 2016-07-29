#include <iostream>
#include <cstdlib>
#include <ctime>
int arr[10][10];

using namespace std;

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
                if(arr[l+r-3][m+c-3]==i && !((l+r-3)==r && (m+c-3)==c))
                    return false;
            }
            else if(r%3==0)
            {
                if(arr[l+r-3][m+c-(c%3)]==i && !((l+r-3)==r && (m+c-(c%3))==c))
                    return false;
            }
            else if(c%3==0)
            {
                if(arr[l+r-(r%3)][m+c-3]==i && !((l+r-(r%3))==r && (m+c-3)==c))
                    return false;
            }
            else
            {
                if(arr[l+r-(r%3)][m+c-(c%3)]==i && !((l+r-(r%3))==r && (m+c-(c%3))==c))
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
    bool uniq=true;
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
    for(int i=1; i<=9; i++)
        for(int j=1; j<=9; j++)
            arr[i][j]=0;
    srand((unsigned)time(NULL));
    int j=(rand()%9)+1;
    int r=(rand()%9)+1;
    int c=(rand()%9)+1;
    arr[r][c]=j;
    while(solutions()==2)
    {
        //cout<<"HI";
        j=(rand()%9)+1;
        r=(rand()%9)+1;
        c=(rand()%9)+1;
        arr[r][c]=j;
        if(solutions()==0)
        {
            arr[r][c]=0;
        }
    }
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }

}
