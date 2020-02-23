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
const long long M = 100500;
vector<int> w[M];
int n,m,x,y;
int f[M];
int cCnt[M];
int first[M];
int checked[M];
vector<int> ans;
bool inAns[M];
void out(int p) {
    for (int next: w[p]) {
        out(next);
    }
    if (first[p] == p)
        ans.push_back(p);
}
int main() {
    memset(f, 0, sizeof(f));
    memset(cCnt, 0, sizeof(cCnt));
    memset(inAns, 0, sizeof(inAns));
    memset(first, 0, sizeof(first));
    memset(checked, 0, sizeof(checked));
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        w[x].push_back(y);
        f[y] = x;
        cCnt[x] ++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> first[i];
    }
    for (int i = 1; i <= n; i++) {
        if (cCnt[i] == 0) {
            int p = i;
            while (p != 0) {
                if (checked[p]) break;
                int fa = f[p];
                if (first[fa] != first[p] && first[p] != p) {
                    printf("-1");
                    return 0;
                }  
                checked[p] = true;
                p = fa;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0)
            out(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
}