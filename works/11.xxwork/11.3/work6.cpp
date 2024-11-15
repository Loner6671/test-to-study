#include<iostream>
using namespace std;
int fun(void);
int main(void)
{
    int m=fun();
    for(int i=0;i<7;i++)
    {
        m=fun();
    }
    system("pause");
}
int fun(void)
{
    static int n=0;
    n++;
    cout<<"n="<<n<<endl;
    return n;
}