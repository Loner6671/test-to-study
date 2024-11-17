#include<iostream>
using namespace std;
class Shape
{
    public:
    virtual double getArea()=0;
};
class Rectangle:public Shape
{
    public:
    double width,height;
    Rectangle(double w,double h):width(w),height(h){}
    double getArea() override
    {
        return width*height;
    }
};
class Circle:public Shape
{
    public:
    double radius;
    Circle(double r):radius(r){}
    double getArea() override
    {
        return 3.14159*radius*radius;
    }
};
int main(void)
{
    int w,h,r;
    cout<<"Please tap in number"<<endl<<"width=";
    cin>>w;
    cout<<"height=";
    cin>>h;
    cout<<"radius=";
    cin>>r;
    Rectangle rect(w,h);
    cout<<"The area of Rectangle is:"<<rect.getArea()<<endl;
    Circle cir(r);
    cout<<"The area of Circle is:"<<cir.getArea()<<endl;
    system("pause");
}