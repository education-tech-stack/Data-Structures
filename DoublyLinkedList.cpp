#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next,*prev;
};
class operations
{
    public:
    node *start,*last;
    int x;
    operations()
    {
        start=last=NULL;
    }
    node *newnode(int n)
    {
        node *temp=new node;
        temp->data=n;
        temp->next=temp->prev=NULL;
        return temp;
    }
    void insertfront()
    {
        node *temp;
        cout<<"Enter a element"<<endl;
        cin>>x;
        temp=newnode(x);
        if(start==NULL)
        {
            start=last=temp;
            cout<<"First node Created"<<endl;
        }
        else
        {
            start->prev=temp;
            temp->next=start;
            start=temp;
            cout<<"Element inserted"<<endl;
        }
    }
    void insertmid()
    {
        node *temp,*curr,*back;
        curr=start;
        back=NULL;
        cout<<"Enter a element"<<endl;
        cin>>x;
        temp=newnode(x);
        if(start==NULL)
        {
            start=last=temp;
            cout<<"First node Created"<<endl;
        }
        else
        {
            while( x > curr->data && curr->next!=NULL)
            {
                back=curr;
                curr=curr->next;
            }
            if(curr->next==NULL)  //if it reaches the last element
            {
                curr->next=temp;
                temp->prev=curr;
                last=temp;
            }
            else
                if(back==NULL)  //if loop stops at first element
            {
                curr->prev=temp;
                temp->next=curr;
                start=temp;
            }
            else
            {
                back->next=temp;
                temp->prev=back;
                temp->next=curr;
                curr->prev=temp;
            }
            cout<<"Node inserted at correct position."<<endl;
        }
    }
    void insertlast()
    {
        node *temp;
        cout<<"Enter a element"<<endl;
        cin>>x;
        temp=newnode(x);
        if(start==NULL)
        {
            start=last=temp;
            cout<<"First node Created"<<endl;
        }
        else
        {
            last->next=temp;
            temp->prev=last;
            last=temp;
            cout<<"Element inserted at last."<<endl;
        }
    }
    void deletefront()
    {
        node *temp;
        temp=start;
        if(start==NULL)
        {
            cout<<"The list is empty";
        }
        else
        {
            start=start->next;
            start->prev=NULL;
            delete temp;
            cout<<"First element deleted"<<endl;
        }
    }
    void deletemid()
    {
        node *temp,*curr,*back;
        curr=start;
        back=NULL;
        cout<<"Enter element to be deleted"<<endl;
        cin>>x;
        if(start==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            while( x != curr->data && curr!=NULL)
            {
                back=curr;
                curr=curr->next;
            }
            if(curr==NULL)
            {
                cout<<"Element not found"<<endl;
            }
            else
                if(back==NULL)
            {
                temp=start;
                start=start->next;
                start->prev=NULL;
                delete temp;
            }
            else
            {
                temp=curr;
                curr=curr->next;
                curr->prev=back;
                back->next=curr;
                delete temp;
            }
            cout<<"Node deleted"<<endl;
        }
    }
    void deletelast()
    {
        node *temp;
        if(start==NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            temp=last;
            last=last->prev;
            last->next=NULL;
            delete temp;
            cout<<"Node deleted from last"<<endl;
        }
    }
    void displayasc()
    {
        node *curr,*back;
        curr=start;
        back=NULL;
        if(start==NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            while(curr!=NULL)
            {
                back=curr;
                cout<<curr->data<<"\t";
                curr=curr->next;
            }
            cout<<endl;
        }
    }
    void displaydsc()
    {
        node *curr,*back;
        curr=last;
        back=NULL;
        if(start==NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            while(curr!=NULL)
            {
                back=curr;
                cout<<curr->data<<"\t";
                curr=curr->prev;
            }
            cout<<endl;
        }
    }
};
main()
{
    operations opo;
    int choice;
    do
    {
        cout<<"1.Insert front\t 2. Insert middle\t 3. Insert last\n4. Delete front\t 5. Delete middle\t 6. Delete last\n7. Display\t 0. END"<<endl;
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Insert data at begining\n";
            opo.insertfront();
            break;
        case 2:
            cout<<"Insert data at middle\n";
            opo.insertmid();
            break;
        case 3:
            cout<<"Insert data at last\n";
            opo.insertlast();
            break;
        case 4:
            cout<<"Delete data from begining\n";
            opo.deletefront();
            break;
        case 5:
            cout<<"Delete data from middle\n";
            opo.deletemid();
            break;
        case 6:
            cout<<"Delete data from last\n";
            opo.deletelast();
            break;
        case 0:
            break;
        case 7:
            cout<<"Ascending list"<<endl;
            opo.displayasc();
            cout<<"Descending list"<<endl;
            opo.displaydsc();
            break;
        default:
            cout<<"INVALID COMMAND\n";
        }
    }while(choice!=0);
}
