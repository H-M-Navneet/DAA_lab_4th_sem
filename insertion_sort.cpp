#include<iostream>
using namespace std;

void sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key;
        key = a[i];
        int j=i;
        while (j>0 && a[j-1]>key)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=key;
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