#include<iostream>
using namespace std;

int array[10][10],completed[10],n,cost=0;

void input()
{
    int i,j;

    cout<<"Enter the number of cities: ";
    cin>>n;

    cout<<"\nEnter the Cost Matrix\n";

    for(i=0; i < n; i++)
    {
        cout<<"\nEnter elements of row: "<<i+1<<"\n";

        for( j=0; j < n; j++)
            cin>>array[i][j];

        completed[i]=0;
    }

    cout<<"The cost list is:\n";

    for( i=0; i < n; i++)
    {
        cout<<"\n";

        for(j=0; j < n; j++)
            cout<<"\t"<<array[i][j];
    }
}

int least(int c)
{
    int i,nc=1111;
    int min=1111,kmin;

    for(i=0; i < n; i++)
    {
        if((array[c][i]!=0)&&(completed[i]==0))
            if(array[c][i]+array[i][c] < min)
            {
                min=array[i][0]+array[c][i];
                kmin=array[c][i];
                nc=i;
            }
    }

    if(min!=1111)
        cost+=kmin;

    return nc;
}

void minimum_cost(int city)
{
    int i,ncity;

    completed[city]=1;

    cout<<city+1<<"--->";
    ncity=least(city);

    if(ncity==1111)
    {
        ncity=0;

        cost+=array[city][ncity];

        return;
    }

    minimum_cost(ncity);
}

int main()
{
    input();

    cout<<"\n\nThe Path is:\n\n";
    minimum_cost(0);

    cout<<"\n\nMinimum cost is "<<cost;

    return 0;
}
