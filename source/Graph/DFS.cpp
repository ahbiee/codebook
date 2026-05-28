struct DFS{
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;

    void init(int _n) {
        n = _n;
        adj.assign(n + 1, vector<int>());
        vis.assign(n + 1, false);
        subtree_size.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 無向圖就兩個都加
    }

    // 基礎 DFS：走訪與找連通塊
    void dfs(int u) {
        vis[u] = true;
        // 如有需要，處理抵達 u 時的邏輯 (Pre/In/Post-order)
        
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    }
};