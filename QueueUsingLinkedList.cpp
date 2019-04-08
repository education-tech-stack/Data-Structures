#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class queue
{
    public:
    int x;
    node *front,*rear;
    queue()
    {
        front=rear=NULL;
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
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
    void pop()
    {
        node *temp;
        if(front==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            temp=front;
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
                    cout<<temp->data<<"\t";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
};
main()
{
    queue abc;
    int choice;
    do
    {
        cout<<" 1.Push element \t 2.Pop element \t 3.Display \t 4.EXIT"<<endl<<"Enter choice:";
        cin>>choice;
        cout<<endl;
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
    }while(choice!=4);
}
