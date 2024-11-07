#include<iostream>
int compare(int tar,int num,int n[]);
using namespace std;
int main(void)
{
    int tar,n;
    cout<<"Please tap in number's number:"<<endl;
    cin>>n;
    int num[n-1];
    cout<<"Please tap in number line:"<<endl;
    for(int i=0;i<n;i++)
        cin>>num[i];
    cout<<"Please tap in target number:"<<endl;
    cin>>tar;
    compare(tar,n,num);
    system("pause");
}
int compare(int tar,int num,int n[])
{
    int max=n[num-1];
    int min=n[0];
    int mid1=(max+1)/2;
    if(tar>n[num-1] || tar<n[0])
    {
        cout<<"error 404 not found"<<endl;
        return 0;
    }
    else
    {
        while(min<=max)
        {
            if(tar==n[mid1])
                {cout<<"The location is:"<<mid1<<endl;
                return 0;}
            else if(tar<n[mid1])
                mid1++;
            else
                mid1--;
        }
    }
}