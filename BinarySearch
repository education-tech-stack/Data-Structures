#include<iostream>
using namespace std;
main()
{
    int a[20],n,i,x,mid,last,beg;
    cout<<"Enter no. of elements :"<<endl;
    cin>>n;
    cout<<"Enter the elements :"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to be searched :"<<endl;
    cin>>x;
    last=n-1;
    beg=0;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==x)
        {
            cout<<"Element is at position :"<<mid+1;
            break;
        }
        else
            if(a[mid]>x)
                last=mid-1;
            else
                beg=mid+1;
    }
    if(last<beg)
        cout<<"NOT FOUND!";
}
