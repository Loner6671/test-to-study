#include<iostream>
int main(void)
{
    using namespace std;
    int a,b,c,d,e=0;
    for(int i=1;i<10001;i++)
    {    
        a=i/10000;
        b=(i-10000*a)/1000;
        c=(i-10000*a-1000*b)/100;
        d=(i-10000*a-1000*b-100*c)/10;
        e=i-10000*a-1000*b-100*c-10*d;
        if(a==0)
            a=-5;
        if(b==0)
            b=-4;
        if(c==0)
            c=-3;
        if(d==0)
            d=-2;
        if(e==0)
            d=-1;
        if(e>d && d>c && c>b && b>a)
            cout<<i<<endl;
    }
    system("pause");
}