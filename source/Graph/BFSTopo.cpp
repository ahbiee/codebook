struct BFS_Topo {
    int n;
    vector<vector<int>> adj; // adjacency list，避免爆空間
    vector<int> in_degree; // 紀錄入度，用於拓樸排序

    void init(int _n) {
        n = _n;
        adj.assign(n + 1, vector<int>());
        in_degree.assign(n + 1, 0);
    }

    // 有向圖，u 指向 v (u 必須在 v 之前完成)
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        in_degree[v]++; // v 被 u 指到，入度 +1
    }

    // 1. 拓樸排序 (Kahn's Algorithm)
    // 回傳拓樸排序的結果。若回傳的 vector 大小小於 n，代表圖中有環
    vector<int> topo_sort() {
        queue<int> q;
        vector<int> res;

        // 步驟一：將所有入度為 0 (沒有前置條件) 的點加入 queue
        for (int i = 1; i <= n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }

        // 步驟二：開始 BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);

            // 拔掉 u 連出去的所有邊
            for (int v : adj[u]) {
                in_degree[v]--; // v 的前置條件少了一個
                if (in_degree[v] == 0) { // 如果前置條件都滿足了，就推入 queue
                    q.push(v);
                }
            }
        }
        return res; // 若 res.size() < n，說明有環，無法完成拓樸排序
    }

    // 2. 基礎 BFS：無權圖的單源最短路徑
    vector<int> get_dist(int start) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) { // 沒走過
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};