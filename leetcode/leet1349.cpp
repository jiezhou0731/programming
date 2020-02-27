class Solution {
public:

    int maxStudents(vector<vector<char>>& seats) {
        int f[15][1000];
        int n = seats.size();
        int m = seats[0].size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= pow(2, m); j++) {
                f[i][j] = -1;
            }
        }
        f[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= pow(2, m); j ++) {
                if (f[i-1][j] == -1) continue;
                int t[400];
                memset(t, 0, sizeof(t));
                t[0] = f[i-1][j];
                f[i][0] = max(f[i][0],t[0]);
                for (int k = 0; k <= pow(2, m); k++) {
                    for (int d = 1; d <= m; d++) {
                        if (seats[i-1][d-1] == '#') continue;
                        bool canPut = true;
                        if (k & (1 << (d-1))) canPut = false;
                        if (d > 1 && (k &(1 << (d - 2)))) canPut = false;
                        if (d < m && (k &(1 << (d)))) canPut = false;
                        if (d > 1 && (j &(1 << (d - 2)))) canPut = false;
                        if (d < m && (j &(1 << (d)))) canPut = false;
                        if (canPut) {
                            int nextState = k | (1 << (d - 1));
                            if (t[nextState] < t[k] + 1) {
                                t[nextState] = max(t[nextState], t[k] + 1); 
                                if (f[i][nextState] < t[nextState]) {
                                    f[i][nextState]  = t[nextState];
                                }
                            }
                        }
                    }
                }
            }
        }
                
        int ans = -1;
        for (int i = 0; i <= pow(2,m); i++) {
            ans = max(ans, f[n][i]);
        }
        return ans;
    }
};