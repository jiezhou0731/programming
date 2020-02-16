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
const long long M = 100500;
vector<tuple<long long,long long,long long>> a;
long long x,y,n;
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x, &y);
        a.push_back({x,y, i});
    }
    sort(a.begin(), a.end());
    if (get<0>(a[0]) == get<0>(a[1])) {
        int i = 2;
        while (get<0> (a[i]) == get<0>(a[0]))
            i++;
        printf("%lld %lld %lld", get<2>(a[0]), get<2>(a[1]), get<2>(a[i]));
    } else if (get<1>(a[0]) == get<1>(a[1])) {
        int i = 2;
        while (get<1>(a[0]) == get<1>(a[i]))
            i++;
        printf("%lld %lld %lld", get<2>(a[0]), get<2>(a[1]), get<2>(a[i]));
    } else {
        int i = 2;
        while (
            (get<1>(a[1]) - get<1>(a[0])) * (get<0>(a[i]) - get<0>(a[0]))
            == (get<0>(a[1]) - get<0>(a[0])) * (get<1>(a[i]) - get<1>(a[0])))
            i++;
 
        printf("%lld %lld %lld", get<2>(a[0]), get<2>(a[1]), get<2>(a[i]));
    }
    return 0;
}