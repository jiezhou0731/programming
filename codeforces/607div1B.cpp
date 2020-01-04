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
long long n, m, t;
int main()
{   
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        string s = "";
        bool state[10];
        memset(state, 0, sizeof(state));
        state[0] = true;
        bool cHasP[70];
        bool rHasP[70];
        memset(cHasP, 0, sizeof(cHasP));
        memset(rHasP, 0, sizeof(rHasP));
 
        for (int j = 0; j < r; j++) {
            cin >> s;
            if (j == 0 || j == r -1) {
                if (s[0] == 'A' || s[c-1] == 'A') {
                    state[2] = true;
                }
                for (int t = 0; t < c; t++) {
                    if (s[t] == 'A') {
                        state[3] = true;
                    }
                }
            }
            for (int t = 0; t < c; t++) {
                if (s[t] == 'A') {
                    state[4] = true;
                } else {
                    state[0] = false;
                    cHasP[t] = true;
                    rHasP[j] = true;
                }
            }
            if (s[0] == 'A' || s[c-1] == 'A') {
                state[3] = true;
            }
        }
        if (!cHasP[0] || !cHasP[c-1] || !rHasP[0] || !rHasP[r-1]) {
            state[1] = true;
        }
        for (int j = 1; j < r-1; j++) {
            if (!rHasP[j]) state[2] = true;
        }
        for (int j = 1; j < c-1; j++) {
            if (!cHasP[j]) state[2] = true;
        }
        for (int j = 0; j <= 5; j++) {
            if (state[j]) {
                printf("%d\n", j);
                break;
            }
            if (j == 5) {
                printf("MORTAL\n");
            }
        }
    }
    return 0;
}