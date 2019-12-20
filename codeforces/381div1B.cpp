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
long long t0, t1, n;
long long a[M];
vector<pair<long long,long long>> edge[M];
long long parent[M];
long long cnt[M];
vector<pair<long long,long long>> so;
long long search(long long p, long long dist) {
    auto t = lower_bound(so.begin(), so.end(), make_pair((long long)dist - a[p],(long long)-1));
    if (t != so.end()) {
        cnt[parent[t->second]] --;
        cnt[parent[p]] ++;
    }
    so.push_back({dist, p});
    for (auto next: edge[p]) {
        cnt[p] += search(next.first, dist + next.second);
    }
    so.pop_back();
    return cnt[p];
}
int main()
{   
    memset(cnt, 0,sizeof(cnt));
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (long long i = 2; i <= n; i++) {
        cin >> t0 >> t1;
        edge[t0].push_back({i,t1});
        parent[i] = t0;
    }
    search(1, 0);
    for (long long i = 1; i <= n; i++) {
        cout << cnt[i] <<" ";
    }
    return 0;
}