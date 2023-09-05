#include <vector>
#include <algorithm>


// Kruskal's Algorithm

// Graph - G(n,m)

// Time Complexity: O(mlogn + n + m) = O(mlogn)

int n;

std::vector<int> p (n);

std::vector < std::pair < int, std::pair<int,int> > > g; // weight  -  source vertex   -   destination vertex


int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        std::swap (a, b);
    if (a != b)
        p[a] = b;
}

void kruskal(){
    int m;
    int cost = 0;
    std::vector < std::pair<int,int> > res;
    sort (g.begin(), g.end());
    p.resize (n);
    for (int i=0; i<n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            res.push_back (g[i].second);
            dsu_unite (a, b);
        }
    }
}


int main() {
}
