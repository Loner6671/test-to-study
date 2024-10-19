#include<iostream>
int main(void)
{
    using namespace std;
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
    system("pause");
}