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
 
int n, m, s, x, y; 
vector<int> edge[M];
int num[M];
int low[M];
int ind = 1;
bool inSta[M];
int scc[M];
int sccCounter = 0;
deque<int> sta;
int hasIndeg[M];
void tarjan(int v) {
    num[v] = ind;
    low[v] = ind;
    inSta[v] = true;
    sta.push_back(v);
    ind ++;
    for (int next: edge[v]) {
        if (num[next] == 0) {
            tarjan(next);    
            low[v] = min(low[v], low[next]);
        } else if (inSta[next]) {
            low[v] = min(low[v], num[next]);
        }
    }
    if (low[v] == num[v]) {
        sccCounter ++;
        while (sta.size() > 0 && sta.back() != v) {
            scc[sta.back()] = sccCounter;
            inSta[sta.back()] = false;
            sta.pop_back();
        }
        scc[sta.back()] = sccCounter;
        inSta[sta.back()] = false;
        sta.pop_back();
    }
}
int main() {
    cin >> n >> m >> s;
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(inSta, 0, sizeof(inSta));
    memset(scc, 0, sizeof(scc));
    memset(hasIndeg, 0, sizeof(hasIndeg));
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0)
            tarjan(i);
    }
    hasIndeg[scc[s]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int next: edge[i]) {
            if (scc[i] != scc[next])
                hasIndeg[scc[next]] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccCounter; i++) {
        if (hasIndeg[i] == false) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}