// 倍增 LCA: 預處理 O(N log N)、查詢 O(log N)。同時求路徑上的最大邊權
const int MAXN = 200005, LOG = 18; // 2^LOG > N
int n, up[LOG][MAXN], dep[MAXN];
ll mx[LOG][MAXN], distr[MAXN];     // mx[j][v]: v 往上 2^j 條邊中的最大邊權；distr: 到根距離
vector<pair<int, ll>> g[MAXN];
void build(int root) { // BFS 版，鏈狀樹也不會 stack overflow
    vector<int> order; order.reserve(n);
    fill(dep, dep + n + 1, -1);
    queue<int> q; q.push(root);
    dep[root] = 0; up[0][root] = root; mx[0][root] = 0; distr[root] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (auto [v, w] : g[u]) if (dep[v] == -1) {
            dep[v] = dep[u] + 1; up[0][v] = u; mx[0][v] = w; distr[v] = distr[u] + w;
            q.push(v);
        }
    }
    for (int j = 1; j < LOG; j++)
        for (int v : order) {
            up[j][v] = up[j - 1][up[j - 1][v]];
            mx[j][v] = max(mx[j - 1][v], mx[j - 1][up[j - 1][v]]); // [改] min / sum
        }
}
int kth_ancestor(int v, int k) { for (int j = 0; j < LOG; j++) if (k >> j & 1) v = up[j][v]; return v; }
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = kth_ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[j][u] != up[j][v]) u = up[j][u], v = up[j][v];
    return up[0][u];
}
ll path_max(int u, int v) { // u-v 路徑上的最大邊權
    ll res = 0;
    if (dep[u] < dep[v]) swap(u, v);
    for (int j = LOG - 1; j >= 0; j--)
        if (dep[u] - (1 << j) >= dep[v]) res = max(res, mx[j][u]), u = up[j][u];
    if (u == v) return res;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[j][u] != up[j][v]) {
            res = max({res, mx[j][u], mx[j][v]});
            u = up[j][u]; v = up[j][v];
        }
    return max({res, mx[0][u], mx[0][v]});
}
// 兩點距離 = distr[u] + distr[v] - 2 * distr[lca(u, v)]  (邊數: 用 dep)
// u 是否在 v 的子樹內: lca(u, v) == v
