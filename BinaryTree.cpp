#include<iostream>
using namespace std;
class leaf
{
    public:
    int data;
    leaf *left,*right;
};
class tree
{
    leaf *root,*parent,*curr;
    public:
    tree()
    {
        root=parent=curr=NULL;
    }
    leaf *createleaf(int n)
    {
        leaf *temp=new leaf;
        temp->data=n;
        temp->left=temp->right=NULL;
        return temp;
    }
    void insert()
    {
        leaf *temp;
        curr=root;
        int a;
        cout<<"Enter data"<<endl;
        cin>>a;
        temp=createleaf(a);
        if(root==NULL)
        {
            root=temp;
            cout<<"Root added"<<endl;
        }
        else
        {
            while(curr!=NULL)
            {
                parent=curr;
                if(temp->data > curr->data)
                    curr=curr->right;
                else if(temp->data < curr->data)
                    curr=curr->left;
                    else
                    {
                        cout<<"DUPLICATES NOT ALLOWED"<<endl;
                        return;
                    }
            }
            if(temp->data >parent->data)
            {
                cout<<"Element inserted in right of "<<parent->data<<endl;
                parent->right=temp;
            }
            else
                {
                    cout<<"Element inserted in left of "<<parent->data<<endl;
                    parent->left=temp;
                }
            cout<<"Element added"<<endl;
        }
    }
    void inorder(leaf* &temp)
    {
        if(temp==NULL)
        {
            return;
        }
        inorder(temp->left);
        cout<<temp->data<<"  ";
        inorder(temp->right);
    }
    void preorder(leaf* &temp)
    {
         if(temp==NULL)
        {
            return;
        }
        cout<<temp->data<<"  ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(leaf* &temp)
    {
         if(temp==NULL)
        {
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<"  ";
    }
    void traversal()
    {
        cout<<"Inorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        inorder(root);
        cout<<"\n----------------------------------------------------"<<endl;

        cout<<"Preorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        preorder(root);
        cout<<"\n----------------------------------------------------"<<endl;

        cout<<"Postorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        postorder(root);
        cout<<"\n----------------------------------------------------"<<endl;
    }
    void deleteleaf(leaf* &curr,leaf* &parent)
    {
        if(curr->data < parent->data)
            parent->left=NULL;
        else
            parent->right=NULL;
        cout<<curr->data<<" element deleted"<<endl;
        delete curr;
    }
    void deletehavingone(leaf* &curr,leaf* &parent)
    {
        leaf* child;
        if(curr->left==NULL)
            child=curr->right;
        else
            child=curr->left;
        if(parent->right==curr)
            parent->right=child;
        else
            parent->left=child;
        cout<<curr->data<<" deleted form tree"<<endl;
        delete curr;
    }
    void deletehavingboth(leaf* &curr,leaf* &parent)
    {
        leaf* inos;
        inos=curr->right;
        parent=curr;      //if curr=ROOT & parent=NULL
        while(inos->left!=NULL)
        {
            parent=inos;
            inos=inos->left;
        }

        curr->data=inos->data;
        if(inos->left==NULL  &&  inos->right==NULL)
        {
            deleteleaf(inos,parent);
        }
        else
            deletehavingone(inos,parent);
    }
    void deleteit()
    {
        int num;
        cout<<"Enter element to be deleted"<<endl;
        cin>>num;
        curr=root;
        if(root==NULL)
        {
            cout<<"EMPTY TREE";
        }
        else
        {
            while(curr != NULL && num != curr->data)
            {
                parent = curr;
                if(num < curr->data)
                    curr = curr->left;
                else if(num > curr->data)
                    curr = curr->right;
            }
            if(curr==root && curr->left==NULL && curr->right==NULL)
            {
                root=NULL;
                delete curr;
                cout<<"Root deleted"<<endl;
            }else if(curr==NULL)
            {
                cout<<"Element NOT FOUND"<<endl;
                return;
            }
            else if(curr->left==NULL  &&  curr->right==NULL)
                    deleteleaf(curr,parent);
                else if(curr->left!=NULL  &&  curr->right!=NULL)
                    deletehavingboth(curr,parent);
                    else
                        deletehavingone(curr,parent);
        }
    }
};
main()
{
    tree bt;
    int opn;
    do{
        cout<<"1. Insert\n2. Delete\n3. Display\n0. EXIT"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                bt.insert();
                break;
            case 2:
            	bt.deleteit();
            	break;
            case 3:
                bt.traversal();
                break;
            case 0:
                break;
            default:
                cout<<"INVALID COMMAND"<<endl;
                break;
        }
    }while(opn!=0);
}
