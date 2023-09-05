#include <iostream>
#include <vector>


// DSU - Disjoint-Set Data Structure

int n;

std::vector<int> parent(n);
std::vector<int> rank(n);

void make_set (int v) {
    parent[v] = v;
    rank[v] = 0;
}


// Time Complexity: Approximately equals to O(1)
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}


// Time Complexity: Approximately equals to O(1)
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap (a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}


int main() {
}
