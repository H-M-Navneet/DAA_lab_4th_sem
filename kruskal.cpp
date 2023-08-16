#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>graph;
int v,e;
void kruskal()
{
    int tree_id[e];
    sort(graph.begin(),graph.end());
    for(int i=0;i<e;i++)
    {
        tree_id[i]=i;
    }
    for(auto x:graph)
    {
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
    kruskal();
}