#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    string fis;
    string sec="a";
    cout<<"Please tap in a sentence"<<endl;
    cin>>fis;
    int num=sizeof(fis)/sizeof(sec);
    cout<<sizeof(fis)<<endl<<sizeof(sec)<<endl;
    cout<<"This sentence has "<<num<<" characters"<<endl;
    system("pause");
}