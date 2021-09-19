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
ll n;

ll bitSum(vector<ll> &BITree, ll index) 
{ 
    ll sum = 0; 
    index = index + 1; 
    while (index>0) { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void bitUpdate(vector<ll> &BITree, ll index, ll val) 
{ 
    index = index + 1; 
    while (index <= BITree.size()) { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
} 

int main() {
    /*
    int t;
    scanf("%d", &t);
    for(long long tt = 0; tt < t; tt++) {

    }*/
    scanf("%lld", &n);
    vector<ll> vs;
    vector<vector<ll>> a = vector<vector<ll>> (n, vector<ll>(2, 0));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i][1]);
        vs.push_back(a[i][1]);
    }
    sort(vs.begin(), vs.end());
    map<ll,ll> vMap;
    for (ll i = 0; i < vs.size(); i++) {
        vMap[vs[i]] = i;
    }
    sort(a.begin(), a.end());
    vector<ll> posTree = vector<ll>(n+100, 0);
    vector<ll> cntTree = vector<ll>(n+100, 0);
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll p = a[i][0];
        ll v = a[i][1];

        ll sumPos = bitSum(posTree, vMap[v]);
        ll sumCnt = bitSum(cntTree, vMap[v]);
        ans += p * sumCnt - sumPos;
        bitUpdate(posTree, vMap[v], p);
        bitUpdate(cntTree, vMap[v], 1);
    }
    cout << ans;
    return 0;
}