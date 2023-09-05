#include <iostream>
#include <vector>
#include <set>


// Prim's algorithm


// G(n,m)

// G - Complete graph

// Time Complexity: O(n^2)

int n;
std::vector < std::vector<int> > g;
const int INF = INT32_MAX;

std::vector<bool> used (n);
std::vector<int> min_e (n, INF), sel_e (n, -1);


void prim(){
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            std::cout << "No MST!";
            return;
        }

        used[v] = true;
        if (sel_e[v] != -1)
            std::cout << v << " " << sel_e[v] << "\n";

        for (int to=0; to<n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }

}


// G - Sparse graph


// Time Complexity: O(mlogn)

std::vector < std::vector < std::pair<int,int> > > g_; // pair.first - weight, pair.second - vertex

void prim_(){
    min_e[0] = 0;
    std::set < std::pair<int,int> > q;
    q.insert (std::make_pair (0, 0));
    for (int i=0; i<n; ++i) {
        if (q.empty()) {
            std::cout << "No MST!";
            return;
        }
        int v = q.begin()->second;
        q.erase (q.begin());

        if (sel_e[v] != -1)
            std::cout << v << " " << sel_e[v] << "\n";

        for (size_t j=0; j<g_[v].size(); ++j) {
            int to = g_[v][j].first,
                    cost = g_[v][j].second;
            if (cost < min_e[to]) {
                q.erase (std::make_pair (min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = v;
                q.insert (std::make_pair (min_e[to], to));
            }
        }
    }
}


int main() {

}
