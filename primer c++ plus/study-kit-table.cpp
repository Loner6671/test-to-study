#include<iostream>
#include<string>
int main(void)
{
    using namespace std;
    string fis="ÇÃ×À×Ó";
    for(int i=1;i<101;i++)
    {   if(i%7==0 || i%10==7 || i-(i%10)*10==7)
            cout<<fis<<endl;
        else 
            cout<<i<<endl;
    }
    system("pause");
}