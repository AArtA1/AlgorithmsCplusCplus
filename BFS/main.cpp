#include <iostream>
#include<vector>
#include <queue>
#include <algorithm>


// Adjacency list of graph
std::vector<std::vector<int>> g;

// Size of adjacency
int n;

std::vector<int> destination_length, path_to_destination;
std::vector<bool> used;


// BFS (Breadth first search)
// Time Complexity: O(n+m) n - quantity of vertices, m - quantity of edges
void bfs(int source_index){
    std::queue<int> q;
    destination_length.assign(n,0);
    path_to_destination.assign(n,0);
    used.assign(n, false);
    q.push (source_index);
    used[source_index] = true;
    path_to_destination[source_index] = -1;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (size_t i=0; i<g[vertex].size(); ++i) {
            int to = g[vertex][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                destination_length[to] = destination_length[vertex] + 1;
                path_to_destination[to] = vertex;
            }
        }
    }
}



void recovery_path(int destination_index){
    if (!used[destination_index])
        std::cout << "No path";
    else {
        std::vector<int> path;
        for (int v=destination_index; v != -1; v= path_to_destination[v]){
            path.push_back (v);
        }
        std::reverse(path.begin(), path.end());
        std::cout << "Path: ";
        for (size_t i=0; i<path.size(); ++i)
        {
            std::cout << path[i] + 1 << " ";
        }
    }
}

int main() {

}
