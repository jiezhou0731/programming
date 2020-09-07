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
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = pow(10,6);
const ll MOD = 998244353;

long long cost = 0;
long long n, m, k, d, f, t, c, dmax;
vector<tuple<ll,ll,ll,ll>> a;
int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    dmax = 0;
    for (int i = 0; i < m ;i++) {
        scanf("%lld %lld %lld %lld",&d, &f, &t, &c);
        dmax = max(d, dmax);
        a.push_back(d,f,t,c);
    }
    sort(a.begin(), a.end());
    ll ans = -1;
    ll enterCnt = 0;
    ll enterCost = 0;
    multiset<ll> enter[M];
    ll backCnt = 0;
    ll backCost = 0;
    multiset<ll> back[M];
    for (ll i = 0; i < a.size(); i++) {
        d = get<0>(a[i]);
        f = get<1>(a[i]);
        t = get<2>(a[i]);
        c = get<3>(a[i]);

    }

    for (ll i = 1; i <= dmax - k + 1; i++) {

    }
    return 0;
}

