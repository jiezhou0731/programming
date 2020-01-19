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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const int MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 100200;
long long MOD = pow(10, 9) + 7;
long long n, m;
long long f[15][1500];
long long g[15][1500];
int main()
{   
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
    scanf("%lld %lld", &n, &m);
    for (long long j = 1; j <= n; j++) {
    	f[1][j] = 1;
    }
    for (long long i = 2; i <= m; i++) {
    	for (long long j = 1; j <= n; j++) {
    		f[i][j] = (f[i-1][j] + f[i][j-1]) % MOD;
    	}
    }
    for (long long i = 1; i <= m; i++) {
    	for (long long j = 1; j <= n; j++) {
    		g[i][j] = (g[i][j-1] + f[i][j]) % MOD;
    	}
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
    	ans = (ans + f[m][i] * g[m][n - i+1]) % MOD;
    }
    cout << ans;
 
    return 0;
}