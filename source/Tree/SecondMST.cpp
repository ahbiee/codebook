/* 嚴格次小生成樹 O(E log V)。需要 DisjointSet.cpp
   想法: 先求 MST；對每條「非樹邊」(u,v,w)，加進去會形成環，
   拿掉環上 (= 樹上 u-v 路徑) 最大且 < w 的邊 → 候選 = MST - 那條邊 + w
   所以要維護路徑上的「最大值」與「嚴格次大值」 */
const int LOG = 18; // MAXN 沿用 DisjointSet.cpp 的 (2^LOG > N)
const ll INF = 1e18;
int n, up[LOG][MAXN], dep[MAXN];
ll m1[LOG][MAXN], m2[LOG][MAXN]; // 往上 2^j 條邊的最大、嚴格次大
vector<pair<int, ll>> t[MAXN];
void merge_(ll &a1, ll &a2, ll b1, ll b2) { // 把 (b1,b2) 併進 (a1,a2)
    for (ll x : {b1, b2}) {
        if (x > a1) a2 = a1, a1 = x;
        else if (x < a1 && x > a2) a2 = x;
    }
}
ll second_mst(vector<tuple<ll, int, int>> edges) { // 回傳 -1 表示不存在
    sort(edges.begin(), edges.end());
    init(n);
    vector<bool> in_mst(edges.size(), false);
    ll mst = 0; int used = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        auto [w, u, v] = edges[i];
        if (unite(u, v)) in_mst[i] = true, mst += w, used++, t[u].push_back({v, w}), t[v].push_back({u, w});
    }
    if (used != n - 1) return -1;
    vector<int> order; queue<int> q; q.push(1);           // BFS 建倍增表
    fill(dep, dep + n + 1, -1); dep[1] = 0; up[0][1] = 1; m1[0][1] = m2[0][1] = -INF;
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (auto [v, w] : t[u]) if (dep[v] == -1)
            dep[v] = dep[u] + 1, up[0][v] = u, m1[0][v] = w, m2[0][v] = -INF, q.push(v);
    }
    for (int j = 1; j < LOG; j++) for (int v : order) {
        int mid = up[j - 1][v];
        up[j][v] = up[j - 1][mid];
        m1[j][v] = m1[j - 1][v]; m2[j][v] = m2[j - 1][v];
        merge_(m1[j][v], m2[j][v], m1[j - 1][mid], m2[j - 1][mid]);
    }
    ll best = INF;
    for (int i = 0; i < (int)edges.size(); i++) {
        if (in_mst[i]) continue;
        auto [w, u, v] = edges[i];
        ll a1 = -INF, a2 = -INF;
        if (dep[u] < dep[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; j--)
            if (dep[u] - (1 << j) >= dep[v]) merge_(a1, a2, m1[j][u], m2[j][u]), u = up[j][u];
        if (u != v) {
            for (int j = LOG - 1; j >= 0; j--) if (up[j][u] != up[j][v]) {
                merge_(a1, a2, m1[j][u], m2[j][u]); merge_(a1, a2, m1[j][v], m2[j][v]);
                u = up[j][u]; v = up[j][v];
            }
            merge_(a1, a2, m1[0][u], m2[0][u]); merge_(a1, a2, m1[0][v], m2[0][v]);
        }
        if (a1 < w) best = min(best, mst - a1 + w);           // 不要求嚴格: a1 <= w 即可
        else if (a2 > -INF) best = min(best, mst - a2 + w);
    }
    return best == INF ? -1 : best;
}
// 多筆測資: 記得 t[i].clear()
