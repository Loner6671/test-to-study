#include<iostream>
using namespace std;
int main(void)
{
    cout<<"Please selsct question:"<<endl;
    int que=0;
    cin>>que;
    switch(que)
    {
    case 3:
        int a,b,c,d=0;
        for(int i=1;i<12;i++)
        {
            for(a=1;a<=2*(11-i);a++)
                cout<<" ";
            for(b=1;b<=2*i-1;b+=2)
                cout<<b<<" ";
            for(d=2*i-3;d>=1;d-=2)
                cout<<d<<" ";
            cout<<"\n";
        }
        break;
    case 4:
        for(int i=1;i<11;i++)
        {       
            for(int j=1;j<11;j++)
                {
                    if(i>j)
                    cout<<"<"<<i<<","<<j<<">"<<endl;
                }
        }
        break;
    case 5:


}