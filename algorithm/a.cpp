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
#define ll long long
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 400000;
const ll MOD = 998244353;
ll t,tt, n, m,x,y,q,l;
ll a[M];
ll countDigits(ll x) {
    ll ans = 0;
    while (x != 0) {
        ans ++;
        x /= 10;
    }
    return ans;
}
ll cnt[20];
//https://codeforces.com/problemset/problem/1195/D2
int main() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[countDigits(a[i])] ++;
    }
    for (int i = 0; i < n ;i++) {

    }

}

