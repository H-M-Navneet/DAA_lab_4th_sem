#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }
    return a;
}

int main()
{
    int a,b;
    cout<<"enter 2 no.s\n";
    cin>>a>>b;
    int ans = gcd(a,b);
    cout<<"gcd of "<<a<<" and "<<b<<" is "<<ans<<endl;
    return 0;
}