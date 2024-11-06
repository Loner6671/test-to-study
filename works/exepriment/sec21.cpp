#include<iostream>
#include<cmath>
int main(void)
{
    using namespace std;
    double x,y,ans=0;
    cout<<"please tao  in number"<<endl;
    cout<<"x=";
    cin>>x;
    cout<<"y=";
    cin>>y;
    if(x<0 && y<0)
        ans=exp(x+y);
    else if(1<=x+y && x+y<10)
        ans=log(x+y)/exp(1);
    else
        ans=log10(abs(x+y)+1);
    cout<<"z="<<ans<<endl;
    system("pause");
}