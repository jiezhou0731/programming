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
struct Node {
    vector<Node*> next = vector<Node*>(2, NULL);
};
int M = 20;
class Solution {
public:
   
};
int main()
{
     vector<int> a = {-1,0,1,1};
     vector<vector<int>> b = {{0,2}, {3,2},{2,5}};
     Solution *solu = new Solution();
     solu->maxGeneticDifference(a, b);

     return 0;
}
