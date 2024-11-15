#include<iostream>
enum Weekday{SUNDAY,MONDAY,TUSEDAY,WENDAY,THURSDAY,FRISDAY,SATURDAY};
int main(void)
{
    using namespace std;
    Weekday today=WENDAY;
    cout<<"Today is "<<today<<endl;
    int data;
    data=WENDAY;
    cout<<"day number is "<<data<<endl;
    system("pause");
}