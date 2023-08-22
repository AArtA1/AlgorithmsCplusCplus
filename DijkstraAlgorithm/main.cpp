#include <iostream>
#include <vector>
#include <queue>


// Adjacency list of graph
std::vector<std::vector<std::pair<int, int>>> g;
std::vector<int> path;

int n;

const int32_t inf = INT32_MAX;


// Find the min distance to the destination vertex
// If g is almost complete graph
// Time Complexity: O(n^2) n - quantity of vertices, m - quantity of edges
std::vector<int> dijkstra(int s) {
    std::vector<int> d(n, inf);
    std::vector<bool> a(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        // находим вершину с минимальным d[v] из ещё не помеченных
        int v = -1;
        for (int u = 0; u < n; u++)
            if (!a[u] && (v == -1 || d[u] < d[v]))
                v = u;
        // помечаем её и проводим релаксации вдоль всех исходящих ребер
        a[v] = true;
        for (auto [u, w]: g[v]) {
            if (d[u] > d[v] + w) {
                path[u] = v; // for recovering path further
                d[u] = d[u] + w;
            }
        }
    }
    return d;
}


// If g is a sparse graph
// Time Complexity: O(mlogn) - n - quantity of vertices, m - quantity of edges
std::vector<int> dijkstra_(int s){
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> queue;
    queue.push({0,s});
    std::vector<int> d(n, inf);
    d[s] = 0;
    while(!queue.empty()){
        auto [cur_d,v] = queue.top();
        queue.pop();
        if(cur_d > d[v]){
            continue;
        }
        for(auto [u, w] : g[v]){
            if(d[u] > d[v] + w){
                d[u] = d[v] + w;
                queue.push({d[u],u});
                path[u] = v;
            }
        }
    }
    return d;
}





std::vector<int> get_path(int s,int v) {
    std::vector<int> temp;
    while (v != s) {
        temp.push_back(v);
        v = path[v];
    }
    temp.push_back(s);
    return temp;
}


int main() {
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> queue;
    queue.push({1,2});
    queue.push({2,4});
    std::cout << queue.top().first;
    queue.pop();
}
