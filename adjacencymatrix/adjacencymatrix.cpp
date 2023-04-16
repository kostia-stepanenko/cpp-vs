// adjacencymatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <set>
/// http://www.cplusplus.com/reference/queue/queue/

using namespace std;
template<typename TnodeInfo, typename TedgeInfo>
class Graph {
public:
    int N;
    char** A;
    TnodeInfo* nodeInfo;
    TedgeInfo** edgeInfo;

    Graph(int numNodes) {
        int i, j;

        N = numNodes;

        /// allocate the adjacency matrix
        A = new char* [N]; ///allocated rows
        for (i = 0; i < N; i++)
            A[i] = new char[N]; ///allocated columns

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                A[i][j] = 0;

        // allocate the array with node information
        nodeInfo = new TnodeInfo[N];

        // allocate the matrix of edge information
        edgeInfo = new TedgeInfo * [N];
        for (i = 0; i < N; i++)
            edgeInfo[i] = new TedgeInfo[N];
    }

    void setNodeInfo(int i, TnodeInfo info) {
        nodeInfo[i] = info;
    }

    TnodeInfo getNodeInfo(int i) {
        return nodeInfo[i];
    }

    void addEdge(int i, int j) {
        A[i][j] = 1;
        A[j][i] = 1;
    }
    void removeEdge(int i, int j) {
        A[i][j] = 0;
        A[j][i] = 0;
    }

    void setEdgeInfo(int i, int j, TedgeInfo info) {
        edgeInfo[i][j] = info;
        edgeInfo[j][i] = info;
    }

    TedgeInfo getEdgeInfo(int i, int j) {
        return edgeInfo[i][j];
    }

    ~Graph() {
        int i;
        for (i = 0; i < N; i++) {
            delete A[i];
            delete edgeInfo[i];
        }
        delete A;
        delete edgeInfo;
        delete[] nodeInfo;
    }
};

Graph<int, int> g(9);

char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop(); ///dequeue
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
                Q.push(y);
            }
    }
}

set<int> red;

set<int> black;

bool containsInSet(int key, set<int> set) {
    return set.find(key) != set.end();
}

void printSet(set<int> s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}

bool bip(int start) {
    std::queue<int> queue;

    red.insert(start);
    queue.push(start);

    while (!queue.empty()) {

        int cur = queue.front();
        queue.pop(); ///dequeue

        int curColor;
        if (containsInSet(cur, red)) {
            curColor = 0; // RED
        }
        else {
            curColor = 1; // BLACK
        }

        
        for (int other = 0; other < g.N; ++other) {

            int edgeVal = g.A[cur][other];

            if (g.A[cur][other]) {

                if (containsInSet(other, red)) {
                    if (curColor == 0) {
                        return false;
                    }
                }
                else if (containsInSet(other, black)) {
                    if (curColor == 1) {
                        return false;
                    }
                }
                else {
                    // not colored yet node

                    queue.push(other);

                    int otherColor = (curColor + 1) % 2;

                    if (otherColor == 0) {
                        red.insert(other);
                    }
                    else {
                        black.insert(other);
                    }
                    
                }

            }
        }
    }

    return true;
}



int main() {
    /*
    visited = new char[g.N];
    for (int i = 0; i < g.N; i++) {
        visited[i] = 0;
    }

    // add edges
    g.addEdge(4, 0),
    g.addEdge(4, 2),
    g.addEdge(4, 6),
    g.addEdge(4, 7),
    g.addEdge(6, 5),
    g.addEdge(5, 7),
    g.addEdge(7, 3),
    g.addEdge(3, 1);


    dfs(4);
    //bfs(4);

    delete[] visited;
    */

    // add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 4);
    g.addEdge(1, 3);
    g.addEdge(4, 7);
    g.addEdge(6, 8);
    g.addEdge(3, 2);
    g.addEdge(7, 8);
   // g.addEdge(3, 6);
    
  

    bool isBip = bip(0);

    if (isBip) {
        cout << "bipartite" << endl;
        // todo: output red, black
        printSet(red);
        printSet(black);
    }
    else {
        cout << "Not bipartite" << endl;
    }

    return 0;
}



