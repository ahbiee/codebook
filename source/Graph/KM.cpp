/*
前提：完美匹配與虛擬節點
KM 演算法要求左右兩側的節點數必須相等（形成完全二分圖）
如果在題目中左右節點數不同，或者某些點之間沒有連線，我們必須加入「虛擬節點」與「權重為 0（或極小值）的虛擬邊」來補齊，才能讓 KM 演算法順利運作。
*/

struct KM {
    int n;
    vector<vector<long long>> weight; // weight[u][v] 表示左 u 到右 v 的權重
    vector<long long> lx, ly, slack;  // lx, ly 為左右點的「期望值(頂標)」，slack 為鬆弛量
    vector<int> match_y;              // match_y[v] = u 代表右側 v 匹配給左側 u
    vector<int> pre;                  // 紀錄右側節點的交替樹路徑，用於 BFS 回溯
    vector<bool> vis_y;               // 紀錄右側節點是否在當前交替樹中
    const long long INF = 1e18;

    void init(int _n) {
        n = _n;
        // 為了方便，採用 1-based index，0 作為虛擬的空節點
        weight.assign(n + 1, vector<long long>(n + 1, 0));
        lx.assign(n + 1, 0);
        ly.assign(n + 1, 0);
        match_y.assign(n + 1, 0);
    }

    void add_edge(int u, int v, long long w) {
        weight[u][v] = max(weight[u][v], w); // 若有多重邊，保留權重最大的
    }

    // BFS 尋找增廣路徑並更新頂標
    void bfs(int root) {
        slack.assign(n + 1, INF);
        vis_y.assign(n + 1, false);
        pre.assign(n + 1, 0);
        
        int y = 0; 
        match_y[0] = root; // 將起始點放在虛擬節點 match_y[0]
        
        while (true) {
            int x = match_y[y]; // 當前考慮的左側節點
            long long delta = INF;
            int next_y = 0;
            vis_y[y] = true;
            
            // 遍歷所有右側節點，計算 slack 量
            for (int i = 1; i <= n; ++i) {
                if (!vis_y[i]) {
                    long long diff = lx[x] + ly[i] - weight[x][i];
                    if (diff < slack[i]) {
                        slack[i] = diff;
                        pre[i] = y; // 紀錄從哪個右側節點轉移過來
                    }
                    if (slack[i] < delta) {
                        delta = slack[i];
                        next_y = i;
                    }
                }
            }
            
            // 更新交替樹中所有點的頂標 (期望值)
            for (int i = 0; i <= n; ++i) {
                if (vis_y[i]) {
                    lx[match_y[i]] -= delta;
                    ly[i] += delta;
                } else {
                    slack[i] -= delta;
                }
            }
            
            y = next_y; // 走到下一個右側節點
            if (match_y[y] == 0) break; // 找到未匹配的右側節點，增廣路徑結束
        }
        
        // 回溯並更新匹配狀態
        while (y != 0) {
            match_y[y] = match_y[pre[y]];
            y = pre[y];
        }
    }

    long long solve() {
        // 初始化左側頂標為連接邊的最大權重
        for (int i = 1; i <= n; ++i) {
            lx[i] = -INF;
            for (int j = 1; j <= n; ++j) {
                lx[i] = max(lx[i], weight[i][j]);
            }
        }
        
        // 對每一個左側節點進行匹配
        for (int i = 1; i <= n; ++i) {
            bfs(i);
        }
        
        // 計算最大權重總和
        long long max_weight = 0;
        for (int i = 1; i <= n; ++i) {
            if (match_y[i] != 0) {
                max_weight += weight[match_y[i]][i];
            }
        }
        return max_weight;
    }
};