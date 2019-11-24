#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace std;

const int M = 1000;
string s;
map<char, int> samNext[M];
int samLink[M];
int samLen[M];
int samN = 1;
int samLast = 0;
void extends(char c) {
    int cur = samN++;
    samLen[cur] = samLen[samLast] + 1;
    int p = samLast;
    while (p != -1) {
        if (samNext[p][c] == 0) {
            samNext[p][c] = cur;
            p = samLink[p];
        } else {
            int q = samNext[p][c];
            if (samLen[q] == samLen[p] + 1) {
                samLink[cur] = q;
            } else {
                int clone = samN ++;
                samLink[clone] = samLink[q];
                samNext[clone] = samNext[q];
                samLen[clone] = samLen[q] + 1;
                while (p != -1) {
                    samNext[p][c] = clone;
                    p = samLink[p];
                }
                samLink[q] = samLink[cur] = clone;
            }
            break;
        }
    }
    samLast = cur;
}
void traverse(int p) {
    printf("Node: %d, link: %d, len: %d, [", p, samLink[p], samLen[p]);
    for (char c = 'a'; c <='z'; c++) {
        if (samNext[p][c] != 0) {
            printf("(%c %d) ", c, samNext[p][c]);
        }
    }
    printf("]\n");
}
int main()
{   
    memset(samLink, 0, sizeof(samLink));
    memset(samLen, 0, sizeof(samLen));
    samLink[0] = -1;
    cin >> s;
    for (char c: s) {
        extends(c);
    }
    for (int i = 0; i < samN; i++)
        traverse(i);
    return 0;
}
