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
const long long INF = pow(2, 25);
const long long M = 200500;
vector<int> w[M];
vector<pair<int,int>> edges;
int color[M];
bool valid = true;
int n, m, x, y;
void dfs(int p, int current) {
    if (color[p] > 0) {
        if (color[p] != current) {
            valid = false;
        }
        return;
    }
    color[p] = current;
    int nextColor = current % 2 + 1;
    for (int next: w[p]) {
        dfs(next, nextColor);
    }
}
int main() {
    memset(color, 0, sizeof(color));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        w[x].push_back(y);
        w[y].push_back(x);
        edges.push_back({x,y});
    }
    dfs(1, 1);
    if (valid) {
        printf("YES\n");
        for (int i = 0; i < m; i++) {
            x = edges[i].first;
            y = edges[i].second;
            if (color[x] == 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
    } else {
        printf("NO");
    }
    return 0;
}