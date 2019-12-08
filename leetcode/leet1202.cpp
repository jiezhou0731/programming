const int M = 101000;

class Solution {
public:
    int uf[M];
    int n = 0;
    void combineUf(int x, int y) {
        int t0 = getUf(x);
        int t1 = getUf(y);
        uf[t0] = t1;
    }
    int getUf(int x) {
        if (x == uf[x]) return x;
        uf[x] = getUf(uf[x]);
        return uf[x];
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.size();
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
        for (int i = 0; i < pairs.size(); i++) {
            combineUf(pairs[i][0], pairs[i][1]);
        }
        vector<char> a[M];
        vector<int> b[M];
        for (int i = 0; i< n; i++) {
            cout << uf[i] << " ";
            a[getUf(i)].push_back(s[i]);
            b[getUf(i)].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            sort(a[i].begin(), a[i].end());
            for (int j = 0; j < a[i].size(); j++) {
                s[b[i][j]] = a[i][j];
            }
        }
        return s;
    }
};