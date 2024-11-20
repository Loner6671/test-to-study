#include<iostream>
using namespace std;
int main(void)
{
    int a=10;
    int &b=a;
    cout<<b<<"\n";
    b=20;
    cout<<a<<endl;
}