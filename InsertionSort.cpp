#include<iostream>
using namespace std;
void Insertion(int [], int );
main()
{
    int n,a[20];
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements   "<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    Insertion(a,n);
    cout<<"The sorted array is: "<<endl;
    for(int k=0;k<n;k++)
    cout<<a[k]<<"\t";
}
void Insertion(int ar[], int size)
{
    int i,j;
    for(i=1;i<=size-1;i++)
    {
        int temp=ar[i];
        j=i-1;
        while((temp<=ar[j])&&(j>=0))
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
}
