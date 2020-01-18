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
const long long M = 100200;
long long t;
long long n;
long long search(set<long long> &a, long long pos) {
	if (pos == 0) return 0;
	set<long long> s0, s1;
	long long mask = 1 << (pos-1);
	for (long long i: a) {
		if ((mask & i) == 0) {
			s0.insert(i);
		} else {
			s1.insert(i);
		}
	}
	if (s0.size() == 0) {
		return search(s1, pos - 1);
	}
	if (s1.size() == 0) {
		return search(s0, pos - 1);
	}
	return (1 << (pos-1)) + min(search(s0, pos - 1), search(s1, pos - 1));
}
int main()
{   
    scanf("%lld", &n);
    set<long long> a;
    for (int i = 0; i < n; i++) {
    	scanf("%lld", &t);
    	a.insert(t);
    }
    cout << search(a, 30);
 
    return 0;
}