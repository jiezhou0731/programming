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
const long long M = 2*pow(10, 5)+100;
string s;
void calcL(string &s) {
    if (s.size() == 0) return;
    int lps[10000];    
    memset(lps, 0, sizeof(lps));
    int center = 0;
    for (int currentRight = 1; currentRight <= s.size() * 2; currentRight ++) {
        int centerRight = center + lps[center];
        int currentLeft = 2 * center - currentRight;
        int diff = centerRight - currentRight;
        if (diff > 0) {
            lps[currentRight] = min(diff, lps[currentLeft]);
        } 
        int expandLeft = currentRight - lps[currentRight] - 1;
        int expandRight = currentRight + lps[currentRight] + 1;
        while (expandLeft >= 0 && expandRight <= 2*s.size()
                && (expandLeft % 2 == 0 
                || (expandLeft % 2 == 1 && s[expandLeft/2] == s[expandRight/2]))) {
            lps[currentRight] ++;
            expandLeft--;
            expandRight++;
        }
        if (lps[currentRight] + currentRight > centerRight) {
            center = currentRight;
            centerRight = lps[currentRight] + currentRight;
        }
    }
}
int main()
{   
    cin >> s;
    calcL(s);
    return 0;
}
