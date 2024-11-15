#include<iostream>
int main()
{
    using namespace std;
    int n;
    cout<<"plsease tap in a number" <<endl;
    cout<<"num=" ;
    cin>>n ;
    int a=n/1000;
    int b=(n-a*1000)/100;
    int c=(n-a*1000-b*100)/10;
    int d=n-a*1000-b*100-c*10;
    cout<<d<<c<<b<<a;
}