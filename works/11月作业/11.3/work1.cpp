#include<iostream>
#include<string>         //GBK
using namespace std;
int fac(int n,int m);
int main(void)
{
    int num1=0,num2=0;
    string fis="最大公约数为";
    string sec="最小公倍数为";
    cout<<"Please tap in two numbers:"<<endl;
    cout<<"fis.number=";
    cin>>num1;
    cout<<"sec.number=";
    cin>>num2;
    int max_yin=fac(num1,num2);
    int min_gong=num1*num2/max_yin;
    cout<<fis<<max_yin<<endl<<sec<<min_gong<<endl;
    system("pause");
}
int fac(int n,int m)
{
    int num;
    if(n<m)
    {
        while(m%n !=0)
        {
            num= m % n;
            m=n;
            n=num;
        }
    }
    return n;
} 