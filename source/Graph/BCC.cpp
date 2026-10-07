/* 無向圖。dfn[u]: DFS 拜訪順序；low[u]: u 的子樹「不經過父邊」能回到的最小 dfn
   割點: 非根 u 有子節點 v 使 low[v] >= dfn[u]；根需 >= 2 個 DFS 子樹
   點雙連通分量 (v-BCC): 內部任兩點有兩條點不重複路徑；割點可同時屬於多個 BCC */
const int MAXN = 200005;
int n, timer_, dfn[MAXN], low[MAXN];
bool is_cut[MAXN];
vector<pair<int, int>> g[MAXN]; // {鄰點, 邊編號}，邊編號用來處理重邊
vector<vector<int>> bcc;
vector<int> stk;
void add_edge(int u, int v, int id) { g[u].push_back({v, id}); g[v].push_back({u, id}); }
void tarjan(int u, int pe) { // pe = 走進 u 的邊編號
    dfn[u] = low[u] = ++timer_;
    stk.push_back(u);
    int child = 0;
    for (auto [v, id] : g[u]) {
        if (id == pe) continue;
        if (dfn[v]) { low[u] = min(low[u], dfn[v]); continue; } // 回邊
        child++;
        tarjan(v, id);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
            if (pe != -1) is_cut[u] = true;
            vector<int> comp = {u}; // u 留在 stack 上 (可能還屬於別的 BCC)
            while (true) {
                int w = stk.back(); stk.pop_back();
                comp.push_back(w);
                if (w == v) break;
            }
            bcc.push_back(comp);
        }
    }
    if (pe == -1 && child >= 2) is_cut[u] = true;
}
void solve() {
    timer_ = 0; bcc.clear();
    fill(dfn, dfn + n + 1, 0); fill(is_cut, is_cut + n + 1, false);
    for (int i = 1; i <= n; i++) if (!dfn[i]) {
        stk.clear();
        tarjan(i, -1);
        if (g[i].empty()) bcc.push_back({i}); // 孤立點自成一個 BCC
    }
}
