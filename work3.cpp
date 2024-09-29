#include<iostream>
int main()
{
    using namespace std;
    int a,b,c,d;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    d=a;
    a=b;
    b=c;
    c=d;
    
    cout<<"a="<<a<<"  b="<<b<<"  c="<<c<<endl;
    
}