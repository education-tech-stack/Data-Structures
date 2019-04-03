#include<iostream>
using namespace std;
main()
{
    int i,n,a[20],x;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements   "<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter element to be searched :"<<endl;
    cin>>x;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            cout<<"Element found at location "<<i;
            break;
        }

    }
    if(i==n)
        cout<<"NOT FOUND!";
}
