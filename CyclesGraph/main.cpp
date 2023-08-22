#include <iostream>
#include <vector>


// Adjacency list of graph
std::vector<std::vector<int>> g;

// Size of adjacency
int n;

std::vector<bool> used(n,false);


// return -1, if we don't find a cycle, else the vertex index of cycle beginning
// p is the index of the previous vertex
// Time Complexity: O(n+m) n - quantity of vertices, m - quantity of edges
int dfs(int v, int p = -1) {
    if (used[v]) {
        std::cout << "Graph has a cycle:" << "\n";
        return v;
    }
    used[v] = true;
    for (int u : g[v]) {
        if (u != p) {
            int k = dfs(u, v);
            if (k != -1) {
                std::cout << v << "\n";
                if (k == v)
                    exit(0);
                return k;
            }
        }
    }
    return -1;
}

int main() {

}
