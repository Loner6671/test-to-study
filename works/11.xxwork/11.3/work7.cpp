#include<iostream>
using namespace std;
class Car;
int getTotalWeight();
class Boat
{
private:
    int weight;
public:
    void getboat(int n)
    {
        weight=n;
    }
    friend int getTotalWeight(Boat car1,Car boat1);
};
class Car
{
private:
    int weight;
public:
    void getcar(int m)
    {
        weight=m;
    } 

    friend int getTotalWeight(Boat car1,Car boat1);
};
int getTotalWeight(Boat car1,Car boat1)
{
    return boat1.weight+car1.weight;
}
int main(void)
{
    Boat boat1;
    Car car1;
    boat1.getboat(5000);
    car1.getcar(1500);
    int m=getTotalWeight(boat1,car1);
    cout<<m<<endl;
    system("pause");
}

