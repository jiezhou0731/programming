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
string s;
map<char,int> cnt;
string ans[1010];
int l,k;
void findKthWord() {
    int t = 1;
    char c = 'a';
    while (c <= 'z') {
        if (cnt[c] > k - t) {
            for (int i = t; i <= k; i++) {
                ans[i] += c;
            }
            cnt[c] -= k - t + 1;
            if (ans[k].size() == l) return;
        } else if (cnt[c] > 0) {
            for (int i = t; i < t+cnt[c]; i++) {
                ans[i] += c;
            }
            t += cnt[c];
            cnt[c] = 0;
        } else if (cnt[c] == 0) {
            c++;
        }
    }
}
int main()
{   
    scanf("%d %d %d", &n, &l, &k);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
    }
    findKthWord();
    char c = 'z';
    for (int j = 0; j < l; j++) {
        for (int i = n; i > k; i--) {
            while (cnt[c] == 0) c--;
            ans[i] += c;
            cnt[c] --;
        }
    }
    for (int i = k-1; i >= 1; i--) {
        while (ans[i].size() != l) {
            while (cnt[c] == 0) c--;
            ans[i] += c;
            cnt[c] --;   
        }
    }
 
    for (int i = 1; i <= n; i++) {
        cout << ans[i] <<"\n";
    }
 
    return 0;
}