#include<iostream>
#include<cstring>
using namespace std;
int strcmp(const char* s1,const char* s2)
{
    if(*s1 == *s2)
        return 1;
    else
        return 0;
}
int main(void)
{
    string s1,s2;
    cout<<"Please tap in"<<endl;
    cin>>s1;
    cout<<"Please tap in"<<endl;
    cin>>s2;
    int num=strcmp(s1.c_str(),s2.c_str());
    cout<<num<<endl;
    system("pause");
}