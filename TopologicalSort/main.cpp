#include <iostream>
#include <vector>
#include <algorithm>

// Adjacency list of graph
std::vector<std::vector<int>> g;

// Size of adjacency
int n;

std::vector<bool> used;

// result f.e 4 1 2 0 3 means vertix 4 is the first in sequence,1 is the second e.t.c
std::vector<int> result;



// DFS (Depth first search) recurrent
// Time Complexity: O(n+m) n - quantity of vertices, m - quantity of edges
void dfs(int source_index){
    used[source_index] = true;
    for(auto item : g[source_index]){
        if(!used[item]){
            dfs(item);
        }
    }
    result.push_back(source_index);
}


// Time Complexity: O(n+m) n - quantity of vertices, m - quantity of edges
void topological_sort() {
    used.assign(n, false);
    for (int v = 0; v < n; v++)
        if (!used[v])
            dfs(v);
    reverse(result.begin(), result.end());
}


int main() {

}
