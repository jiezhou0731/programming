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
long long total[M];
int n, m;
long long t0, t1, t2;
vector<pair<long long,int>> pos, neg;
vector<tuple<int,int,long long>> ans;
int main()
{   
    memset(total, 0, sizeof(total));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t0 >> t1 >> t2;
        total[t0] -= t2;
        total[t1] += t2;
    }
    for (int i = 1; i <= n; i++) {
        if (total[i] > 0) {
            pos.push_back({total[i], i});
        } else if (total[i] < 0) {
            neg.push_back({-total[i], i});
        }
    }
    if (pos.size() == 0) {
        cout << 0;
        return 0;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int i = pos.size()-1;
    int j = neg.size()-1;
    while (i >= 0 || j >= 0) {
        long long t = min(pos[i].first, neg[j].first);
        pos[i].first -= t;
        neg[j].first -= t;
        if (t > 0)
            ans.push_back({neg[j].second, pos[i].second, t});
        if (pos[i].first == 0) i--;
        if (neg[j].first == 0) j--;
    }
    cout << ans.size()<<"\n";
    for (auto i: ans) {
        cout << get<0>(i)<< " " << get<1>(i) << " "<< get<2>(i)<<"\n";
    }
    return 0;
}