#include<iostream>
using namespace std;
int main(void)
{
    int line1[]={1,4,9,16,25,36,49,64,81,100};
    int line2[]={1,3,6,10,15,21,28,36,45,55};
    int line3[]={1,2,3,5,8,13,21,34,55,89};
    for(int i=0;i<30;i++)
    {
        if(i<10)
            cout<<line1[i]<<" ";
        else if(i>=10 && i<20)
        {
            if(i==10)
                cout<<"\n";
            cout<<line2[i-10]<<" ";
        }
        else
        {
            if(i==20)
                cout<<"\n";
            cout<<line3[i-20]<<" ";
        }
    }
    cout<<"\n";
    system("pause");
}