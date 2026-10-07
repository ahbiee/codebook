// 有向圖強連通分量 (Tarjan)，O(V+E)。scc[v] = 所屬 SCC 編號 (1..scc_cnt)
// 編號順序是「反拓樸序」: 編號大的 SCC 指向編號小的
const int MAXN = 200005;
int n, timer_, scc_cnt, dfn[MAXN], low[MAXN], scc[MAXN];
bool in_stk[MAXN];
vector<int> g[MAXN], stk;
void tarjan(int u) {
    dfn[u] = low[u] = ++timer_;
    stk.push_back(u); in_stk[u] = true;
    for (int v : g[u]) {
        if (!dfn[v]) { tarjan(v); low[u] = min(low[u], low[v]); }
        else if (in_stk[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) { // u 是這個 SCC 的頭
        scc_cnt++;
        while (true) {
            int v = stk.back(); stk.pop_back();
            in_stk[v] = false; scc[v] = scc_cnt;
            if (v == u) break;
        }
    }
}
void find_scc() {
    timer_ = scc_cnt = 0;
    fill(dfn, dfn + n + 1, 0);
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
}
/* 縮點: 每個 SCC 變成一個點 → 得到 DAG，就能做拓樸 / DAG DP
   for u: for v in g[u]: if (scc[u] != scc[v]) dag[scc[u]].push_back(scc[v]);  (可能重邊，要的話去重)
   - 最少加幾條邊使整張圖強連通: max(入度 0 的 SCC 數, 出度 0 的 SCC 數)，只有 1 個 SCC 時為 0
   - 點權最大路徑: SCC 內點權加總，在 DAG 上 DP
*/
