#include <bits/stdc++.h>
using namespace std;
  

int crossProduct(pair<int,int> O, pair<int,int> A, pair<int,int> B) {
    return (A.first - O.first) * (B.second - O.second)
           - (A.second - O.second) * (B.first - O.first);
}
  
vector<pair<int,int>> getConvexHull(vector<pair<int,int>> &A)
{
    int n = A.size(), k = 0;
    if (n <= 3)
        return A;
    vector<pair<int,int>> ans;
    sort(A.begin(), A.end());
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && crossProduct(ans[k - 2], 
                          ans[k - 1], A[i]) <= 0) {
            k--;
            ans.pop_back();
        }
        k++;            
        ans.push_back(A[i]);
    }
    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {
        while (k >= t && crossProduct(ans[k - 2],
                           ans[k - 1], A[i - 1]) <= 0) {
            k--;
            ans.pop_back();   
        }
        k++;            
        ans.push_back(A[i-1]);       
    }
    ans.pop_back();
    return ans;
}

int main()
{
    vector<pair<int,int>> s;
  
    // Add pair<int,int>s
    s.push_back({ 0, 3 });
    s.push_back({ 2, 2 });
    s.push_back({ 1, 1 });
    s.push_back({ 2, 1 });
    s.push_back({ 3, 0 });
    s.push_back({ 0, 0 });
    s.push_back({ 3, 3 });
  
    // Find the convex hull
    vector<pair<int,int>> ans = getConvexHull(s);
  
    // Print the convex hull
    for (int i = 0; i < ans.size(); i++)
        cout << "(" << ans[i].first << ", " 
             << ans[i].second << ")" << endl;
  
    return 0;
}