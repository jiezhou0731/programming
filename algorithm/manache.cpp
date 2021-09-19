#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace std;

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

        // Expand based on current lps
        int expandLeft = currentRight - lps[currentRight] - 1;
        int expandRight = currentRight + lps[currentRight] + 1;
        while (expandLeft >= 0 && expandRight <= 2*s.size()
                && (expandLeft % 2 == 0 
                || (expandLeft % 2 == 1 && s[expandLeft/2] == s[expandRight/2]))) {
            lps[currentRight] ++;
            expandLeft--;
            expandRight++;
        }

        // Update center right
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
