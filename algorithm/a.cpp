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
#define ll long long
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 200100;
ll t,tt, n, m,x,y,q,l,r;
dataSet has;
int b[M];
int ans;
//https://codeforces.com/problemset/problem/1172/A
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        has.insert(x);
    }
    ans = 0;
    int suf = -1;
    int sufCnt = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (has.order_of_key(n - i) >= n - i) {
            ans += n;
            break;
        }

        cin >> x;
        if (x == 0 || x == 1) {
            suf = x;
            sufCnt = 1;
        }
        if (suf > 0) {
            if (x == suf + 1) {
                suf ++;
                sufCnt ++;
            } else {
                suf = -1;
                sufCnt = 0;
            }
        }
    }
    cout << i <<" +"<< n <<"-" << sufCnt;


    return 0;
}