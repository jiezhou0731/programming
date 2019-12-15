#include <bits/stdc++.h>
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const long long MOD = 100000000007;
#define M 200500
int n, t, l, r, q, p;
int f[M][3];
int k[10];
int pos[M];
int main()
{   
    n = 0;
    for (int i = 0; i < 3; i++) {
        cin >> k[i];
        n += k[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <k[i]; j++) {
            cin >> t;
            pos[t] = i;
        }
    }
    f[0][0] = 0;
    f[0][1] = 0;
    f[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (pos[i] == j) {
                if (j == 0) {
                    f[i][j] = f[i-1][0];
                } else if (j == 1) {
                    f[i][j] = min(f[i-1][0], f[i-1][1]);
                } else if (j == 2) {
                    f[i][j] = min(f[i-1][2], min(f[i-1][0], f[i-1][1]));
                }
            } else {
                if (j == 0) {
                    f[i][j] = f[i-1][0] + 1;
                } else if (j == 1) {
                    f[i][j] = min(f[i-1][0], f[i-1][1]) + 1;
                } else if (j == 2) {
                    f[i][j] = min(f[i-1][2], min(f[i-1][0], f[i-1][1])) + 1;
                }
            }
            printf("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }
    int ans = M;
    for (int i = 0; i < 3; i++) 
        ans = min(f[n][i], ans);
    cout << ans;
   
    return 0;
}