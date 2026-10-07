// 最大流 Dinic。O(V^2 E)，二分圖 O(E sqrt V)。邊 e 的反向邊是 e ^ 1
const int MAXN = 5005, MAXE = 200005; // MAXE = 2 * 邊數
const ll INF = 1e18;
int n, S, T, ecnt, to[MAXE], lvl[MAXN], it_[MAXN];
ll cap[MAXE];
vector<int> g[MAXN]; // g[u] = 從 u 出發的邊編號
void init(int _n) { n = _n; ecnt = 0; for (int i = 0; i <= n; i++) g[i].clear(); }
void add_edge(int u, int v, ll c) { // 無向邊: 第二行的 0 改成 c
    to[ecnt] = v; cap[ecnt] = c; g[u].push_back(ecnt++);
    to[ecnt] = u; cap[ecnt] = 0; g[v].push_back(ecnt++);
}
bool bfs() {
    fill(lvl, lvl + n + 1, -1);
    queue<int> q; q.push(S); lvl[S] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e : g[u]) if (cap[e] > 0 && lvl[to[e]] == -1) lvl[to[e]] = lvl[u] + 1, q.push(to[e]);
    }
    return lvl[T] != -1;
}
ll dfs(int u, ll f) {
    if (u == T) return f;
    for (int &i = it_[u]; i < (int)g[u].size(); i++) { // 當前弧優化: i 是參考
        int e = g[u][i], v = to[e];
        if (cap[e] > 0 && lvl[v] == lvl[u] + 1) {
            ll d = dfs(v, min(f, cap[e]));
            if (d > 0) { cap[e] -= d; cap[e ^ 1] += d; return d; }
        }
    }
    return 0;
}
ll max_flow(int s, int t) {
    S = s; T = t;
    ll flow = 0;
    while (bfs()) {
        fill(it_, it_ + n + 1, 0);
        while (ll f = dfs(S, INF)) flow += f;
    }
    return flow;
}
/* 建模技巧:
- 最小割 = 最大流。割邊: 跑完後從 S 沿 cap>0 走得到的點集合 A，A→非A 的原始邊
- 二分圖匹配: S→左(1)、左→右(1)、右→T(1)；每點最多配 k 個 → 對應邊容量 k
- 點有容量: 拆點 v_in → v_out 容量 = 點容量
- 多源多匯: 超級源點連所有源點 (容量 INF)
- 最大權閉合子圖 (選 A 必須選 B): S→正權點(w)、負權點→T(-w)、A→B(INF)；答案 = 正權和 - 最大流
*/
