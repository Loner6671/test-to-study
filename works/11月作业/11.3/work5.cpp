#include<iostream>
using namespace std;
class Tree
{
public:
    double age;
    double high;
    double number(double n,double m)
    {
        age=n;
        high=m;
    }
    double show()
    {
        cout<<"The tree's height is "<<high<<endl;
    }
};
int main(void)
{
    Tree tree1;
    tree1.high=10;
    tree1.show();
    system("pause");
}

