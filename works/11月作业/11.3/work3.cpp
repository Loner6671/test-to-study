#include<iostream>
#include<cmath>
using namespace std;
void les(double num1,double num2,double num3);
void greate(double num1,double num2,double num3);
void equal(double num1,double num2,double num3);
int main(void)
{
    double a,b,c,ans;
    cout<<"Please tap in number:"<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    if((b*b-4*a*c)>0)
        greate(a,b,c);
    else if((b*b-4*a*c)<0)
        les(a,b,c);
    else
        equal(a,b,c);
    system("pause");
}
void greate(double num1,double num2,double num3)
{
    double ans1=(-num2-pow(num2*num2-4*num1*num3,0.5))/2*num1;
    double ans2=(-num2+pow(num2*num2-4*num1*num3,0.5))/2*num1;
    cout<<"answer1="<<ans1<<endl;
    cout<<"answer2="<<ans2<<endl;
}
void les(double num1,double num2,double num3)
{
    double ans_one = -num2/2*num1;
    double ans_two = pow(-(num2*num2-4*num1*num3),0.5)/2*num1;
    cout<<"answer1="<<ans_one<<"+"<<ans_two<<"i"<<endl;
    cout<<"answer2="<<ans_one<<"-"<<ans_two<<"i"<<endl;
}
void equal(double num1,double num2,double num3)
{
    double ans=-num2/2*num1;
    cout<<"answwer="<<ans<<endl;
}