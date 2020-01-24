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
const long long M = 300200;
long long MOD = 1000000007;
long long n, l , r, t, m;
vector<pair<int,int>> valid;
int a[M][9];
int all1 = 1;
pair<int,int> check(int mid) {
	map<int,int> exist;
	for (int i = 1; i <= n; i++) {
		int stat = 0;
		for (int j = 0; j < m; j++) {
			int current = 0;
			if (a[i][j] >= mid) {
				current = 1;
			} 
			stat = (stat << 1) | current;
		}
		exist[stat] = i;
	}
	for (auto i: valid) {
		if (exist[i.first] > 0 && exist[i.second] > 0) {
			return {exist[i.first], exist[i.second]};
		}
	}
	return {-1,-1};
}
int main()
{   
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 2; i <= m; i++) {
		all1 = (all1 << 1) | 1;
	}
	for (int i = 0; i <= all1; i++) {
		for (int j = i; j <= all1; j++) {
			if ((i|j) == all1) 
				valid.push_back({i,j});
		}
	}
	int left = 0;
	int right = pow(10, 9);
	int mid = (left + right + 1) / 2;
	pair<int,int> ans;
	while (left < right) {
		mid = (left + right + 1) / 2;
		ans = check(mid);
		if (ans.first == -1) {
			right = mid - 1;
		} else {
			left = mid;
		}
	}
	ans = check((left + right + 1) / 2);
	
	cout << ans.first <<" " << ans.second;
    return 0;
}