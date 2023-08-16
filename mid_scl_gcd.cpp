#include<iostream>
using namespace std;

void prime(int n,int pf[])
{
    int ind=0;
    while (n%2==0)
    {
        pf[ind++]=2;
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            pf[ind++]=i;
            n/=i;
        }
    }
    if(n>2)
    {
        pf[++ind]=n;
    }
}

int primefactor(int a,int b)
{
    int pf1[100]={0};
    int pf2[100]={0};
    prime(a,pf1);
    prime(b,pf2);
    int i1=0,i2=0;
    int res=1;
    while(pf1[i1]!=0 && pf2[i2]!=0)
    {
        if(pf1[i1]==pf2[i2])
        {
            res*=pf1[i1];
            i1++;
            i2++;
        }
        else if(pf1[i1]<pf2[i2])
        {
            i1++;
        }
        else
        {
            i2++;
        }
    }
    return res;
}

int main()
{
    int a,b;
    cout<<"enter 2 no.s\n";
    cin>>a>>b;
    int ans = primefactor(a,b);
    cout<<"gcd of "<<a<<" and "<<b<<" is "<<ans<<endl;
    return 0;
}