#include<iostream>
int main(void)
{
    using namespace std;
    int a,b,c,d,e;
    for(int i=1;i<10001;i++)
    {    
        a=i/10000;
        b=(i-10000*a)/1000;
        c=(i-10000*a-1000*b)/100;
        d=(i-10000*a-1000*b-100*c)/10;
        e=i-10000*a-1000*b-100*c-10*d;
        
        if(e>d && d>c && c>b && d>e)
            cout<<i<<endl;
    }
    system("pause");
}