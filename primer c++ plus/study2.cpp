#include<iostream>
#include<cstring>
int main(void)
{
    using namespace std;
    int i=25;
    char name[i];
    cout<<"Tell me yuor name"<<endl;
    cin>>name;
    cout<<"Well your name have "<<sizeof(name)<<"bytes\n";

}
