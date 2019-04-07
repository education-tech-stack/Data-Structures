#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class stack
{
    public:
    int x;
    node *front;
    stack()
    {
        front=NULL;
    }
    node *newnode(int n)
    {
        node *temp=new node;
        temp->data=n;
        temp->next=NULL;
        return temp;
    }
    void push()
    {
        node *temp;
        cout<<"Enter data to push"<<endl;
        cin>>x;
        temp=newnode(x);
        if(front==NULL)
        {
            cout<<"First element pushed"<<endl;
            front=temp;
        }
        else
        {
            temp->next=front;
            front=temp;
            cout<<"Element pushed"<<endl;
        }
    }
    void pop()
    {
        node *temp=front;
        if(front==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            front=front->next;
            delete temp;
            cout<<"Element poped"<<endl;
        }
    }
        void display()
        {
            node *temp;
            temp=front;
            if(front==NULL)
            {
                cout<<"Stack is empty"<<endl;
            }
            else
            {
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t"<<endl;
                    temp=temp->next;
                }
            }
        }
};
main()
{
    stack abc;
    int choice;
    do
    {
        cout<<" 1.Push element \t 2.Pop element \t 3.Display \t 4.EXIT\nEnter choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            abc.push();
            break;
        case 2:
            abc.pop();
            break;
        case 3:
            abc.display();
            break;
        default:
            cout<<"INVALID COMMAND"<<endl;
            break;
        case 4:
            break;
        }
    }while(choice!=0);
}
