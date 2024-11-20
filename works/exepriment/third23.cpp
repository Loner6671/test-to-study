#include<iostream>
using namespace std;
int factor(int m,int n)
{
    if(n == 0)
        return m;
    else
        return factor(n,m%n);
}
int main(void)
{
    int num1,num2,fac;
    cout<<"Please tap in number:"<<endl;
    cin>>num1;
    cin>>num2;
    if(num1>num2)
        fac=factor(num1,num2);
    else
        fac=factor(num2,num1);
    int mul=fac*(num1/fac)*(num2/fac);
    cout<<"The max factor is "<<fac<<endl<<"The min multiple is "<<mul<<endl;
    system("pause");
}