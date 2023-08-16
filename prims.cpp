#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct comparator{
    bool operator()(vector<int>&lhs,vector<int>&rhs){
        return lhs>rhs;
    }
};
vector<vector<int>>graph;
int v,e;
void prims()
{
    priority_queue <vector<int>,vector<vector<int>>,comparator>pq;
    int tree_id[e];
    for(int i=0;i<e;i++)
    {
        tree_id[i]=i;
    }
    for(auto x:graph)
    {
        pq.push(x);
    }
    for(int i=0;i<e;i++)
    {
        vector<int>x=pq.top();
        pq.pop();
        if(tree_id[x[1]]!=tree_id[x[2]])
        {
            cout<<x[1]<<"->"<<x[2]<<" Cost:"<<x[0]<<endl;
            int old=tree_id[x[2]];
            int nw=tree_id[x[1]];
            for(int i=0;i<e;i++)
            {
                if(tree_id[i]==old)
                {
                    tree_id[i]=nw;
                }
            }
        }
    }
}
int main()
{
    cin>>v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int>temp={n3,n1,n2};
        graph.push_back(temp);
    }
    prims();
}