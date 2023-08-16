#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(const vector<vector<int>>& adj_list, int start)
{
    int n = adj_list.size();
    vector<bool> visited(n, false);
    stack<int> stk;

    stk.push(start);
    visited[start] = true;
    cout << "DFS traversal order: ";

    while (!stk.empty())
    {
        int v = stk.top();
        stk.pop();
        cout << v << " ";

        for (int u : adj_list[v])
        {
            if (!visited[u])
            {
                stk.push(u);
                visited[u] = true;
            }
        }
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj_list(n);

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            if (value != 0)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    dfs(adj_list, start);

    return 0;
}