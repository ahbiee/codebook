// 湊出金額 k (硬幣無限使用)。方法數成長很快 → 取模或 long long
const int MAXK = 1000005;
const ll MOD = 1e9 + 7, INF = 1e18;
ll dp[MAXK];
// 1. 組合數 (2+3 和 3+2 算同一種)：外層「硬幣」、內層「金額」
ll count_combination(const vector<int> &coins, int k) {
    fill(dp, dp + k + 1, 0); dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= k; i++) dp[i] = (dp[i] + dp[i - c]) % MOD;
    return dp[k];
}
// 2. 排列數 (順序不同算不同)：外層「金額」、內層「硬幣」
ll count_permutation(const vector<int> &coins, int k) {
    fill(dp, dp + k + 1, 0); dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int c : coins) if (i >= c) dp[i] = (dp[i] + dp[i - c]) % MOD;
    return dp[k];
}
// 3. 最少硬幣數 (湊不出回傳 -1)
ll min_coins(const vector<int> &coins, int k) {
    fill(dp, dp + k + 1, INF); dp[0] = 0;
    for (int c : coins)
        for (int i = c; i <= k; i++) if (dp[i - c] != INF) dp[i] = min(dp[i], dp[i - c] + 1);
    return dp[k] == INF ? -1 : dp[k];
}
// 多筆詢問同一組硬幣: 在 main 開頭對最大金額建一次表，每筆直接查 dp[k]
// 每種硬幣只能用一次 → 內層改成由大到小 (變 0/1 背包)
