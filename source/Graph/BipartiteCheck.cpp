struct BipartiteCheck {
    int n;
    vector<vector<int>> adj;
    vector<int> color; // 0: 未著色, 1: 顏色A, -1: 顏色B

    void init(int _n) {
        n = _n;
        adj.assign(n + 1, vector<int>());
        color.assign(n + 1, 0); // 初始化全為未著色
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 二分圖判斷通常針對無向圖
    }

    bool solve() {
        bool is_bipartite = true;

        // 圖可能有多個連通分量 (Components)，必須確保每個節點都被檢查到
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) { // 遇到未著色的節點，當作新 Component 的起點
                queue<int> q;
                q.push(i);
                color[i] = 1; // 塗上第一種顏色

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == 0) {
                            // 相鄰節點未著色，塗上相反的顏色 (-color[u]) 並加入 queue
                            color[v] = -color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            // 相鄰節點已著色，且與自己同色 -> 產生奇數環，非二分圖
                            is_bipartite = false;
                            return false; // 提早結束，不需繼續檢查
                        }
                    }
                }
            }
        }
        return is_bipartite;
    }
};