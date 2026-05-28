struct Dijkstra {
    // 定義 pii 為 pair<距離, 節點>，預設由小到大排序(pq用)
    using pii = pair<long long, int>;
    const int MAXN = 2e5 + 10;
    const long long INF = 1e18; // 使用 1e18 避免相加時 long long 溢位
    
    vector<pair<int, long long>> adj[MAXN]; // adj[u] = {v, weight}
    long long dist[MAXN]; // dist[i]為起點到i的距離
    int n;

    // 初始化：傳入節點數，清空圖
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
        }
    }

    void add_edge(int u, int v, long long w) {
        adj[u].push_back({v, w});
        // 若為無向圖，須加上 adj[v].push_back({u, w});
    }

    void solve(int start) {
        fill(dist, dist + n + 1, INF); // 將距離陣列初始化為無限大
        // pq存起點到某一點的距離，用距離的Min-Heap
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // 懶惰刪除 (Lazy Deletion)：如果取出時發現已經有更好的距離，直接丟棄
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                long long w = edge.second;

                // 鬆弛 (Relax)
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};