#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
    char fis[100];
    char sec[]={"a"};
    int num;
    cout<<"Please tap in a sentence"<<endl;
    cin.getline(fis,100);
    for(int i=0;i<=100;i++)
    {
        if(fis[i]>='a' && fis[i]<='z' || fis[i]>='A' && fis[i]<='Z')
            num++;
    } 
    cout<<"This sentence has "<<num<<" characters"<<endl;
    system("pause");
}