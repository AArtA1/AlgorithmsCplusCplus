#include <vector>


// We also can use whatever operation that has inverse element instead of plus on the set
// f(i) = i & (i+1) return operation result on the segment from f(i) to i
// g(i) = i | (i+1) return index reference to the next element that has to be changed unless index is out of range
// Get complexity: O(logn)
// Change Complexity: O(logn)
// Space Complexity: O(n)
struct fenwick_tree{
public:
    fenwick_tree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    fenwick_tree(const std::vector<int> &a) : fenwick_tree(a.size()) {
        for (int i = 0; i < a.size(); i++){
            add(i, a[i]);
        }
    }

    // find operation result from 0 to r
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }


    void add(int index, int delta) {
        for (; index < n; index = index | (index + 1)){
            bit[index] += delta;
        }
    }

private:
    std::vector<int> bit;
    int n;
};




int main() {
    fenwick_tree f (std::vector<int> {1,2,3,4,5});
    f.sum(2);
}
