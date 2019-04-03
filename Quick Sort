#include<iostream>
using namespace std;
void quicksort(int [],int,int);
int partition(int [],int,int);
main()
{
    int n,a[20];
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements   "<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,0,n-1);
    cout<<"The sorted array is: "<<endl;
    for(int k=0;k<n;k++)
    cout<<a[k]<<"\t";
}
void quicksort(int ar[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(ar,l,u);
        quicksort(ar,l,j-1);
        quicksort(ar,j+1,u);
    }
}
int partition(int ar[],int l,int u)
{
    int temp,v,i,j;
    v=ar[l];
    i=l;
    j=u+1;
    do
    {
        do {i++;} while((ar[i]<v) && (i<=u));
        do {j--;} while(v<ar[j]);
        if(i<j)
        {
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
        }
    }while(i<j);
    ar[l]=ar[j];
    ar[j]=v;
    return (j);
}
