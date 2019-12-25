#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
const long long MOD = 100000000007;
const long long M = 300100;
long long t,n;
int main()
{   
    long long red = 0;
    long long blue = 0;
    long long ans = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> t;
        if (i % 2 == 0) {
            red += (t+1) / 2;
            blue += t/2;
        } else {
            blue += (t+1) / 2;
            red += t/2;
        }
    }
    cout << min(blue, red);
    return 0;
}
