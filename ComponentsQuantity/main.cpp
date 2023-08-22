#include <iostream>
#include <vector>



// Adjacency list of graph
std::vector<std::vector<int>> g;

// Size of adjacency
int n;

std::vector<bool> used;

void dfs(int source_index){
    used[source_index] = true;
    for(auto item : g[source_index]){
        if(!used[item]){
            dfs(item);
        }
    }
}


// Time Complexity: O(m)
int find(){
    used.assign(n, false);
    int res = 0;
    for(int i  = 0; i < n;++i){
        if(g[i].empty()){
            ++res;
            continue;
        }
        if(!used[i]){
            dfs(i);
            ++res;
            continue;
        }
    }
    return res;
}



int main() {
    n = 8;
    g.push_back({1,4});
    g.push_back({0});
    g.push_back({3,5});
    g.push_back({2,6});
    g.push_back({4});
    g.push_back({2,6});
    g.push_back({3,5});
    g.emplace_back();
    std::cout << find();
}
