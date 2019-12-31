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
const long long MOD = 100000000007;
const long long M = 200100;
int n, m, q;
long long s, sqrts;
long long t0, t1, t2;
int a[M];
int f[M];
vector<int> diffEdge[M];
vector<int> sameEdge[M];
int main()
{   
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++) {
        int next = i + a[i];
        if (0 <= next && next < n) {
            if (a[i] % 2 == a[next] % 2) {
                sameEdge[next].push_back(i);
            } else {
                diffEdge[next].push_back(i);
            }
        }
        next = i - a[i];
        if (0 <= next && next < n) {
            if (a[i] % 2 == a[next] % 2) {
                sameEdge[next].push_back(i);
            } else {
                diffEdge[next].push_back(i);
            }
        }
    }
    deque<int> que;
    for (int i = 0; i < n ;i++) {
        for (int next: diffEdge[i]) {
            f[next] = 1;
            que.push_back(next);
        }
    }
    while (que.size() != 0) {
        int cur = que.front();
        que.pop_front();
        for (int next : sameEdge[cur]) {
            if (f[next] == 0) {
                f[next] = f[cur] + 1;
                que.push_back(next);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            printf("-1 ");
        } else {
            printf("%d ", f[i]);
        }
    }
    return 0;
}