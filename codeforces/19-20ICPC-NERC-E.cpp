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
const long long M = 200;
int n, m, t;
int a[M][M];
int s[M];
int main()
{   
    memset(s, 0, sizeof(s));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            s[j] += a[i][j];
        }
    }
    int ans = M;
    vector<int> ansA;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        int x = s[n] - s[i];
        vector<pair<int,int>> diff;
        for (int j = 1; j <= m; j++) {
            if (a[j][i] < a[j][n]) {
                diff.push_back({a[j][n] - a[j][i], j});
            }
        }
        sort(diff.begin(), diff.end());
        while (x > 0) {
            x -= diff[diff.size() - 1 - cnt].first;
            cnt ++;
        }
        if (ans > cnt) {
            ans = cnt;
            ansA.clear();
            for (int i = (int)diff.size()- 1; i>= (int)diff.size() - cnt; i--) {
                ansA.push_back(diff[i].second);
            }
        }
    }
    printf("%d\n", ans);
    for (int i: ansA) {
        printf("%d ", i);
    }
 
    return 0;
}