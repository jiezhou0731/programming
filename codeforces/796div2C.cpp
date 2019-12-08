#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
const long long MOD = 100000000007;
const long long M = 300100;
const long long MIN = numeric_limits<long long>::min();
long long n;
long long a[M];
long long f[M][3];
vector<long long> edges[M];
long long x, y, ans;
void calc(long long p, long long last) {
    f[p][0] = a[p];
    f[p][1] = a[p] + 1;
    f[p][2] = a[p] + 2;
    for (long long next: edges[p]) {
        if (next != last) {
            calc(next, p);
            f[p][0] = max(f[p][0], f[next][1]);
            f[p][1] = max(f[p][1], f[next][2]);
            f[p][2] = max(f[p][2], f[next][2]);
        }
    }
    //printf("p: %lld last: %lld, 0: %lld  1: %lld  2:%lld\n", p, last, f[p][0], f[p][1], f[p][2]);
}
void solve(long long p, long long last, long long pre) {
    //printf("p: %lld pre %lld \n", p, pre);
 
    long long t = max(a[p],pre);
    if (last != 0) {
        t = max(t, a[last] + 1);
        pre = max(pre, a[last] + 2);
    }
 
    multiset<long long> child;
    for (long long next: edges[p]) {
        if (next != last) {
            child.insert(f[next][2]);
            t = max(t, f[next][1]);
        }
    }
    //printf("* %lld *\n", t);
    ans = min(ans, t);
    for (long long next: edges[p]) {
        if (next != last) {
            long long nextPre = pre;
            child.erase(child.find(f[next][2]));
            if (child.size() > 0) {
                nextPre = max(nextPre, *prev(child.end()));
            }
            child.insert(f[next][2]);
            //printf("-- next: %lld nextpre %lld \n", next, nextPre);
            solve(next, p, nextPre);
        }
    }
}
int main()
{   
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (long long i = 1; i <= n-1; i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    calc(1, 0);
    ans = numeric_limits<long long>::max();
    solve(1, 0, MIN);
    cout << ans;
    return 0;
}