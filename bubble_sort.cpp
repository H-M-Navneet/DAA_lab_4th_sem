#include<iostream>
using namespace std;

void sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cout<<"enter no.of elements\n";
    cin>>n;
    int a[n];
    cout<<"enter elements of array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,n);
    cout<<"sorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}