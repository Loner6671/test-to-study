#include<iostream>
int main()
{
    using namespace std;
    int a,b,c,x,y,z,max,mild,min;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    if(a>b)
       { x=a;
         y=b;}
    else 
        {x=b;
        y=a;}
    if(x>c)
        {max=x;
        if(c>y)
            {mild=c;
            min=y;}
        else
            {mild=y;
            min=c;}}
    else
        {max=c;
        mild=x;
        min=y;}
    cout<<"max="<<max<<"  mild="<<mild<<"  min="<<min ;
}