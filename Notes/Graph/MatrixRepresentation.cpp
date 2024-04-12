#include <bits/stdc++.h>
//#include <queue>

using namespace std;

void BFS(int **graph, int source, int nodes)
{
    bool visitedArray[nodes + 1];
    for (int i = 0; i <= nodes; i++)
    { // Ensure to iterate until nodes, not nodes+1
        visitedArray[i] = false;
    }

    queue<int> q;
    q.push(source);
    visitedArray[source] = true;

    while (!q.empty())
    {
        int head = q.front(); // pick head

        cout << head << endl;
        q.pop(); // explore head
        for (int i = 1; i <= nodes; i++)
        { // Ensure to iterate until nodes, not nodes+1
            if (graph[head][i] && !visitedArray[i])
            {
                q.push(i);
                visitedArray[i] = true;
            }
        }
    }
    cout << endl;
}
void DFS(int **graph, int source, int nodes)
{
    bool visitedArray[nodes + 1];
    for (int i = 0; i <= nodes; i++)
    { // Ensure to iterate until nodes, not nodes+1
        visitedArray[i] = false;
    }

    stack<int> q;
    q.push(source);
    visitedArray[source] = true;

    while (!q.empty())
    {
        int head = q.top(); // pick head

        cout << head << endl;
        q.pop(); // explore head
        for (int i = 1; i <= nodes; i++)
        { // Ensure to iterate until nodes, not nodes+1
            if (graph[head][i] && !visitedArray[i])
            {
                q.push(i);
                visitedArray[i] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    int **graph = new int *[nodes + 1];
    for (int i = 0; i <= nodes; i++)
    {
        graph[i] = new int[nodes + 1];
        for (int j = 0; j <= nodes; j++)
        {
            graph[i][j] = 0; // Initialize the adjacency matrix with 0
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    int source = 1;
    BFS(graph, source, nodes);
    DFS(graph, source, nodes);

    // Free memory
    for (int i = 0; i <= nodes; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
