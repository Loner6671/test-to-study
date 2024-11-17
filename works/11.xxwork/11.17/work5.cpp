#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* creatlist()
{
    node* fis=new node;
    fis->next=NULL;
    node* end=fis;
    int data;
    cout<<"Please tap in number:"<<endl<<"-1 is end"<<endl;
    cin>>data;
    while(data != -1)
    {
        node* newnode=new node;
        newnode->data=data;
        newnode->next=NULL;
        end->next=newnode;
        end=newnode;
        cout<<"Please tap in next number: ";
        cin>>data;
    }
    return fis;
}
void print(node* fis)
{
    node* num=fis;
    while(num != NULL)
    {
        cout<<num->data<<" ";
        num =num->next;
    }
}
int main(void)
{
    node* fis=creatlist();
    print(fis);
    system("pause");
}