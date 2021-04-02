#define PI 3.14159265
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const long long MOD = 100000000007;
const long long INF =1.5e7 + 10;
const long long M = 2*pow(10,6);
const ll MOD = pow(10,9)+7;

// in: x,y in axis
// out: degree
double getAngle(int x, int y) {
	return atan2(y, x) * 180 / PI;
}
int main() {
	// 0
    cout << getAngle(0,0) <<"\n";

    // 0
    cout << getAngle(2,0) <<"\n";

	// 26 degree
    cout << getAngle(2,1) <<"\n";

	// 90
    cout << getAngle(0,1) <<"\n";    

    // 153 degree
    cout << getAngle(-2,1) <<"\n";

    // -153 degree
    cout << getAngle(-2,-1) <<"\n";

	// -26 degree
    cout << getAngle(2,-1) <<"\n";
    return 0;
}

