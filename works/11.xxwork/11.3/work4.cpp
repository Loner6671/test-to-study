#include<iostream>
using namespace std;
int Fibonacci(int n);
int main(void)
{
    int n;
    cout<<"Please tao in a number:";
    cin>>n;
    int ans=Fibonacci(n);
    cout<<"answer is "<<ans<<endl;
    system("pause");
}
int Fibonacci(int n)
{
    int zancun;
    if(n<=1)
        return n;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}