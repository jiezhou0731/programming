// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/submissions/   
#include <bits/stdc++.h> 
using namespace std; 
vector<vector<int>> f;
TreeAncestor(int n, vector<int>& parent) {
    f = vector<vector<int>> (n, vector<int>(20,-1));
    for (int i = 0; i < n; i++) {
        f[i][0] = parent[i];
    }
    for (int l = 1; l <= 19; l++) {
        for (int i = 0; i < n; i++) {
            if (f[i][l-1] >= 0) {
                if (f[f[i][l-1]][l-1] >= 0) {
                    f[i][l] = f[f[i][l-1]][l-1];
                }
            }
        }
    }
}

int getKthAncestor(int x, int k) {
    if (x == -1) {
        return -1;
    }
    if (k == 1) {
        return f[x][0];
    }
    if (k == 0) {
        return x;
    }
    int cur = 1;
    int next = 0;
    while (cur * 2 <= k) {
        cur *= 2;
        next += 1;
    }
    return getKthAncestor(f[x][next], k - cur);
}