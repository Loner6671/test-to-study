#include<iostream>
#include<cmath>
#include<string>
int main(void)
{
    using namespace std;
    string fis="?1?7?1?7?0?5?1?7?1?7?1?7?1?7?0?4";    
    string sec="5.?1?7?0?3?1?7";
    int choice,mid,n,a=1,b=2,sign=1;
    double ans=0,term=0.0,x=0;
    FLAG:
    cout<<fis<<"\n1.S=1+2+3?1?7?1?7+100\n2.S=1!+2!+3!+...7!\n3.S=1*2+3*4+5*6+...39*40\n4.Y=x-pow(x,3)/3!+pow(x,5)/5!-pow(-1,n+1)*pow(x,2n-1)/(2n=1)!\n"<<sec<<endl;
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
        cout << "TAP IN NUMBER:\n";
        cout << "x=";
        cin >> x;
        cout << "n="; 
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int exp = 2 * i + 1; 
            double mid = 1.0;
            for (int j = 1; j <= exp; j++) 
            {
                mid*= j;
            }
        term = pow(x, exp)/mid; 
        ans += sign * term;
        sign*= -1;
        }
        break;
    case 5:
        return 0;
        break;
    }
    cout<<"answer="<<ans<<endl;
    ans=0; 
    system("pause");
    goto FLAG; 
}
