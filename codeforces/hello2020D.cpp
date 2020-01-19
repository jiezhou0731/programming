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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 
//const int MOD = 100000000007;
const long long INF = pow(2, 25);
const long long M = 100200;
long long MOD = pow(10, 9) + 7;
int n;
int ind[M][5];
bool check(int sa, int ea, int sb, int eb) {
    vector<tuple<int,int,int>> sorted;
    for (int i = 0; i < n; i++) {
        sorted.push_back({ind[i][sa], 0, i});
        sorted.push_back({ind[i][ea], 1, i});
    }
    sort(sorted.begin(), sorted.end());
    multiset<int> sbSet;
    multiset<int> ebSet;
    for (int i = 0; i < sorted.size(); i++) {
        int index = get<2>(sorted[i]);
        int typ = get<1>(sorted[i]);
        if (typ == 0) {
            sbSet.insert(ind[index][sb]);
            ebSet.insert(ind[index][eb]);
            if (*prev(sbSet.end()) > *(ebSet.begin())) {
                return false;
            }
        } else {
            sbSet.erase(sbSet.find(ind[index][sb]));
            ebSet.erase(ebSet.find(ind[index][eb]));
        }
    }
    return true;
}
int main()
{   
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &ind[i][j]);
        }
    }
    bool ans = min(check(0, 1, 2, 3), check(2,3,0,1));
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}