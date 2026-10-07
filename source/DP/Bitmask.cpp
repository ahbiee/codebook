/* 位元 DP: N <= 20 左右，用一個整數的 bit 表示「哪些東西已經用過/選過」
   mask >> i & 1: 第 i 個是否在集合中；mask | (1<<i): 加入；mask ^ (1<<i): 移除
   例: TSP — 從 0 出發走過所有點各一次再回到 0 的最短距離。O(2^N * N^2) */
const int MAXN = 18; // 2^18*18*8 bytes = 38MB；N=20 要改 int 或省記憶體
const ll INF = 1e18;
int n;
ll d[MAXN][MAXN], dp[1 << MAXN][MAXN]; // dp[mask][v] = 走過 mask 的點、目前停在 v 的最小花費
ll tsp() {
    for (int m = 0; m < (1 << n); m++) fill(dp[m], dp[m] + n, INF);
    dp[1][0] = 0;                                        // [改] 起點
    for (int mask = 1; mask < (1 << n); mask++)
        for (int v = 0; v < n; v++) {
            if (dp[mask][v] == INF || !(mask >> v & 1)) continue;
            for (int u = 0; u < n; u++) if (!(mask >> u & 1))
                dp[mask | (1 << u)][u] = min(dp[mask | (1 << u)][u], dp[mask][v] + d[v][u]);
        }
    ll ans = INF;
    for (int v = 0; v < n; v++) ans = min(ans, dp[(1 << n) - 1][v] + d[v][0]); // [改] 不用回起點: 不加 d[v][0]
    return ans;
}
/* [其他常見位元 DP]
- 指派問題 (n 人 n 工作): dp[mask] = 前 popcount(mask) 個人已分配 mask 這些工作的最小花費
- 枚舉子集合: for (int s = mask; s; s = (s - 1) & mask)  → 全部 O(3^N)
- 分組 (每組有限制): dp[mask] = 把 mask 分好最少要幾組，枚舉子集合 s 為最後一組
- 棋盤放置 (不能相鄰): 一列一列做，狀態 = 上一列的放法 mask，先預處理合法的 mask (mask & (mask<<1)) == 0
*/
