#include <iostream>
using namespace std;
int arr[10][10];

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

bool findsoln(int r,int c)
{
    if(arr[r][c]==0)//If that position is blank in the puzzle
    {
        for(int i=1; i<=9; i++)
        {
            if(Hor(r,c,i) && Vert(r,c,i) && Box(r,c,i))//If there is no instance of number i in that row, column or box
            {
                arr[r][c]=i;//Temporarily assign i, for now, there is no loophole in the solution
                if(r==9 && c==9)//If the last cell has been assigned a number, it means the puzzle has a solution
                {
                    return true;
                }
                else if(findsoln(nextcell_row(r,c),nextcell_column(r,c)))//If assigning i leads to a solution for the puzzle, return true i.e. there is a solution
                {
                    return true;
                }
                else//If assigning i doesn't lead to a solution, then remove that temporarily assigned value
                {
                    arr[r][c]=0;
                }
            }
        }
        if(arr[r][c]==0)//At this point, all the values from 1-9 for that particular cell would be exhausted, and none of them would have led to a solution, so return false to the previous cell
        {
            return false;
        }
    }
    else if(r==9 && c==9)//If the last cell has been reached, and it already has an assigned value, that is still a solution for the puzzle, so return true
    {
        return true;
    }
    else if(findsoln(nextcell_row(r,c),nextcell_column(r,c)))//If cell has already been assigned a value in the puzzle,  check if it subsequently leads to a solution, findsoln for next cell
    {
        return true;
    }
    else//If the cell has already been assigned a value in the puzzle, and it does not lead to a solution, return false
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
    findsoln(1,1);//Calls cell (1,1)
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
//findsoln(1,1) will return true when there is a solution, For it to do so, findsoln(1,2) needs to return true to findsoln(1,1), findsoln(1,3) needs to return true to findsoln(1,2) and so on until findsoln(9,9) returns true to findsoln(9,8)
//If say, for a particular coordinate (r,c), none of the values 1-9 leads to a solution, then definitely there is a flaw with the values in the previous cells, so it returns false to the previous cell
