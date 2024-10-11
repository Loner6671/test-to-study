#include<iostream>
#include<string>
int main(void)
{
    using namespace std;
    string fis ="”≈";
    string sec ="¡º";
    string thi ="÷–";
    string fou ="≤Ó";
    int d=0;
    cout<<"Please tap in your point:";
    cin>>d;
    if(d>=90 && d<=100)
        cout<<fis;
    else if(d>=80 && d<90)
        cout<<sec;
    else if(d>=60 && d<80)
        cout<<thi;
    else 
        cout<<fou;
    cout<<"\n";
    system("pause");
}