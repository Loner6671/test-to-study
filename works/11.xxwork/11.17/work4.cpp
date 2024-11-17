#include<iostream>
using namespace std;
int tsqu[3][3];
int sq[3][3];
int squ_t(int squ[3][3])
{
    int m,n;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i<j)
            {
                m=squ[i][j];
                n=squ[j][i];
                squ[i][j]=n;
                squ[j][i]=m;
            }
        }
    }
    return squ[3][3];
}
int main(void)
{
    cout<<"Please tap in number:"<<endl;
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            cin>>sq[x][y];
        }
    }
    tsqu[3][3]=squ_t(sq);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<sq[i][j]<<"  ";
        }
        cout<<"\n";
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<tsqu[i][j]<<"  ";
        }
        cout<<"\n";
    }
    system("pause");
}
