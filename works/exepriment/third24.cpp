#include<iostream>
using namespace std;
int *sort(int arr[],int num)
{
    for(int n=0;n<num-1;n++)
    {
        for(int m=0;m<num-1-n;m++)
        {
            if(arr[m]>arr[m+1])
            {
                int temp=arr[m];
                arr[m]=arr[m+1];
                arr[m+1]=temp;
            }
        }
    }
    return arr;
}
int find(int *arr,int num,int tar)
{
    int mid=arr[num/2];
    if(tar == mid)
        return num/2;
    else if(tar > mid)
    {
        for(int i=num/2;i<num;i++)
        {
            if(tar==arr[i])
                return i;
        }
    }
    else 
    {
        for(int i=0;i<num/2;i++)
        {
            if(tar==arr[i])
                return i;
        }        
    }
}
int main()
{
    int num,tar;
    cout<<"Please tao in array's size: ";
    cin>>num;
    int arr[num];
    cout<<"Please tap in number"<<endl;
    for(int i=0;i<num;i++)
        cin>>arr[i];
    cout<<"Please tap in target num:"<<endl;
    cin>>tar;
    int *new_arr=sort(arr,num);
    int address=find(new_arr,num,tar);
    cout<<"The address is "<<address<<endl;
    system("pause");
}