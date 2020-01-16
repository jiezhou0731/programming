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
const long long M = 200020;
int n, m, k, q;
int a[M];
int t[M], l[M], r[M];
int main()
{   
    scanf("%d %d %d", &n, &q, &m);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    }
    for (int i = 1; i <= q; i++) {
    	scanf("%d %d %d", &t[i], &l[i], &r[i]);
    }
    for (int i = 1; i <= m; i++) {
    	scanf("%d", &k);
    	for (int j = q; j >= 1; j--) {
    		if (l[j] <= k && k <= r[j]) {
    			if (t[j] == 2) {
    				k = r[j] + l[j] - k;
	    		} else {
	    			if (k == l[j]) {
	    				k = r[j];
	    			} else {
	    				k--;
	    			}
	    		}
    		}
    		
    	}
    	printf("%d ", a[k]);
    }
 
    return 0;
}