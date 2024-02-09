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

bool isSimilar(string str1, string str2, int diff = 0){
    for(int i = 0 ; i < str1.size() ; i++){
        if(str1[i] != str2[i]) diff++;
        if(diff > 2 ) return false;
    }
    return true;
}

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());
        for(int i = 0 ; i < strs.size() ; i++){
            for(int j = i +1 ; j < strs.size() ; j++){
                if(isSimilar(strs[i],strs[j])){
                    uf.unionSets(i,j);
                }
            }
        }
        return uf.forests;
    }
};