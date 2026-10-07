// n 個物品 (1-based)，重量 w[i]、價值 v[i]，容量 W
const int MAXN = 1005, MAXW = 100005;
int n, W, w[MAXN], v[MAXN];
ll dp[MAXW];
ll dp2[105][10005]; // 二維版很吃記憶體 (N*W*8 bytes)，只在要回溯時用

// 1. 0/1 背包 二維 (要回溯選了哪些時用)。dp2[i][j] = 前 i 個物品、容量 j 的最大價值
void knap01_2d() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++) {
            dp2[i][j] = dp2[i - 1][j];                                         // 不拿 i
            if (j >= w[i]) dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - w[i]] + v[i]); // 拿 i
        }
    vector<int> chosen; // 回溯: 和上一列一樣就是沒拿
    for (int i = n, j = W; i >= 1; i--)
        if (dp2[i][j] != dp2[i - 1][j]) chosen.push_back(i), j -= w[i];
}
// 2. 0/1 背包 一維 (滾動陣列)：j 必須「由大到小」，否則同一物品會被拿多次
void knap01() {
    fill(dp, dp + W + 1, 0);       // [改] 恰好裝滿: dp[0]=0，其餘 -INF
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
}
// 2b. 二維費用 0/1 背包: 每個物品同時消耗兩種資源 (例: 時間 t[i]、雞蛋 e[i])，上限 T、E
//     dp[j][k] = 時間用 <= j、雞蛋用 <= k 時的最大價值。和 0/1 一樣，兩層容量都「由大到小」
const int MAXT = 505, MAXE = 505;
int T, E, t[MAXN], e[MAXN];
ll dp2d[MAXT][MAXE];
void knap01_2cost() {
    for (int j = 0; j <= T; j++) fill(dp2d[j], dp2d[j] + E + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = T; j >= t[i]; j--)          // 時間由大到小
            for (int k = E; k >= e[i]; k--)      // 雞蛋由大到小
                dp2d[j][k] = max(dp2d[j][k], dp2d[j - t[i]][k - e[i]] + v[i]);
    // 答案 dp2d[T][E]。[改] 每個物品可無限拿: 兩層都改成由小到大
    // [改] 求「最多能做幾個」: v[i] = 1
}
// 3. 完全背包 (每種無限個)：j「由小到大」
void knap_unbounded() {
    fill(dp, dp + W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= W; j++) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
}
// 4. 多重背包 (第 i 種有 c[i] 個)：二進位拆分成 1,2,4,...,剩餘 → 變 0/1 背包，O(W Σ log c)
int c[MAXN];
void knap_bounded() {
    fill(dp, dp + W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int k = 1, left = c[i]; left > 0; k <<= 1) {
            int take = min(k, left); left -= take;
            int ww = w[i] * take; ll vv = (ll)v[i] * take;
            for (int j = W; j >= ww; j--) dp[j] = max(dp[j], dp[j - ww] + vv);
        }
}
// 5. 分組背包 (每組最多選一個)：容量迴圈在外 (由大到小)，組內物品在內
vector<vector<pair<int, int>>> groups; // groups[g] = {(重量, 價值)}
void knap_group() {
    fill(dp, dp + W + 1, 0);
    for (auto &grp : groups)
        for (int j = W; j >= 0; j--)
            for (auto [gw, gv] : grp) if (j >= gw) dp[j] = max(dp[j], dp[j - gw] + gv);
}
/* 6. 子集合和 / 能否剛好湊出 / 分成兩堆等重: bitset<MAXW> b; b[0]=1; 每個 x: b |= b << x;
      能湊出 j <=> b[j]。等重兩堆: 總和偶數且 b[sum/2]
   7. 方法數: dp[0]=1，max 改成 +=
   8. 容量很大 (1e9) 但價值小: 改成 dp[價值] = 最小重量，最後找 dp[val] <= W 的最大 val
   9. 多人各自有容量 W_i、共用同一批商品: 跑一次 dp，答案 Σ dp[W_i] (dp 初始全 0 時已是單調) */
