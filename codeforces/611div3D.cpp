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
const long long M = 200100;
long long n, m, t;
vector<long long> ans;
long long ctree[M];
int main()
{   
    scanf("%lld %lld", &n, &m);
    set<long long> occupied;
    deque<pair<long long, long long>> que;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &ctree[i]);
        occupied.insert(ctree[i]);
    }
    for (long long i = 0; i < n; i++) {
        long long t = ctree[i];
        if (occupied.find(t+1) == occupied.end()) {
            occupied.insert(t+1);
            que.push_back({t+1, 1});
        }
        if (occupied.find(t-1) == occupied.end()) {
            occupied.insert(t-1);
            que.push_back({t-1,1});
        }
    }
    for (long long i = 0; i < m; i++) {
        long long t = que.front().first;
        long long d = que.front().second;
        que.pop_front();
        ans.push_back(t);
        sum += d;
        if (occupied.find(t+1) == occupied.end()) {
            occupied.insert(t+1);
            que.push_back({t+1, d+1});
        }
        if (occupied.find(t-1) == occupied.end()) {
            occupied.insert(t-1);
            que.push_back({t-1, d+1});
        }
    }
    printf("%lld\n", sum);
    for (auto i: ans) {
        printf("%lld ", i);
    }
 
    return 0;
}