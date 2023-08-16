#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

vector<int> dist;
vector<vector<pair<int,int>>> graph;
int V,E;

void dijkstras(int source)
{
    dist.assign(V,INF);
    dist[source]=0;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[u])
            continue;
        for(auto& neighbour:graph[u])
        {
            int v=neighbour.first;
            int w=neighbour.second;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    cout<<"enter no.of edges and vertices\n";
    cin>>V>>E;
    graph.resize(V);
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int source;
    cout<<"enter source vertex\n";
    cin>>source;
    dijkstras(source);
    cout<<"shortest distance from source "<<source<<" :\n";
    for(int i=0;i<V;i++)
    {
        if(dist[i]==INF)
        {
            cout<<"vertex"<<i<<" : INF\n";
        }
        else
        {
            cout<<"vertex"<<i<<" : "<<dist[i]<<endl;
        }
    }
    return 0;
}