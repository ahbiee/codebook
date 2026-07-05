const int MAXN = 2e5 + 5; // 依據題目給定的最大節點數量調整 MAXN
const int LOG = 19; // LOG = __lg(MAXN) + 1，2e5 的情況下 18+1=19 即可

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

// DFS 預處理深度與 2^i 祖先
void dfs(int u, int p) {
    up[u][0] = p; // 2^0 的祖先就是直屬父親 p
    
    for (int i = 1; i < LOG; ++i) { // 狀態轉移：倍增建表
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int get_lca(int u, int v) { // 查詢最近公共祖先 (LCA)
    if (depth[u] < depth[v]) swap(u, v); // 確保 u 是比較深的那個點
    
    for (int i = LOG - 1; i >= 0; --i) { // 深度對齊
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; --i) { // 同時往上跳，尋找 LCA 的直屬子節點
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    // 假設題目輸入為 n 個點，q 筆 LCA 查詢
    if (!(cin >> n >> q)) return 0;

    for(int i = 1; i <= n; ++i) adj[i].clear(); // 若題目有多筆測資，必須初始化

    for (int i = 0; i < n - 1; ++i) { // 讀取 n-1 條無向樹邊
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0; // 選擇根節點 (通常題目為 1，或0)，並初始化根節點的深度與 DFS 預處理
    dfs(1, 1); // 根節點的父親設為自己，防止倍增跳躍時越界

    while (q--) { // 處理 Q 筆查詢
        int u, v;
        cin >> u >> v;
        
        int lca = get_lca(u, v);
        cout << lca << "\n";
        
        // 延伸：若題目要求輸出兩點間的距離 (邊數)
        // cout << depth[u] + depth[v] - 2 * depth[lca] << "\n";
    }

    return 0;
}