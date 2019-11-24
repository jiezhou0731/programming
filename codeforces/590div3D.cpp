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
const long long M = pow(2,17);
int n, t, l, r, q, p;
string s;
char c;
int seg[M*2+10][28];
void updateSeg(int p, int c0, int c1) {
    seg[p][c0] ++;
    seg[p][c1] --;
    if (p != 0)
        updateSeg((p-1)/2, c0, c1);
}
void querySeg(int p, int ans[], int cL, int cR, int l, int r) {
    if (cR < l || r < cL || cL > cR) {
        return;
    }
    if (l <= cL && cR <= r) {
        for (int j = 0; j < 27; j++) {
            ans[j] += seg[p][j];
        }
        return;
    } 
    
    querySeg(p*2+1, ans, cL, (cL + cR)/2, l, r);
    querySeg(p*2+2, ans, (cL + cR)/2+1, cR, l, r);
}
int main()
{   
    memset(seg, 0, sizeof(seg));
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        updateSeg(M-1+i,s[i]-'a',27);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %c",&p, &c);
            p --;
            if (s[p] != c) {
                updateSeg(M-1+p, c-'a', s[p]-'a');
                s[p] = c;
            }
        } else {
            scanf("%d %d", &l, &r);
            l --;
            r --;
            int ans[27];
            memset(ans, 0, sizeof(ans));
            querySeg(0, ans, 0, M-1, l, r);
            int x = 0;
            for (int j = 0; j < 26; j++) {
                if (ans[j]) x++;
            }
            printf("%d\n", x);
        }
    }
    
    return 0;
}