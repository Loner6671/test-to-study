#include<iostream>
#include<cmath>
#include<string>
int main(void)
{
    using namespace std;
    string fis="��ѡ����ʽ";    
    string sec="999.�˳�";
    int choice,mid;
    int a=1;
    int b=2;
    double ans=0;
    FLAG:
    cout<<fis<<"\n1.S=1+2+3��+100\n2.S=1!+2!+3!+...7!\n3.S=1*2+3*4+5*6+...39*40\n4.Y=x-pow(x,3)/3!+pow(x,5)/5!-pow(-1,n+1)*pow(x,2n-1)/(2n=1)!\n"<<sec<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        for(int i=1;i<101;i++)
            ans+=i;
        break;
    case 2:
        for(int i=1;i<8;i++)
        {   for(int n=1;n<=i;n++)
                mid*=n;
            ans+=mid;
            mid=1;}
        break;
    case 3:
        for(int i=1;i<21;i++)
            ans+=a*b;
            a+=2;
            b+=2;
        break;
    case 4:
        double x,n,mi;
        mi=1;
        cout<<"Please tap in number:\n";
        cout<<"x=";
        cin>>x;
        cout<<"n=";
        cin>>n;
        for(int i=1;i<=(n+1)/2;i+=2)
        {    for(int a=1;a<=i;a+=1)
                mi*=a;
            ans+=pow(x,a)/mi*pow(-1,(a-1)/2);
            mi=1;}        
        break;
    case 999:
        return 0;
        break;
    }
    cout<<"answer="<<ans<<endl;
    system("pause");
    goto FLAG; 
}
