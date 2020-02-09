#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(10, 9);
const long long M = 200500;
int n,q,t,le, ri;
int segTail = 1;
struct SegNode {
    int l = 0, r = 0, v = 0;
};
SegNode seg[80 * M];
set<pair<int, int>> lenLeft;
set<pair<int, int>> leftLen;
map<int,int> isIn;
void segUpdate(int pos, int value, int s, int e, int p) {
    if (pos < s || e < pos) {
        return;
    }
    seg[p].v += value;
    if (s == e) return;
    if (seg[p].l == 0) {
        segTail ++;
        seg[p].l = segTail;
    } 
    segUpdate(pos, value, s, (s+e)/2, seg[p].l);
    if (seg[p].r == 0) {
        segTail ++;
        seg[p].r = segTail;
    }
    segUpdate(pos, value, (s+e)/2 + 1, e, seg[p].r);
}
int segQuery(int le, int ri, int s, int e, int p) {
    if (p == 0 || ri < s || e < le) {
        return 0;
    }
    if (le <= s && e <= ri) {
        return seg[p].v;
    }
    return segQuery(le, ri, s, (s+e)/2, seg[p].l)
        + segQuery(le, ri, (s+e)/2+1, e, seg[p].r);

}
int main() {
    scanf("%d%d", &n, &q);
    leftLen.insert({1, n});
    lenLeft.insert({n, 1});
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d%d", &le, &ri);
            printf("%d\n", segQuery(le, ri, 1, INF, 1));
        } else {
            if (isIn[t] == 0) {
                auto p = prev(lenLeft.end());
                int len = p->first;
                int le = p->second;
                lenLeft.erase(p);
                leftLen.erase({le, len});
                int newLeftLen = len / 2;
                if (newLeftLen > 0) {
                    lenLeft.insert({newLeftLen, le});
                    leftLen.insert({le, newLeftLen});  
                } 
                isIn[t] = le + newLeftLen; 
                segUpdate(isIn[t], 1, 1, INF, 1);

                int newRightLen = (len - 1) / 2;
                if (newRightLen > 0) {
                    lenLeft.insert({newRightLen, le + newLeftLen + 1});
                    leftLen.insert({le + newLeftLen + 1, newRightLen});
                }
            } else {
                segUpdate(isIn[t], -1, 1, INF, 1);
                auto p = leftLen.lower_bound({isIn[t], 0});
                int newLe = isIn[t];
                isIn[t] = 0;
                int newLen = 1;
                if (p != leftLen.begin()) {
                    auto pre = prev(p);
                    if (pre->first + pre->second == newLe) {
                        newLe = pre->first;
                        newLen += pre->second;
                        lenLeft.erase({pre->second, pre->first});
                        leftLen.erase(pre);
                    }
                }
                if (p != leftLen.end()) {
                    if (newLe + newLen == p->first) {
                        newLen += p->second;
                        lenLeft.erase({p->second, p->first});
                        leftLen.erase(p);
                    }   
                }
                lenLeft.insert({newLen, newLe});
                leftLen.insert({newLe, newLen});
            }
        }
    }
    return 0;
}