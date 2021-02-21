void lcp(string st, vector<vector<int>> &dp) {
    for (int i = 0; i < st.length(); i++)
        dp[i][i] = 1;
    for (int i = st.length() - 1; i >= 0; i--)  {
        for (int j = i + 1; j < st.length(); j++) {
            if (st[i] == st[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
}
int longestPalindrome(string w1, string w2) {
    int n = w1.size(), m = w2.size(), res = 0;

    vector<vector<int>> dp(n + m + 1, vector<int>(n + m + 1, 0));
    lcp(w1 + w2, dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (w1[i] == w2[j]) 
                res = max(res, dp[i][n + j]);
        }
    }
    return res;        
}