#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF =1.5e7 + 10;
const long long M = 2*pow(10,6);
const ll MOD = pow(10,9)+7;
int n, m , t, x,y,z,d,tt,q,k,current, last;
string s;
int main() {
    while (true) {
        cin >> current >> last;
        cout << current / ((last - current)/8);
    }
    return 0;
}