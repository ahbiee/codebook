// 二分圖最大匹配 (Kuhn)，O(V*E)。左邊 1..nl，右邊 1..nr
const int MAXN = 1005;
int nl, nr, match_r[MAXN]; // match_r[v] = 右邊 v 配到的左邊點 (0 = 沒配)
bool vis[MAXN];
vector<int> g[MAXN];       // g[左u] = 可配的右邊點
bool try_match(int u) {
    for (int v : g[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (!match_r[v] || try_match(match_r[v])) { match_r[v] = u; return true; } // 搶位子
    }
    return false;
}
int max_matching() {
    fill(match_r, match_r + nr + 1, 0);
    int res = 0;
    for (int u = 1; u <= nl; u++) {
        fill(vis, vis + nr + 1, false);
        if (try_match(u)) res++;
    }
    return res;
}
/* 二分圖定理 (重要!):
   最小點覆蓋 = 最大匹配            (König)
   最大獨立集 = 總點數 - 最大匹配
   DAG 最小路徑覆蓋 (路徑不相交) = 點數 - 最大匹配 (每點拆成 左u、右u，邊 u→v 變 左u-右v)
   點數很大 (1e5) 改用 Dinic，複雜度 O(E sqrt V) */
