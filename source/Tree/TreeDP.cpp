/* 樹 DP: dp[u] 只由小孩的 dp 算出來 → 依「BFS 序的反序」處理 = 先算小孩
   用 BFS 序就不需要遞迴 (不怕鏈狀樹 stack overflow) */
const int MAXN = 200005;
int n, par[MAXN], sz[MAXN];
ll dp0[MAXN], dp1[MAXN], down_[MAXN], ans[MAXN];
vector<int> g[MAXN], order_;
void bfs_order(int root) {
    order_.clear(); par[root] = 0;
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop(); order_.push_back(u);
        for (int v : g[u]) if (v != par[u]) par[v] = u, q.push(v);
    }
}
// 例 1: 子樹大小 + 最大獨立集 (相鄰點不能同時選)
void tree_dp() {
    for (int i = (int)order_.size() - 1; i >= 0; i--) {
        int u = order_[i];
        sz[u] = 1; dp0[u] = 0; dp1[u] = 1;            // [改] dp1 = 點權
        for (int v : g[u]) if (v != par[u]) {
            sz[u] += sz[v];
            dp0[u] += max(dp0[v], dp1[v]);  // u 不選: 小孩隨意
            dp1[u] += dp0[v];               // u 選: 小孩都不能選
        }
    }
} // 答案 max(dp0[root], dp1[root])。最小點覆蓋: dp1 += min(dp0,dp1)、dp0 += dp1[v]

// 例 2: 換根 DP — 每個點當根時「到所有點的距離和」，O(N)
// 第一次 (由下往上) 算以 1 為根的答案，第二次 (由上往下) 把根從 u 移到小孩 v:
// ans[v] = ans[u] - sz[v] + (n - sz[v])   (v 子樹的點近 1，其餘點遠 1)
void rerooting() {
    bfs_order(1); tree_dp();
    for (int i = (int)order_.size() - 1; i >= 0; i--) {
        int u = order_[i]; down_[u] = 0;
        for (int v : g[u]) if (v != par[u]) down_[u] += down_[v] + sz[v];
    }
    ans[1] = down_[1];
    for (int u : order_) for (int v : g[u]) if (v != par[u]) ans[v] = ans[u] - sz[v] + (n - sz[v]);
}

// 例 3: 樹壓平 (Euler Tour): 子樹 = 一段連續區間 [tin[u], tout[u]]
// → 子樹加值/子樹求和 變成 BIT/線段樹 的區間操作
int tin[MAXN], tout[MAXN], timer_;
void euler_tour(int root) { // 迭代 DFS
    timer_ = 0;
    vector<pair<int, int>> st = {{root, 0}};
    vector<size_t> idx(n + 1, 0);
    while (!st.empty()) {
        auto [u, p] = st.back();
        if (idx[u] == 0) tin[u] = ++timer_;
        if (idx[u] < g[u].size()) {
            int v = g[u][idx[u]++];
            if (v != p) st.push_back({v, u});
        } else { tout[u] = timer_; st.pop_back(); }
    }
}
