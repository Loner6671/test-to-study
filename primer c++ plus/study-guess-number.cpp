#include<iostream>
#include<string>
#include<ctime>
int main(void)
{
    using namespace std;
    srand((unsigned int)time(NULL));
    int fac=rand()%100+1;
    int num=0;
    string fis="恭喜你";
    string sec="小了";
    string thi="大了";
    while(num!=fac)
    {
        cin>>num;
        if(num>fac)
            cout<<thi<<endl;
        else if(num<fac)
            cout<<sec<<endl;
        else 
            cout<<fis<<endl;
    }
system("pause");
}