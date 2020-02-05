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
const long long M = 500200;
long long MOD = 1000000007;
long long e[5];
long long k, n;
long long ans = 1;
long long count(long long x) {
    if (x > n) {
        return 0;
    } if (x == n) {
        return 1;
    }
    long long s = 0;
    long long r = (x%2)? x : (x+1);
    long long l = 1;
    while (r <= n) {
        if (x % 2 == 1) {
            s += l;
            l *= 2;
            r = l * x + l - 1;      
        } else {
            s += 2 * l;
            l *= 2;
            r = l * x + l * 2 - 1;
        }
    }
    if (x % 2 == 1) {
        s += max((l - (r - n)),(long long)0);
    } else {
        s += max((2 * l - (r - n)),(long long)0);
    }
    return s;
}
int main()
{   
    cin >> n >> k;
    if (n % 2 == 0) {
        e[1] = n - 1;
        e[0] = n;
    } else {
        e[1] = n;
        e[0] = n - 1;
    }
    for (int i = 0; i <= 1; i++) {
        long long l = i;
        long long r = e[i];
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            if (mid % 2 != i) {
                mid ++;
            }
            if (count(mid) >= k) {
                l = mid;
            } else {
                r = mid - 2;
            }
        }
        ans = max(ans, l);
    }
    cout << ans;
    return 0;
}