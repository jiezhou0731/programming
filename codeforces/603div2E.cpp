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
const long long M = pow(2, 20);
long long n, m;
string o;
long long t, t0, t1, t2;
// sum, min, max
long long seg[3][M * 2 + 100];
void pushUp(long long p) {
    seg[0][p] = seg[0][p*2+1] + seg[0][p*2+2];
    seg[1][p] = min(seg[1][p*2+1], seg[0][p*2+1]+seg[1][p*2+2]);
    seg[2][p] = max(seg[2][p*2+1], seg[0][p*2+1]+seg[2][p*2+2]);
 
    if (p != 0) pushUp((p-1)/2);
}
void update(long long p, long long v) {
    int t = p + 1 + M;
    if (t == v) return;
    for (int i = 0; i < 3; i++) {
        seg[i][t] = v;    
    }
    pushUp((t-1)/2);
}
int main()
{   
    for (int i = 0; i < M * 2; i++) {
        seg[0][i] = 0; 
        seg[1][i] = INF;
        seg[2][i] = -INF;
    }
    seg[1][0] = 0;
    seg[2][0] = 0;
    long long p = 0;
    scanf("%lld", &n);
    cin >> o;
    for (int i = 0; i < o.size(); i++) {
        if (o[i] == 'R') {
            p ++;
        } else if (o[i] == 'L') {
            p --;
            if (p < 0) p = 0;
        } else if (o[i] == '(') {
            update(p, 1);
        } else if (o[i] == ')') {
            update(p, -1);
        } else {
            update(p, 0);
        }
        if (seg[0][0] == 0 && seg[1][0] >= 0) {
            printf("%lld ", seg[2][0]);
        } else {
            printf("-1 ");
        }
        
    }
    return 0;
}
