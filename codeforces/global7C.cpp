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
dataSet e; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 200200;
const long long MOD = 998244353;
long long x, n, k;
int main() {
    scanf("%lld %lld", &n, &k);
    long long ans = 1;
    long long last = 0;
    long long i = 0;
    while (i < n) {
        i ++;
        scanf("%lld", &x);
        if (x > n - k) {
            last = i;
            break;
        }
    }
    while (i < n) {
        i++;
        scanf("%lld", &x);
        if (x > n - k) {
            ans = (ans * (i-last)) % MOD;
            last = i;
        }   
    }
    cout << (n-k+1+n) * k/2 <<" "<< ans;
    return 0;
}