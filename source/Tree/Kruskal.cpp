// 最小生成樹 O(E log E)。需要 DisjointSet.cpp 的 init / unite
int n;
vector<tuple<ll, int, int>> edges;    // {w, u, v}，tuple 會先比 w
vector<pair<int, ll>> mst_adj[200005]; // MST 本身 (之後要在樹上做事用)
ll kruskal() { // 不連通回傳 -1
    sort(edges.begin(), edges.end()); // [改] 最大生成樹: sort(edges.rbegin(), edges.rend())
    init(n);
    for (int i = 0; i <= n; i++) mst_adj[i].clear();
    ll total = 0; int used = 0;
    for (auto [w, u, v] : edges)
        if (unite(u, v)) {
            total += w; used++;
            mst_adj[u].push_back({v, w}); mst_adj[v].push_back({u, w});
        }
    return used == n - 1 ? total : -1;
}
/* [變形]
- 瓶頸: 「u 到 v 路徑上最大邊最小」= MST 上 u-v 路徑的最大邊 (LCA path_max)
- 必須包含某些邊: 先把那些邊 unite 並加總，再跑 Kruskal
- 最小生成「森林」/ 恰好 k 個連通塊: 做到剩 k 塊 (used == n - k) 就停
- 稠密圖 (V <= 5000, E ~ V^2): 用 O(V^2) Prim 比較快
*/
