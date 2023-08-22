#include <iostream>
#include <vector>
#include <stack>


// Adjacency list of graph
std::vector<std::vector<int>> g;

// Size of adjacency
int n;

std::vector<bool> used(n,false);

// DFS (Depth first search) recurrent
// Time Complexity: O(n+m) n - quantity of vertices, m - quantity of edges
void dfs(int source_index){
    used[source_index] = true;
    for(auto item : g[source_index]){
        if(!used[item]){
            dfs(item);
        }
    }
}

int main() {

}
