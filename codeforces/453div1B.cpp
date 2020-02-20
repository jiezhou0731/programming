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
const long long INF = pow(2, 25);
const long long M = 5020;
const long long  ALL1 = pow(2, 17) -1;
int n, m, k, x, y, t; 
int a[200];
int f[120][ALL1+500];
pair<int,int> last[120][ALL1+500];
vector<int> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
long long state[100];
void tryset(int &x, int v, pair<int,int> &l, pair<int,int> lv) {
    if (v == 0) return;
    if (x == 0) {
        x = v;
        l = lv;
    } else {
        if (x > v) {
            x = v;
            l = lv;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
    }
    memset(f, 0, sizeof(f));
    memset(state, 0, sizeof(state));
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= 60; i++) {
        for (int j = 0; j < pri.size(); j++) {
            if (i / pri[j] > 0 && i % pri[j] == 0) {
                state[i] |= (1 << j);
            }
        }
    }
 
    f[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (long long  j = 0; j <= ALL1; j++) {
            if (f[i][j] != 0) {
                for (int k = 1; k <= 60; k++) {
                    if ((state[k] & j) == 0) {
                        t = (state[k] | j);
                        tryset(f[i+1][t], f[i][j] + abs(k - a[i+1]), last[i+1][t], {j,k});
                    }
                }
            }
        }
    }
    int ans = 0;
    pair<int,int> ansP;
    for (long long  j = 0; j <= ALL1; j++) {
        tryset(ans, f[n][j], ansP, {last[n][j].first, last[n][j].second});
    }
    deque<int> tt;
    for (int i = n; i >= 1; i--) {
        tt.push_front(ansP.second);
        ansP = last[i-1][ansP.first];
    }
    for (int i :tt) {
        printf("%d ", i);
    }
    return 0;
}