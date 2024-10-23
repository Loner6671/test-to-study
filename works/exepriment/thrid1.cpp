#include<iostream>
#include<cmath>
#include<string>
int main(void)
{
    using namespace std;
    double x,a,b,c,d,y=0;
    int choice;
    double ans;
    string fis="«Î—°‘ÒÀ„ Ω";    
    string sec="999.ÕÀ≥ˆ";
    FLAG5:
    cout<<fis<<"\n1.x+(a+b)/(c-d)\n2.°Ã(1+1/(x+1/(1+x)))\n3.sinX+cosX+tan-1X\n4.e(x+y)+e(x-y)\n5.log10(1+°Ã(1+x*x))\n6.|a*a+b*b|+[a-b]\n"<<sec<<endl;
    cin>>choice;
    switch(choice)
    { 
    case 1:    
        goto FLAG1;   //36 line
        break;
    case 2:
        goto FLAG2;   //50 line
        break;
    case 3:
        goto FLAG2;
        break;
    case 4:
        goto FLAG3;   //68 line
        break;
    case 5:
        goto FLAG2;
        break;
    case 6:
        goto FLAG4;   //78 line
        break;
    case 999:
        return 0;
        break;
    }   
    FLAG1 :
    cout<<"please tap in number:"<<endl;
    cout<<"  a=";
    cin>>a;
    cout<<"  b=";
    cin>>b;
    cout<<"  c=";
    cin>>c;
    cout<<"  d=";
    cin>>d;
    cout<<"  x=";
    cin>>x;
    ans=x+(a+b)/(c-d);
    cout<<"answer="<<ans<<endl;
    system("pause");
    goto FLAG5;
    FLAG2 :
    cout<<"please tap in number:"<<endl;
    cout<<"  x=";
    cin>>x;
    switch (choice)
    {
    case 2:
        ans=sqrt(1+1/(x+1/(x+1)));
        break;
    case 3:
        ans=sin(x)+cos(x)+atan(x);
        break;
    case 5:
        ans=log10(1+sqrt(1+x*x));
        break;
    }
    cout<<"answer="<<ans<<endl;
    system("pause");
    goto FLAG5;
    FLAG3 :
    cout<<"please tap in number:"<<endl;
    cout<<"  x=";
    cin>>x;
    cout<<"  y=";
    cin>>y;
    ans=exp(x+y)+exp(x-y);
    cout<<"answer="<<ans<<endl;
    system("pause");
    goto FLAG5;
    FLAG4 :
    cout<<"please tap in number:"<<endl;
    cout<<"  a=";
    cin>>a;
    cout<<"  b=";
    cin>>b;
    ans=abs(a*a-b*b)+floor(a-b);
    cout<<"answer="<<ans<<endl;
    system("pause");
    goto FLAG5;
}

