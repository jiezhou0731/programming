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
int n, m, t;
int pos[M];
int main()
{   
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        pos[t] = i;
    }
    int current = pos[1];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(pos[i] - current);
        current = pos[i];
    }
    cout << ans;
    return 0;
}