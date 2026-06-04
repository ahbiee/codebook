/*
dfn[u]： DFS 時，節點 u 被拜訪到的「時間戳記」或「順序」。一旦給定就不會再改變。

low[u]： 從節點 u 的子樹出發，在不經過 走到 u 的那條父節點邊 的前提下，透過back-edge能到達的所有節點中，最小的 dfn 值。
*/

/*
割點 (Articulation Point)：
定義： 在無向連通圖中，如果移除某個節點及其所有相連的邊後，圖被切斷成兩個或多個不相連的部分，該點就是割點。
用途： 尋找網路、電路或交通系統中的「單點故障」瓶頸。只要這個點壞了，整個系統就會癱瘓。
判斷條件：
若 u 是 DFS 的根節點 (Root)，且它有 2 個以上的子樹，則 u 是割點。
若 u 不是根節點，且存在至少一個子節點 v 滿足 low[v] >= dfn[u]。這代表 v 及其子孫「最多只能爬回 u 自己」，無法繞過 u 抵達更上層的祖先。如果把 u 拔掉，v 就會跟上面斷聯，因此 u 是割點。

點雙連通分量 (Vertex Biconnected Component)：
定義： 一個不包含任何割點的「極大連通子圖」。在 v-BCC 中，任意兩點之間至少有兩條點不重複的路徑。
用途： 用來縮點。把一個個 v-BCC 視為一個大節點，可以將複雜的圖形轉化為「樹」的結構，進而利用 LCA 或樹上 DP 來處理複雜的圖上路徑詢問。
*/

struct BCC {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> dfn, low;
    vector<bool> is_cut;           // 紀錄是否為割點
    vector<vector<int>> bcc_nodes; // 儲存每個 BCC 內的點集
    stack<int> st;

    void init(int _n) {
        n = _n;
        timer = 0;
        adj.assign(n + 1, vector<int>());
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        is_cut.assign(n + 1, false);
        bcc_nodes.clear();
        while (!st.empty()) st.pop();
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p = -1) {
        dfn[u] = low[u] = ++timer;
        st.push(u);
        int children = 0; // 紀錄 DFS 樹上的子節點數量

        for (int v : adj[u]) {
            if (v == p) continue; // 不走回頭路 (父節點)

            if (dfn[v]) {
                // v 已經拜訪過，代表這是一條 Back-edge (回邊)
                low[u] = min(low[u], dfn[v]);
            } else {
                // v 沒拜訪過，代表這是一條 Tree-edge (樹邊)
                children++;
                dfs(v, u);
                
                // 子節點回來後，用子節點的 low 更新自己的 low
                low[u] = min(low[u], low[v]);

                // 判斷割點與收集 BCC 的核心條件
                if (low[v] >= dfn[u]) {
                    is_cut[u] = true;
                    vector<int> comp;
                    
                    // 從 stack 把屬於這個 BCC 的點全部彈出
                    while (true) {
                        int w = st.top();
                        st.pop();
                        comp.push_back(w);
                        if (w == v) break; // 注意：退到 v 就停下
                    }
                    // 割點 u 會同時屬於多個 BCC，把它加進去但【不要】從 stack 彈出它
                    comp.push_back(u); 
                    bcc_nodes.push_back(comp);
                }
            }
        }

        // 根節點特判：DFS 起點如果有小於 2 個子樹，則不是割點
        if (p == -1 && children < 2) {
            is_cut[u] = false;
        }
    }

    void solve() {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                dfs(i);
                
                // 處理極端情況：圖中若存在孤立的單個點，將其視為一個 BCC
                if (bcc_nodes.empty() && n == 1) {
                    bcc_nodes.push_back({1});
                }
            }
        }
    }
};