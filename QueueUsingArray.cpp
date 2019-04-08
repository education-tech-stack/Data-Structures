#include<iostream>
using namespace std;
class queue
{
public:
    int data[100],top;
    queue()
    {
        top=-1;
    }
    int isempty()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
            return 1;
        }
        else
            return 0;
    }
    int isfull()
    {
        if(top==99)
        {
            cout<<"Stack full"<<endl;
            return 1;
        }
        else
            return 0;
    }
    void push()
    {
        if(isfull())
        {
            return ;
        }
        else
        {
            top++;
            cout<<"Enter element "<<endl;
            cin>>data[top];
        }
    }
    void pop()
    {
        if(isempty())
        {
            return ;
        }
        else
        {
                int i;
                for( i=0;i<top;i++)
                {
                    data[i]=data[i+1];
                }
                top--;
                cout<<"Element poped"<<endl;
        }
    }
    void display()
    {
        if(isempty())
        {
            return ;
        }
        else
        {
            for(int i=top;i>=0;i--)
            cout<<data[i]<<"\t";
            cout<<endl;
        }
    }
};
main()
{
    queue sua;
    int opn;
    do{
        cout<<"1 => Push\t2 => Pop\t3 => Display\t 4.EXIT"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                sua.push();
                break;
            case 2:
                sua.pop();
                break;
            case 3:
                sua.display();
                break;
            default:
                cout<<"An invalid choice!"<<endl;
            case 4:
                break;
        }
    }while(opn!=4);
}
