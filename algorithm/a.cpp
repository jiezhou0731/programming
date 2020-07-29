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
 
// less_equal if supports multiple items
// order_of_key() find_by_order()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 10000100;
ll t,tt, n, m,x,y,q,l,r;
string s;
bool isNotPrime[M + 100];
vector<ll> prime;
void calcPrime(long long m) {
    memset(isNotPrime, 0, sizeof(isNotPrime));
    for (int i = 2; i <= m; i++) {
        if (isNotPrime[i] == false) {
            prime.push_back(i);
            ll x = i + i;
            while (x <= m) {
                isNotPrime[x] = true;
                x+=i;
            }
        }
    } 
}
//https://codeforces.com/problemset/problem/222/C
int main() {
    calcPrime(M);
    cin >> n >> m;
    map<int,int> f;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (auto j: prime) {
            while (x != 0 && x % j == 0) {
                f[j] ++;
                x /= j;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        for (auto j: prime) {
            while (x != 0 && x % j == 0) {
                f[j] --;
                x /= j;
            }
        }
    }
    vector<ll> ans0, ans1;
    ll current = 1;
    for (auto i: f) {
        if (i.second > 0) {
            //cout << "(" << i.first <<" " << i.second <<")";
            for (int j = 0; j < i.second; j++) {
                if (current * i.first < 10000000) {
                    current *= i.first;
                } else {
                    ans0.push_back(current);
                    current = i.first;
                }
            }
        }
    }
    ans0.push_back(current);
    current = 1;
    for (auto i: f) {
        if (i.second < 0) {
            //cout << "(" << i.first <<" " << i.second <<")";
            for (int j = 0; j < -i.second; j++) {
                if (current * i.first < 10000000) {
                    current *= i.first;
                } else {
                    ans1.push_back(current);
                    current = i.first;
                }
            }
        }
    }
    ans1.push_back(current);
    cout << ans0.size() << " " << ans1.size() << "\n";
    for (auto i: ans0) {
        cout << i <<" ";
    }
    cout <<"\n";
    for (auto i: ans1) {
        cout << i <<" ";
    }
    return 0;
}