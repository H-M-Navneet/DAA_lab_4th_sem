#include<iostream>
#include<time.h>
using namespace std;

void search(int a[],int low,int high,int key)
{
    if(low>high)
    {
        cout<<"invalid array\n";
    }
    else
    {
        int mid;
        mid = (high+low)/2;
        if(a[mid]==key)
        {
            cout<<"element found at position "<<mid<<endl;
        }
        else if(a[mid]<key)
        {
            search(a,mid+1,high,key);
        }
        else if(a[mid]>key)
        {
            search(a,low,mid-1,key);
        }
    }
}

int main()
{
    int n;
    cout<<"enter no.of elements\n";
    cin>>n;
    int a[n];
    cout<<"enter elements of array in ascending order\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"enter element to be searched\n";
    cin>>key;
    clock_t start = clock();
    search(a,0,n-1,key);
    clock_t stop = clock();
    float time = (float)(stop - start)/CLOCKS_PER_SEC;
    cout<<"Time : "<<time<<endl;
}