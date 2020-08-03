#define N 124
class Solution {
public:
    int dp[N][N];
    int len(int num) {
        if (num == 0) return 0;
        else if (num == 1) return 1;
        else if (num < 10) return 2;
        else if (num < 100) return 3;
        return 4;
    }
    int solve(string &s, int n, int k) {
        if (n <= 0) return 0;
        if (n <= k) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        int res = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++) {
            int remains = k, cnt = 0;
            for (int j = n; j > 0; j--) {
                if (s[j] == c) cnt++;
                else if (--remains < 0) break ;
                int prefix = solve(s, j - 1, remains);
                int curs = prefix + len(cnt);
                res = min(res, curs);
            }
        }
        return dp[n][k] = res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        for (int i = 0; i < N; i++) 
            memset(dp[i], -1, N * sizeof(int));
        string t = " " + s;
        return solve(t, s.size(), k);
    }
};