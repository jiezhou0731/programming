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
const long long MOD = 100000000007;
const int M = 200100;
int n, m, t;
int mx, mi;
int t0, t1, t2;
pair<int, int> a[M];
bool removed[M];
tuple<int,int,int> sorted[M * 2];
multiset<pair<int, int>> current;
vector<int> ans;
int main()
{   
    memset(removed, 0, sizeof(removed));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t0 >> t1;
        a[i] = {t0, t1};
        sorted[2*i] = {t0, 0, i};
        sorted[2*i+1] = {t1, 1, i};
    }
    sort(sorted, sorted + 2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int dis = get<0> (sorted[i]);
        int typ = get<1> (sorted[i]);
        int ind = get<2> (sorted[i]);
        if (typ == 0) {
            current.insert({a[ind].second, ind});
            if (current.size() > m) {
                auto p = prev(current.end());
                int removedInd = p->second;
                current.erase(p);
                ans.push_back(removedInd);
                removed[removedInd] = true;
            }
        } else {
            if (removed[ind]) continue;
            current.erase(current.find({dis, ind}));
        }
    }
    printf("%d\n", ans.size());
    for (auto i: ans) {
        printf("%d ", i+1);
    }
 
    return 0;
}