#include<iostream>
using namespace std;

int partition(int a[],int low,int high,int pivot)
{
    int i=low;
    int j=low;
    while(i<=high)
    {
        if(a[i]>pivot)
        {
            i++;
        }
        else
        {
            swap(a[i],a[j]);
            i++;
            j++;
        }
    }
    return j-1;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot = a[high];
        int pos = partition(a,low,high,pivot);
        quicksort(a,low,pos-1);
        quicksort(a,pos+1,high);
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
    quicksort(a,0,n-1);
    cout<<"sorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}