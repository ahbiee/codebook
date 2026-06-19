// 讓 Edge 支援比較大小，排序時會自動依據權重 w 由小到大排
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};

struct Kruskal {
    int n;
    vector<Edge> edges;
    vector<vector<pair<int, long long>>> tree_adj; // 用來存 MST 的樹狀圖，解DFS MST用

    void init(int _n) {
        n = _n;
        edges.clear();
        tree_adj.assign(n + 1, vector<pair<int, long long>>());
    }

    void add_edge(int u, int v, long long w) {
        edges.push_back({u, v, w});
    }

    // 回傳最小生成樹的總權重。若圖不連通則回傳 -1
    long long solve() {
        sort(edges.begin(), edges.end()); 
        // 如果需要找MaxST，請 sort(edges.rbegin(), edges.rend())， r!!
        
        DSU dsu;
        dsu.init(n + 1); 
        
        long long total_weight = 0;
        int edge_cnt = 0; // 連接邊個數

        for (auto& e : edges) {
            // unite 若回傳 true，代表 u 和 v 原本不相連，合併成功 (無環)
            if (dsu.unite(e.u, e.v)) {
                total_weight += e.w;
                edge_cnt++;

                // 成為MST的一部分，所以加入樹狀圖中
                tree_adj[e.u].push_back({e.v, e.w});
                tree_adj[e.v].push_back({e.u, e.w});
                
                if (edge_cnt == n - 1) break; // V 個點只要 V-1 條邊即完全連通
            }
        }
        
        return (edge_cnt == n - 1) ? total_weight : -1;
    }

    // u: 當前點，target: 目標點，p: 父節點，cur_max: 目前最大邊權，呼叫: dfs_mst(st, ed, 0, 0)
    long long dfs_mst(int u, int target, int p, long long cur_max) {
        if (u == target) return cur_max; // 找到終點，回傳整條路的瓶頸值

        for (auto& edge : tree_adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (v != p) { // 不走回頭路，完美省去 vis 陣列
                // 帶著「目前遇過的最大邊權」繼續往下深搜
                long long res = dfs_mst(v, target, u, max(cur_max, w));
                
                // 如果 res 不是 -1，代表在 v 的這條分支深處成功找到了 target
                if (res != -1) return res; 
            }
        }
        return -1; // 這條死胡同找不到終點
    }
};