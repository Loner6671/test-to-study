#include<iostream>
int compare(int n[],int tar);
int number(int m[]);
using namespace std;
int main(void)
{
    int num[100];
    int tar;
    cout<<"Please tap in number line:"<<endl;
    for
    cout<<"Please tap in target number:"<<endl;
    cin>>tar;
    compare(num,tar);
    system("pause");
}
int compare(int n[],int tar)
{
    int max=number(n)+1;
    int min=n[0];
    int mid1=(max+1)/2;
    if(tar>n[max-1])
    {
        cout<<"error 404 not found"<<endl;
        return 0;
    }
    else
    {
        while(min<=max)
        {
            if(tar==n[mid1])
                cout<<"The location is:"<<mid1<<endl;
            else if(tar<n[mid1])
                mid1++;
            else
                mid1--;
        }
    }
}
int number(int m[])
{
    int num;
    for(int i=0;i<=100;i++)
    {
        if(m[i] != ' ')
            num=m[i];
    }
    return num;
}