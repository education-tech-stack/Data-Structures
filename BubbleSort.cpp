#include<iostream>
using namespace std;
void BubbleSort(int [], int );
main()
{
    int n,a[20];
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements   "<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    BubbleSort(a,n);
    cout<<"The sorted array is: "<<endl;
    for(int k=0;k<n;k++)
    cout<<a[k]<<"\t";
}
void BubbleSort(int ar[], int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<(size-1)-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;
            }
        }
    }
}
