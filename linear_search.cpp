#include<iostream>
#include<time.h>
using namespace std;

void search(int a[],int n,int key)
{
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
            flag = 1;
        }
    }
    if(flag==1)
    {
        cout<<"element found"<<endl;
    }
    else
    {
        cout<<"element not found \n";
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
    search(a,n,key);
    clock_t stop = clock();
    float time = (float)(stop - start)/CLOCKS_PER_SEC;
    cout<<"Time : "<<time<<endl;
}