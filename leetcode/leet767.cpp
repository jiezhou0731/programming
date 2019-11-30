class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        map<char, int> cnt;
        for (char c: S) {
            cnt[c] ++;
        }
        vector<pair<int,char>> a;
        for (auto i: cnt) {
            a.push_back({i.second, i.first});
        }
        int p = 0;
        sort(a.begin(), a.end());
        string b = "";
        for (int i = 0; i < n; i++) {
            b=b+" ";
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = 0; j < a[i].first; j++) {
                b[p] = a[i].second;
                p+=2;
                if (p >= n) {
                    p = 1;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (b[i] == b[i-1]) return "";
        }
        return b;
    }
};