#include <iostream>
#include <list>

using namespace std;

class graph {
    int v;
    list<int> *adj;
    void DFSutil(int, bool []);
public:
    graph(int v); // constructor
    void addedge(int v, int w);
    void BFS(int s);
    void DFS(int);
};

graph::graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void graph::addedge(int v, int w) {
    adj[v].push_back(w); // add w to v's list
}

void graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for (int i=0; i < v; i++)
        visited[i] = false;

    // create a queue for BFS
    list<int> queue;

    // Mark current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    while(!queue.empty()) {
        // dequeue a vertex from queue and print
        s = queue.front();
        cout<< s << " ";
        queue.pop_front();
        // If adjacent vertex is not visited then mark it as visited and enqueue

        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void graph::DFSutil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recursive for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i])
            DFSutil(*i, visited);
    }
}

void graph::DFS(int v) {
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++ )
        visited[i] = false;

    // call recursive function to print DFS traversal
    DFSutil(v, visited);
}

int main() {

    graph g = graph(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);

    cout << "Follow of BFS (vertex 2) \n";
    g.BFS(2);

    cout <<endl<< "Follow of DFS (vertex 2) \n";
    g.DFS(2);

    return 0;
}
