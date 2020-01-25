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
int n, l , r, t, m, current;
vector<int> edge[M];
pair<int,int> ans[M];
void search(int p, int last) {
	//printf("%d:\n", p);
	for (int i = 0; i < edge[p].size(); i++) {
		if (last != edge[p][i]) {
			current ++;
			ans[edge[p][i]].first = current;	
		}
	}
	current ++;
	ans[p].second = current;
	for (int i = edge[p].size() - 1; i >= 0; i--) {
		if (last != edge[p][i]) {
			search(edge[p][i], p);
		}
	}
}
int main()
{   
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &l, &r);
		edge[l].push_back(r);
		edge[r].push_back(l);
	}
	current = 1;
	ans[1].first = 1;
	search(1, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
 
    return 0;
}