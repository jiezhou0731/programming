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
 
int bitSum(vector<int> &BITree, int index) 
{ 
    int sum = 0; 
    index = index + 1; 
    while (index>0) { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void bitUpdate(vector<int> &BITree, int index, int val) 
{ 
    index = index + 1; 
    while (index <= BITree.size()) { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
} 

int main() 
{ 
    vector<int> tree = vector<int>(100, 0);
    bitUpdate(tree, 2, 3);
    bitUpdate(tree, 3, 6); 
    cout << bitSum(tree, 5); 
  
    return 0; 
} 