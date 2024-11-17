#include <iostream>
using namespace std;
class Mam 
{
public:
    Mam() 
    {
        cout << "Mam yes dog" << endl;
    }
    ~Mam() 
    {
        cout << "Mam no cat" << endl;
    }

};
class Dog : public Mam 
{
public:
    Dog() 
    {
        cout << "Dog wolf" << endl;
    }
    ~Dog() 
    {
        cout << "Dog cat" << endl;
    }
};
int main()
{  
    Dog myDog; 
    system("pause");
}