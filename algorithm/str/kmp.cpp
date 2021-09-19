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
#define ll long long
 

// longest prefix which is also suffix
// 01012012345
// AABAACAABAA
vector<int> computeLPSArray(string &pat)
{
    int m = pat.size();
    vector<int> lps = vector<int>(m, 0);
    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMPSearch(string &pat, string &txt)
{
    int m = pat.size();
    int n = txt.size();
  
    vector<int> lps = computeLPSArray(pat);
  
    int i = 0; // index for txt
    int j = 0; // index for pat
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == m) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i = i + 1;
            }
        }
    }
}
 
  
// Driver program to test above function
int main()
{
    string txt = "ABAABAACAABAAAAB";
    string pat = "AABAACAABAA";
    vector<int> lps = computeLPSArray(pat);
    for (auto i: lps) {
        printf("%d",i);
    }
    printf("\n");
    KMPSearch(pat, txt);
    return 0;
}