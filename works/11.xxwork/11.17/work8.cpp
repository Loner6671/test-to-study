#include<iostream>
#include<iomanip>
using namespace std;
class Integer
{
    public:
    virtual int print()=0;
};
class DEC:public Integer
{
    public:
    int number;
    DEC(int num):number(num){}
    int print() override
    {
        cout<<"DEC is "<<number<<endl;
    }
};
class OCT:public Integer
{
    public:
    int number;
    OCT(int num):number(num){}
    int print() override
    {
        cout<<"OCT is "<<oct<<number<<dec<<endl;
    }
};
class HEX:public Integer
{
    public:
    int number;
    HEX(int num):number(num){}
    int print() override
    {
        cout<<"HEX is "<<hex<<number<<dec<<endl;
    }
};
class BIN:public Integer
{
    public:
    int number;
    BIN(int num):number(num){}
    int print() override
    {
        cout << "BIN is ";
        for (int i = 31; i >= 0; --i) 
        {
            cout << ((number>>i)&1);
        }
        cout << endl;
    }
};
int main(void)
{
    int num=0;
    cout<<"Please tap in number:";
    cin>>num;
    Integer* inte[4];
    inte[0]=new DEC(num);
    inte[1]=new OCT(num);
    inte[2]=new HEX(num);
    inte[3]=new BIN(num);
    for(int i=0;i<4;i++)
        inte[i]->print();
    system("pause");
}
