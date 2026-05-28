// 讓 Edge 支援比較大小，排序時會自動依據權重 w 由小到大排
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

struct Kruskal {
    int n;
    vector<Edge> edges;

    void init(int _n) {
        n = _n;
        edges.clear();
    }

    void add_edge(int u, int v, long long w) {
        edges.push_back({u, v, w});
    }

    // 回傳最小生成樹的總權重。若圖不連通則回傳 -1
    long long solve() {
        sort(edges.begin(), edges.end()); // 1. 將所有邊依權重排序
        
        DSU dsu;
        dsu.init(n + 1); // 2. 呼叫併查集 (預設 1-based index)
        
        long long total_weight = 0;
        int edge_cnt = 0; // 記錄成功連接了幾條邊

        for (auto& e : edges) {
            // 3. unite 若回傳 true，代表 u 和 v 原本不相連，合併成功 (無環)
            if (dsu.unite(e.u, e.v)) {
                total_weight += e.w;
                edge_cnt++;
                
                // V 個點只要 V-1 條邊即完全連通，提早結束優化
                if (edge_cnt == n - 1) break; 
            }
        }
        
        // 檢查是否有成功把所有點連通
        return (edge_cnt == n - 1) ? total_weight : -1;
    }
};