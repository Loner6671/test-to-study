#include<iostream>
using namespace std;
int main(void)
{
    cout<<"Please tap in 15 number:"<<endl;
    int line[15];
    for(int i=0;i<15;i++)
        cin>>line[i];
    for(int n=0;n<15-1;n++)
    {
        for(int m=0;m<15-1-n;m++)
        {
            if(line[m]>line[m+1])
            {
                int temp=line[m];
                line[m]=line[m+1];
                line[m+1]=temp;
            }
        }
    }
    for(int h=0;h<15;h++)
        cout<<line[h]<<" ";
    system("pause");
}