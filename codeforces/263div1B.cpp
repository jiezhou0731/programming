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
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 200200;
long long MOD = 1000000007;
long long n, l , r, t;
vector<long long> ch[M];
long long f[M][4];// 0: nothing; 1: has it
bool x[M];
  
// C function for extended Euclidean Algorithm 
long long gcdExtended(long long a, long long b, long long *x, long long *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
long long modInverse(long long b, long long m) 
{ 
    long long x, y; // used in extended GCD algorithm 
    long long g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
long long modDivide(long long a, long long b, long long m) 
{ 
    a = a % m; 
    return (a * modInverse(b, m)) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long x1, y1; // To store results of recursive call 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
void solve(long long p) {
	for (long long c: ch[p]) {
		solve(c);
	}
	long long s = 1;
	for (long long c: ch[p]) {
		s = (s * (f[c][0] + f[c][1])) % MOD;
	}
	if (x[p]) {
		f[p][0] = 0;
		f[p][1] = s;
	} else {
		f[p][0] = s;
 
		f[p][1] = 0;
		for (long long c: ch[p]) {
			long long other = modDivide(s, (f[c][0] + f[c][1]), MOD);
			f[p][1] = (f[p][1] + f[c][1] * other) % MOD;
		}
	}
}
int main()
{   
	scanf("%lld", &n);
	memset(f, 0, sizeof(f));
	for (long long i = 1; i < n; i++) {
		scanf("%lld", &t);
		ch[t].push_back(i);
	}
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	solve(0);
	cout << f[0][1] % MOD;
    return 0;
}