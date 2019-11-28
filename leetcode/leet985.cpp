class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int s = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0)
                s += A[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            if (A[queries[i][1]] % 2== 0) {
                s -= A[queries[i][1]];
            }
            A[queries[i][1]] += queries[i][0];
            if (A[queries[i][1]] % 2== 0) {
                s += A[queries[i][1]];
            }
            ans.push_back(s);
        }
        return ans;
    }
};