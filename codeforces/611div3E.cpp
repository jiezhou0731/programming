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
bool ocMin[M];
bool ocMax[M];
int cnt[M];
int main()
{   
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        cnt[t] += 1;
    }
    memset(ocMin, 0, sizeof(ocMin));
    memset(ocMax, 0, sizeof(ocMax));
    int cMin = 0;
    int cMax = 0;
    for (int i = 1; i <= n; i++) {
        // For min
        if (cnt[i] > 0) {
            if (ocMin[i-1] || ocMin[i]) {
            } else {
                ocMin[i+1] = true;
                cMin ++;
            }
        }
        // For max
        for (int p = i-1; p <= i+1; p++) {
            if (cnt[i] > 0 && ocMax[p] == false) {
                ocMax[p] = true;
                cnt[i] --;
                cMax ++;
            }
        }
    }
    cout << cMin <<" " << cMax;
    
    return 0;
}