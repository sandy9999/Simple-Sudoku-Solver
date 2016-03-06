#include <iostream>
using namespace std;
int arr[10][10];

int Hor(int r,int c,int i)
{
    for(int j=1; j<=9; j++)
        if(j!=c)
            if(arr[r][j]==i)
                return false;
    return true;
}

int Vert(int r,int c,int i)
{
    for(int j=1; j<=9; j++)
        if(j!=r)
            if(arr[j][c]==i)
                return false;
    return true;
}

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
}
int nextcell_row(int r,int c)
{
    if(c==9)
        return r+1;
    else
        return r;
}

int nextcell_column(int r,int c)
{
    if(c==9)
        return 1;
    else
        return c+1;
}

bool findsoln(int r,int c)
{
    if(arr[r][c]==0)
    {
        for(int i=1; i<=9; i++)
        {
            if(Hor(r,c,i) && Vert(r,c,i) && Box(r,c,i))
            {
                arr[r][c]=i;
                if(r==9 && c==9)
                {
                    return true;
                }
                else if(findsoln(nextcell_row(r,c),nextcell_column(r,c)))
                {
                    return true;
                }
                else
                {
                    arr[r][c]=0;
                }
            }
        }
        if(arr[r][c]==0)
        {
            return false;
        }
    }
    else if(r==9 && c==9)
    {
        return true;
    }
    else if(findsoln(nextcell_row(r,c),nextcell_column(r,c)))//Cell has already been assigned a value in the puzzle
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout<<"Enter the puzzle\n";
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            cin>>arr[i][j];
        }
    }
    findsoln(1,1);
    cout<<'\n';
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
