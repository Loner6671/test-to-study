#include<iostream>
void simon(int);
int main()
{
    using namespace std;
    simon(3);    //赋予Simon一个值
    cout<<"please tap in a number: ";  
    int cut;
    cin>>cut;
    simon(cut);  //再次赋予Simon一i个值
    cout<<"Done!"<<endl;
    
}
void simon(int n)  //将赋予Simon的值赋予n
{
    using namespace std;
    cout<<"He says "<<n<<" times hello"<<endl;

}