#include<iostream>
int main(void)
{
    using namespace std;
    for(int i=1;i<11;i++)
    {   for(int j=1;j<11;j++)
            {if(i>j)
                cout<<"<"<<i<<","<<j<<">"<<endl;}
    }
    system("pause");
}