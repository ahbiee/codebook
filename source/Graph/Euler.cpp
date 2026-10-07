/* 歐拉路徑: 每條「邊」恰好走一次 (Hierholzer)，O(E)
   無向圖: 連通 + 奇點數為 0 (迴路，任意起點) 或 2 (路徑，從奇點出發)
   有向圖: 弱連通 + 全部 入度==出度 (迴路)；或恰一點 出-入=1 (起點)、一點 入-出=1 (終點)
   (連通性只看有邊的點；最後 path.size() != m+1 代表不連通) */
const int MAXN = 200005, MAXM = 400005;
int n, m, eu[MAXM], ev[MAXM], ptr_[MAXN];
bool used[MAXM];
vector<pair<int, int>> g[MAXN]; // {鄰點, 邊編號}
vector<int> path;
void add_edge(int u, int v, int id, bool directed) {
    eu[id] = u; ev[id] = v;
    g[u].push_back({v, id});
    if (!directed) g[v].push_back({u, id});
}
void hierholzer(int s) { // 迭代版，避免遞迴太深。結果在 path (點序列)
    path.clear();
    fill(ptr_, ptr_ + n + 1, 0); fill(used, used + m + 1, false);
    vector<int> st = {s};
    while (!st.empty()) {
        int u = st.back();
        while (ptr_[u] < (int)g[u].size() && used[g[u][ptr_[u]].second]) ptr_[u]++;
        if (ptr_[u] == (int)g[u].size()) { path.push_back(u); st.pop_back(); }
        else { auto [v, id] = g[u][ptr_[u]++]; used[id] = true; st.push_back(v); }
    }
    reverse(path.begin(), path.end());
}
// 要字典序最小的路徑: 先把每個 g[u] 依鄰點排序
