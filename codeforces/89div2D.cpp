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
const long long M = 100200;
long long MOD = pow(10, 8);
long long n[3];
long long m[3];
long long f[250][150][5][15];
int main()
{   
    memset(f, 0, sizeof(f));
    cin >> n[0] >> n[1] >> m[0] >> m[1];
    f[0][0][0][0] = 1;
    long long ans = 0;
    for (long long i = 0; i <= n[0] + n[1]; i++) {
        for (long long j = 0; j <= min(i, n[0]); j++) {
            for (long long k= 0; k<= 1; k++) {
                for (long long l = 0; l <= m[k]; l++) {
                    if (f[i][j][k][l] == 0) continue;
                    if (i == n[0] + n[1]) {
                        ans = (ans + f[i][j][k][l]) % MOD;
                    }
                    for (long long c = 0; c <= 1; c++) {
                        long long jj = j;
                        if (c == 0) {
                            jj ++;
                        }
                        if (c == 0) {
                            if (jj > n[0]) continue;
                        } else {
                            if (i + 1- jj > n[1]) continue;
                        }
                        if (c == k) {
                            if (l+1 <= m[c]) {
                                f[i+1][jj][k][l+1] = (f[i+1][jj][k][l+1]  + f[i][j][k][l]) % MOD;    
                            }
                        } else {
                            f[i+1][jj][c][1] = (f[i+1][jj][c][1] + f[i][j][k][l]) % MOD;    
                        }
                    }
                }
            }    
        }
    }
    cout << ans;
 
    return 0;
}