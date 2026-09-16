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

    // 基礎 DFS：走訪與找連通塊 / 遍歷樹
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

/*
題目：節點數量 N <= 10，需要找一條 "最短路徑"，且每個邊的最大degree只有2
題解：使用 DFS 進行枚舉，從各個節點開始跑，對所有可能的路徑跑DFS
邊跑邊更新最長路徑答案，跑完是 O(N!) -> N=10 -> 小於400萬，能跑
*/