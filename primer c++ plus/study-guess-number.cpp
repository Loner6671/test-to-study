#include<iostream>
#include<string>
#include<ctime>
int main(void)
{
    using namespace std;
    srand((unsigned int)time(NULL));
    int fac=rand()%100+1;
    int num,n=0;
    string fis="��ϲ��";
    string sec="С��";
    string thi="����";
    string gg="��������";
    while(num!=fac)
    {
        cin>>num;
        if(num>fac)
            cout<<thi<<endl;
        else if(num<fac)
            cout<<sec<<endl;
        else 
            cout<<fis<<endl;
        n+=1;
        if(n>8)
            {cout<<"fw"<<gg<<endl;
            break;}
    }
system("pause");
}