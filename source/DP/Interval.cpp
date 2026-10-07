/* 區間 DP: dp[l][r] 由「更短的區間」算出來 → 依長度由短到長 (或 l 由大到小、r 由小到大)
   通用模板 (合併石頭、矩陣鏈乘、切木棍): 枚舉分割點 k
     dp[l][r] = min_{l<=k<r} dp[l][k] + dp[k+1][r] + cost(l, r)   O(N^3)，N <= 500 */
const int MAXN = 505;
const ll INF = 1e18;
int n;
ll a[MAXN], pre[MAXN], dp[MAXN][MAXN];
ll merge_stones() { // 相鄰兩堆合併，代價 = 兩堆總和，求最小總代價 (a 為 1-based)
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i], dp[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int l = 1, r = len; r <= n; l++, r++) {
            dp[l][r] = INF;
            for (int k = l; k < r; k++) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            dp[l][r] += pre[r] - pre[l - 1]; // [改] cost(l, r)
        }
    return dp[1][n]; // 環狀: 複製一份接在後面 (長度 2n)，答案 min dp[i][i+n-1]
}
// 最長迴文子序列 (LPS)，0-based
int lps(const string &s) {
    int m = s.size();
    vector<vector<int>> f(m, vector<int>(m, 0));
    for (int i = m - 1; i >= 0; i--) {
        f[i][i] = 1;
        for (int j = i + 1; j < m; j++)
            f[i][j] = s[i] == s[j] ? f[i + 1][j - 1] + 2 : max(f[i + 1][j], f[i][j - 1]);
    }
    return m ? f[0][m - 1] : 0;
}
// 變成迴文的最少編輯 (插入/刪除/取代都算 1)，並輸出字典序最小的結果字串
pair<int, string> palindrome_edit(const string &s) {
    int m = s.size();
    if (!m) return {0, ""};
    vector<vector<int>> f(m + 1, vector<int>(m + 1, 0));
    for (int i = m - 1; i >= 0; i--)
        for (int j = i + 1; j < m; j++)
            f[i][j] = s[i] == s[j] ? f[i + 1][j - 1] : min({f[i + 1][j], f[i][j - 1], f[i + 1][j - 1]}) + 1;
    string L, R; int i = 0, j = m - 1;
    while (i < j) {
        if (s[i] == s[j]) { L += s[i]; R += s[i]; i++; j--; continue; }
        int best = 256, ch = 0; // 1 取代, 2 處理左, 3 處理右；同分取字典序小的字元
        if (f[i + 1][j - 1] + 1 == f[i][j] && min(s[i], s[j]) < best) best = min(s[i], s[j]), ch = 1;
        if (f[i + 1][j] + 1 == f[i][j] && s[i] < best) best = s[i], ch = 2;
        if (f[i][j - 1] + 1 == f[i][j] && s[j] < best) best = s[j], ch = 3;
        L += (char)best; R += (char)best;
        if (ch == 1) i++, j--; else if (ch == 2) i++; else j--;
    }
    if (i == j) L += s[i];
    reverse(R.begin(), R.end());
    return {f[0][m - 1], L + R};
}
/* 迴文子序列「總數」(位置不同算不同):
   s[i]==s[j]: f = f[i+1][j] + f[i][j-1] + 1；否則 f = f[i+1][j] + f[i][j-1] - f[i+1][j-1] */
