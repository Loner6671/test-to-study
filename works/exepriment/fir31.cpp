#include<iostream>
using namespace std;
int main(void)
{
    cout<<"Please selsct question:"<<endl;
    int que=0;
    cin>>que;
    int a,b,c,d;
    double r,area,circum ;
    switch(que)
    {
    case 1:
        cout <<"r=";   
        cin >> r;
        area=r*r*3.14;
        circum=2*r*3.14;
        cout<<"area="<<area<<"  circum="<<circum<<endl;
        break;
    case 2:
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
        break;
    case 3:
        int n;
        cout<<"plsease tap in a number" <<endl;
        cout<<"num=" ;
        cin>>n ;
        a=n/1000;
        b=(n-a*1000)/100;
        c=(n-a*1000-b*100)/10;
        d=n-a*1000-b*100-c*10;
        cout<<d<<c<<b<<a;
        break;
    }
    system("pause");
}