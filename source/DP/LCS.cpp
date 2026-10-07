// dp[i][j] = a 前 i 個字元、b 前 j 個字元 的答案。index 0 = 空字串
const int MAXN = 3005;   // 5000x5000 int = 100MB 太大，注意記憶體
int dp[MAXN][MAXN];
string lcs(const string &a, const string &b) { // 最長共同子序列 (回傳字串)
    int n = a.size(), m = b.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    string res;
    for (int i = n, j = m; i > 0 && j > 0;) { // 回溯
        if (a[i - 1] == b[j - 1]) res += a[i - 1], i--, j--;
        else if (dp[i - 1][j] >= dp[i][j - 1]) i--;
        else j--;
    }
    reverse(res.begin(), res.end());
    return res; // 長度 = dp[n][m]
}
int edit_distance(const string &a, const string &b) { // 插入/刪除/取代 各 1 次
    int n = a.size(), m = b.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) { dp[i][j] = i + j; continue; }  // 全部插入/刪除
            dp[i][j] = min({dp[i - 1][j] + 1,                          // 刪 a[i-1]
                            dp[i][j - 1] + 1,                          // 插 b[j-1]
                            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])}); // 取代/相同
        }
    return dp[n][m]; // 輸出過程: 從 (n,m) 往回看是哪一項轉移來的
}
/* - 最長迴文子序列 = lcs(s, reverse(s)).size()；最少插入幾個字變迴文 = n - 它
   - 最長共同「子字串」(要連續): 相同時 dp = dp[i-1][j-1]+1，不同時 dp = 0，答案取全部最大
   - 只有插入/刪除 (沒有取代) 的距離 = n + m - 2 * LCS
   - 空間不夠: 只保留兩列 (dp[2][MAXN])，用 i & 1 */
