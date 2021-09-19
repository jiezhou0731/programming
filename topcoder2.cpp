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
class ThreeDigits {
public:
	int MOD;
   long long  power(long long x, long long  int y, long long MOD)
    {
        long long temp;
        if( y == 0)
            return 1;
        temp = power(x, y / 2, MOD);
        if (y % 2 == 0)
            return temp * temp%MOD;
        else
            return x * temp * temp%MOD;
    }


	string calculate(int X, int Y, int Z) {
		double l = power(X, Y, 100000000)/Z;
		double r = power(X, Y, Z) * 1.0/ Z;
		string sl = to_string((long long)l);
		string sr = to_string((long long)round(r * 1000));
		cout << sl + "." + sr;
		return  sl + "." + sr;
	}
};

int main()
{

     vector<long long> a = {-1,0,1,1};
     vector<vector<long long>> b = {{0,2}, {3,2},{2,5}};
     ThreeDigits solu = ThreeDigits();
     cout << solu.calculate(4, 7 ,32);
     return 0;
}
