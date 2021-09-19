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
class LandSplitter {
    public:
    long long cheapest(int N, int A, int B) {
        long long n = N;
        long long a = A;
        long long b = B;
        for (long long t = 1; t * A <= N; t ++) {
            
        }
    }
};
int main()
{
     vector<long long> a = {-1,0,1,1};
     vector<vector<long long>> b = {{0,2}, {3,2},{2,5}};
     LandSplitter solu = LandSplitter();
     solu.cheapest(12, 3, 3);
     return 0;
}