#include<iostream>
using namespace std;
int f(int num1);
int main(void)
{
    cout<<"Please tap in number:"<<endl;
    int n;
    cin>>n;
    n = f(n);
    cout<<n<<endl;
    system("pause");
}
int f(int num1)
{
    if(num1==1)
        return 1;
    else
    {
        num1=num1*f(num1-1);
        return num1;
    }
}