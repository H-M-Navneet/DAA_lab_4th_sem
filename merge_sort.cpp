#include<iostream>
using namespace std;

void merge(int a[],int low,int high,int mid)
{
    int i=low;
    int k=0;
    int j=mid+1;
    int temp[high-low+1];
    while(i<=mid && j<=high)
    {
        if (a[i]<a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i] = temp[i-low];
    }
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (high+low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
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
    mergesort(a,0,n-1);
    cout<<"sorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}