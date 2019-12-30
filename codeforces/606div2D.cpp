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
const int M = 200100;
int n, m, q;
int t, t0, t1, t2;
string s,sr;
int c[5];
int main()
{   
    memset(c, 0, sizeof(c));
    cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
        cin >> n;
        set<int> a[4];
        map<string,int> appear[4];
        memset(c,0,sizeof(c));
        for (int i = 1; i <= n; i++) {
            cin >> s;
            sr = s;
            reverse(sr.begin(), sr.end());
            int x = (int)(s[0]-'0')*2+(int)(s[(int)s.size() - 1] -'0');
            int y = x % 2 + 1;
            c[x] ++;
            if ( x == 1 || x == 2) {
                if (appear[y].find(sr) != appear[y].end()) {
                    a[y].erase(appear[y][sr]);
                } else {
                    appear[x][s] = i;
                    a[x].insert(i);
                }
            }
        }
        if (c[1] == 0 && c[2] == 0) {
            if (c[0] > 0 && c[3] > 0) {
                cout << "-1" <<"\n";
            } else {
                cout << "0" <<"\n";
            }
        } else {
            vector<int> ans;
            int b = 2;
            int s = 1;
            if (c[1] > c[2]) {
                b = 1;
                s = 2;
            }
            for (auto u: a[b]) {
                if (c[b] - c[s] <= 1) break;
                ans.push_back(u);
                c[b] --;
                c[s] ++;
            }
            if (c[b] - c[s] <= 1) {
                cout << ans.size()<<"\n";
                for (auto j: ans) printf("%d ", j);
                cout <<"\n";
            } else {
                cout << "-1\n";
            }
            
        }
    }
    return 0;
}