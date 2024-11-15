#include<iostream>
#include<cstring>
using namespace std;
int min(int n,int m)
{
    if(n<m)
        return n;
    else
        return m;
}
int max(int n,int m)
{
    if(n>m)
        return n;
    else
        return m;
}
int main(void)
{
    string fis=" °°µãÊÇ£º";
    int line=0,column=0;
    cout<<"Please tap in array's line and it's column:"<<endl;
    cin>>line;
    cin>>column;
    cout<<"please tap in number:"<<endl;
    int tline[column][line];
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<line;j++)
        {
            cin>>tline[i][j];
        }
    }
    int h=0,n,x=0,y=0,z,num1=0,num2=0;
    for(int m=0;m<column;m++)
    {
        n=tline[m][0];
        do
        {
            x=n;
            n=max(n,tline[m][h]);
            if(n!=x)
                num1++;
            h++; 
        }
        while(h<=line);
        h=0;
        x=y=tline[0][num1];
        do
        {
            x=y;
            y=min(x,tline[h][num1]);
            h++;
        }
        while (h<=column);
        if(x==n)
            cout<<fis<<"["<<m<<"]"<<"["<<num1<<"]"<<endl;
        num1=0;
        h=0;
    }
    system("pause");
}