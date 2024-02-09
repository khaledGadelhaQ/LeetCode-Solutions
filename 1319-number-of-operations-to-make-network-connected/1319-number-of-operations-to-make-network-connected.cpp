#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            swap(x, y);
        }
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y] += 1;
        }
    }
public:
    int forests {0};
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        forests = n;
        for (int i = 0; i < n; i++)
            parent[i] = -1, rank[i] = 1;
    }
    int Find(int x) {
        if (parent[x] == -1) {
            return x;
        }
        return parent[x] = Find(parent[x]);
    }
    bool unionSets(int x, int y) {
        x = Find(x), y = Find(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x != y;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& A) {
        int sz = A.size();
        if(sz < n-1) return -1;
        UnionFind uf(n);
        for(auto &edge : A)
            uf.unionSets(edge[0],edge[1]);
        return uf.forests -1 ;
    }
};