#include<iostream>
#include<string>                //GBK
#include<cmath>
using namespace std;
class Rect
{
    public:
        double squre(double n1,double n2,double n3,double n4)
        {
            ans=abs((n3-n1)*(n4-n2));
            return ans;
        }
        int printsqure(void)
        {
            cout<<thi<<ans<<endl;
        }
    private:
        string thi="矩形的面积是：";
        double ans;
};
int main(void)
{
    Rect squ;
    double num1,num2,num3,num4;
    cout<<"Please tap in first coordinate:";
    cin>>num1>>num2;
    cout<<"Please tap in second coordinate:";
    cin>>num3>>num3;
    squ.squre(num1,num2,num3,num4);
    squ.printsqure();
    system("pause");
}
