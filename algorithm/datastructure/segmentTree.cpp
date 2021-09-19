#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// This example track how many zeros in array: 00100111
ll temp;
int n;
int M = 2*pow(10, 5) + 10;
int l, r, q;
struct Node {
    int v = 0;
    int zeroCnt = 0;
    int end = true;
    Node *left = NULL;
    Node *right = NULL;
};
Node *head;
// update l~r to v
void segUpdate(Node *p, int cL, int cR, int l, int r, int v) {
    if (l <= cL && cR <= r) {
        p->end = true;
        p->v = v;
        if (p->v == 0) {
            p->zeroCnt = cR - cL + 1;    
        } else {
            p->zeroCnt = 0;
        }
        
        return;
    }
    if (cR < l || r < cL) {
        return;
    }
    if (p->left == NULL) {
        p->left = new Node();
        p->right = new Node();
    }
    // make sure to pass end node to its children, needs to recalculate.
    if (p->end == true) {
        p->end = false;    
        p->left->end = true;
        p->left->v = p->v;
        if (p->left->v == 0) {
            p->left->zeroCnt = ((cL + cR)/2 - cL + 1);
        } else {
            p->left->zeroCnt = 0;
        }
        p->right->end = true;
        p->right->v = p->v;
        if (p->right->v == 0) {
            p->right->zeroCnt = (cR - ((cL + cR)/2+1) + 1);
        } else {
            p->right->zeroCnt = 0;
        }
    }
    segUpdate(p->left, cL, (cL + cR)/2, l, r, v);
    segUpdate(p->right, (cL + cR)/2+1, cR, l, r, v);
    p->zeroCnt = p->left->zeroCnt + p->right->zeroCnt;
}
// get zero counts for l~r
int segGetZeroCnt(Node *p, int cL, int cR, int l, int r) {
    if (l <= cL && cR <= r) {
       // printf("getZeroCnt: %d %d %d \n", cL,  cR,  p->zeroCnt);
        return p->zeroCnt;
    }
    if (cR < l || r < cL) {
        return 0;
    }
    if (p->end) {
        if (p->v == 0) {
            return min(r, cR) - max(cL, l) + 1;    
        } else {
            return 0;
        }
    }
    return segGetZeroCnt(p->left, cL, (cL + cR)/2, l, r) +
           segGetZeroCnt(p->right, (cL + cR)/2+1, cR, l, r);
}

void setSegTree(int l, int r, int v) {
    //printf("setSegTree %d %d %d\n", l, r, v);
    segUpdate(head, 0, M, l, r, v);
}


int getMajor(int l, int r) {
    int cnt = segGetZeroCnt(head, 0, M, l, r);
   // printf("===getZeroCnt %d %d %d\n", l, r, cnt);
    int total = r - l + 1;
    if (cnt * 2 > total) {
        return 0;
    } else if ((total - cnt) * 2 > total) {
        return 1;
    } else {
        return -1;
    }
}
void out() {
    for (int i = 0;  i < n; i++) {
        cout << getMajor(i, i);
    }
    printf("\n");
}
int main() {
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++) {
        int ans = 1;
        head = new Node();
        string s0, s1;
        vector<pair<int,int>> a;
        scanf("%d %d", &n, &q);
        cin >> s0;
        cin >> s1;
        for (int i = 0; i < n; i++) {
            setSegTree(i, i, s1[i] - '0');
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &l, &r);
            a.push_back({l, r});
        }

       //out();
        for (int i = q-1; i >= 0; i--) {
            int l = a[i].first-1;
            int r = a[i].second-1;
            int major = getMajor(l, r);
            if (major == -1) {
               // printf("no major \n");
                ans = -1;
                break;
            }
            setSegTree(l, r, major);
           // out();
        }
        for (int i = 0; i < n; i++) {
            if (getMajor(i,i) != s0[i] - '0') {
               // printf("not equal\n");
                ans = -1;
                break;
            }
        }
        if (ans == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}