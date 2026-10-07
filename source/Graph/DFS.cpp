const int MAXN = 200005;
int n, comp[MAXN], color_[MAXN];
vector<int> g[MAXN];
// 1. 連通塊: comp[v] = 所屬編號 (0 = 未拜訪)
void dfs(int u, int id) {
    comp[u] = id;
    for (int v : g[u]) if (!comp[v]) dfs(v, id);
}
int count_components() {
    fill(comp, comp + n + 1, 0);
    int id = 0;
    for (int i = 1; i <= n; i++) if (!comp[i]) dfs(i, ++id);
    return id;
}
// 2. 有向圖找環: 0 未拜訪, 1 在遞迴堆疊中, 2 已完成。走到狀態 1 的點 = 有環
bool has_cycle(int u) {
    color_[u] = 1;
    for (int v : g[u]) {
        if (color_[v] == 1) return true;
        if (color_[v] == 0 && has_cycle(v)) return true;
    }
    color_[u] = 2;
    return false;
}
// 無向圖找環: 走到「已拜訪且不是父節點」的點即有環；或 DSU unite 失敗
// 3. 小 N (<= 10) 枚舉所有路徑: 回溯
bool vis[MAXN];
ll best;
void all_paths(int u, ll len) {
    best = max(best, len);                        // [改] 依題意更新答案 (最長/最短/計數)
    for (int v : g[u]) if (!vis[v]) {
        vis[v] = true; all_paths(v, len + 1);
        vis[v] = false;                           // 回溯: 一定要還原
    }
}
// 遞迴太深 (鏈狀 1e5 以上) 可能 stack overflow → 改用 stack 的迭代版或 BFS
