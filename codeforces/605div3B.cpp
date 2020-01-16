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
int q;
string s;
int main()
{   
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
    	cin >> s;
    	map<char,int> cnt;
    	for (int j = 0; j < s.size(); j++) {
    		cnt[s[j]]++;
    	}
    	int h = min(cnt['L'], cnt['R']);
    	int v = min(cnt['U'], cnt['D']);
        if (v == 0) {
            h = min(h, 1);
        }
        if (h == 0) {
            v = min(v, 1);
        }
    	cout << 2*(h + v)<< "\n";
    	for (int j = 0; j < h; j++) {
    		cout << "L";
    	}
    	for (int j = 0; j < v; j++) {
    		cout << "U";
    	}
    	for (int j = 0; j < h; j++) {
    		cout << "R";
    	}
    	for (int j = 0; j < v; j++) {
    		cout << "D";
    	}
    	cout <<"\n";
    }
 
    return 0;
}