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
const long long M = 3 * pow(10, 5) + 500;
int t, n, m;
int l[M + 500], r[M+ 500];
int a[M+ 500];
int bit[2*M+500];
void updateBIT(int pos, int v) {
    while (pos < 2*M) {
        bit[pos] += v;
        pos += (pos & -pos);
    }
}
int queryBIT(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += bit[pos];
        pos -= (pos & -pos);
    }
    return ans;
}
int main()
{  
    scanf("%d %d", &n, &m);
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        l[i] = i;
        r[i] = i;
        a[i] = M + i;
        updateBIT(M + i, 1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        l[t] = 1;
        r[t] = max(r[t], queryBIT(a[t]));
        updateBIT(a[t], -1);
        a[t] = M - i;
        updateBIT(a[t], 1);
    }
    for (int i = 1; i <= n; i++) {
        r[i] = max(r[i], queryBIT(a[i]));
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}