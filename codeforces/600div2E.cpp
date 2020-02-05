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
const long long M = 500200;
 
int n, m, f[M], s[M], x[M]; 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
    }
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < x[j]) {
                if (x[j] - s[j] <= i) {
                    f[i] = min(f[i], f[max(x[j]-s[j], 1) - 1]);
                } else {
                    f[i] = min(f[i], f[i-1] + x[j] - s[j] - i);
                }
            } else {
                f[i] = min(f[i], f[max(x[j] - (i - x[j]), 1) - 1] + max((i - x[j]) - s[j], 0));
            }
        }
    }
    cout << f[m] <<"\n";
    return 0;
}