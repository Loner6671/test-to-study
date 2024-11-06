#include<iostream>
using namespace std;
void sushu(int num)
{
    for (int i = 2; i <= num; i++) 
    {
        while (num % i == 0) 
        {
            cout << i << "*";
            num /= i;
        }
    }
}
int main(void)
{
    cout<<"Please selsct question:"<<endl;
    int que=0;
    int a,b,c,d,e=0;
    cin>>que;
    switch(que)
    {
    case 3:
        for(int i=1;i<12;i++)
        {
            for(a=1;a<=2*(11-i);a++)
                cout<<" ";
            for(b=1;b<=2*i-1;b+=2)
                cout<<b<<" ";
            for(d=2*i-3;d>=1;d-=2)
                cout<<d<<" ";
            cout<<"\n";
        }
        break;
    case 4:
        for(int i=1;i<11;i++)
        {       
            for(int j=1;j<11;j++)
                {
                    if(i>j)
                    cout<<"<"<<i<<","<<j<<">"<<endl;
                }
        }
        break;
    case 5:  
        for(int i=1;i<10001;i++)
        {    
            a=i/10000;
            b=(i-10000*a)/1000;
            c=(i-10000*a-1000*b)/100;
            d=(i-10000*a-1000*b-100*c)/10;
            e=i-10000*a-1000*b-100*c-10*d;
            if(a==0)
                a=-5;
            if(b==0)
                b=-4;
            if(c==0)
                c=-3;
            if(d==0)
                d=-2;
            if(e==0)
                d=-1;
            if(e>d && d>c && c>b && b>a)
                cout<<i<<endl;
        }
        break;
    case 6:
        int number;
        cout << "Please tap in a number:";
        cin >> number;
        cout << "Result is:";
        sushu(number);
        break;
    }
    system("pause");
}
