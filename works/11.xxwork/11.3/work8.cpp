#include<iostream>
using namespace std;
int main(void)
{
    cout<<"Please tap in 10 number:"<<endl;
    int line[10];
    for(int i=0;i<10;i++)
        cin>>line[i];
    for(int n=0;n<10-1;n++)
    {
        for(int m=0;m<10-1-n;m++)
        {
            if(line[m]>line[m+1])
            {
                int temp=line[m];
                line[m]=line[m+1];
                line[m+1]=temp;
            }
        }
    }
    for(int h=0;h<10;h++)
        cout<<line[h]<<" ";
    system("pause");
}