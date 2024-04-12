#include <bits/stdc++.h>


using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


void dfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    // Create a stack for DFS
    stack<int> stk;

    // Mark the current node as visited and push it onto the stack
    visited[startNode] = true;
    stk.push(startNode);

    // Iterate until the stack is empty
    while (!stk.empty()) {
        // Pop a vertex from the stack and print it
        int currentNode = stk.top();
        stk.pop();
        cout << currentNode << " ";

        // Explore all adjacent vertices of the popped vertex
        // If an adjacent vertex has not been visited, mark it visited and push it onto the stack
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stk.push(neighbor);
            }
        }
    }
}


// Function to add an edge between two vertices in the adjacency list
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main() {
    int vertices = 8; // Number of vertices in the graph

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 3, 6);
    addEdge(adjList, 3, 7);

    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 1
    cout << "Breadth First Traversal starting from vertex 1: ";
    bfs(adjList, 1, visited);
    cout << endl;
     cout << "Depth First Traversal starting from vertex 1: ";
    dfs(adjList, 1, visited);
    cout << endl;

    return 0;
}
