/* 樹鏈剖分 (HLD): 樹上「路徑」修改/查詢 → 拆成 O(log N) 段連續區間，丟給線段樹/BIT
   需要 BIT.cpp (或 SegmentTree.cpp)。以「點權、單點修改、路徑和」為例。1-based */
const int MAXV = 200005;
int par_[MAXV], dep_[MAXV], heavy[MAXV], head[MAXV], pos[MAXV], sz_[MAXV];
vector<int> adj[MAXV];
void hld_build(int root, int N) { // N = 樹的點數；之後 BIT 的 n 也要設成 N
    vector<int> order; order.reserve(N);
    queue<int> qu; qu.push(root); par_[root] = 0; dep_[root] = 0;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop(); order.push_back(u);
        for (int v : adj[u]) if (v != par_[u]) par_[v] = u, dep_[v] = dep_[u] + 1, qu.push(v);
    }
    for (int i = N - 1; i >= 0; i--) { // 由下往上算子樹大小、重兒子
        int u = order[i]; sz_[u] = 1; heavy[u] = 0;
        for (int v : adj[u]) if (v != par_[u]) {
            sz_[u] += sz_[v];
            if (!heavy[u] || sz_[v] > sz_[heavy[u]]) heavy[u] = v;
        }
    }
    int timer = 0;
    for (int u : order) if (u == root || heavy[par_[u]] != u) // u 是一條鏈的開頭
        for (int v = u; v; v = heavy[v]) head[v] = u, pos[v] = ++timer;
}
ll path_query(int u, int v) { // u-v 路徑上點權和
    ll res = 0;
    while (head[u] != head[v]) {
        if (dep_[head[u]] < dep_[head[v]]) swap(u, v);
        res += sum(bit, pos[u]) - sum(bit, pos[head[u]] - 1); // [改] 區間查詢 [pos[head[u]], pos[u]]
        u = par_[head[u]];
    }
    if (dep_[u] > dep_[v]) swap(u, v);
    return res + sum(bit, pos[v]) - sum(bit, pos[u] - 1);      // [改] 邊權: 改成 pos[u]+1 ~ pos[v]
}
void point_update(int u, ll delta) { add(bit, pos[u], delta); }
// 子樹 u 也是連續區間 [pos[u], pos[u] + sz_[u] - 1]
// 路徑「區間加」: 同樣的迴圈，把查詢換成線段樹的 update(pos[head[u]], pos[u], v)
// 邊權: 把邊 (par, v) 的權重放在 v 上，最後一段不要包含 LCA (pos[u]+1)
