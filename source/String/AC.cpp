struct AC_Automaton {
    static const int MAXN = 1e5 + 10;
    int tree[MAXN][size]; // size是字元26, 二進制2
    int fail[MAXN];
    int stop[MAXN]; // 記錄有幾個字串在此結束
    int cnt;

    void init() {
        cnt = 0;
        new_node(); // root is 0
    }

    int new_node() {
        fill(tree[cnt], tree[cnt] + 26, 0);
        fail[cnt] = stop[cnt] = 0;
        return cnt++;
    }

    // 1. 將所有關鍵字插入 Trie
    void insert(const string& s) {
        int curr = 0;
        for (char c : s) {
            int path = c - 'a';
            if (!tree[curr][path]) {
                tree[curr][path] = new_node();
            }
            curr = tree[curr][path];
        }
        stop[curr]++;
    }

    // 2. 建立 Fail 指標與字典圖優化 (使用 BFS)
    void build() {
        queue<int> q;
        // 將 root (0) 的所有實際存在的第一層子節點推入 queue
        for (int i = 0; i < 26; ++i) {
            if (tree[0][i]) {
                fail[tree[0][i]] = 0;
                q.push(tree[0][i]);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < 26; ++i) {
                if (tree[u][i]) {
                    // 若子節點存在，它的 fail 指向父節點 fail 的對應子節點
                    fail[tree[u][i]] = tree[fail[u]][i];
                    q.push(tree[u][i]);
                } else {
                    // 優化: 若子節點不存在，直接把這條路連向 fail 的對應節點
                    // 這樣搜尋時就絕對不會遇到死胡同，也不用往回跳
                    tree[u][i] = tree[fail[u]][i];
                }
            }
        }
    }

    // 3. 搜尋文章，回傳所有關鍵字出現的總次數
    int query(const string& text) {
        int curr = 0;
        int res = 0;
        for (char c : text) {
            curr = tree[curr][c - 'a']; // 感謝字典圖優化，無腦往下走即可
            
            // 順著 fail 指標往上收集沿途所有匹配成功的字串 (例如配對到 "she"，同時也配對到 "he")
            int temp = curr;
            while (temp != 0 && stop[temp] != -1) { 
                res += stop[temp];
                stop[temp] = -1; // -1 是優化：已經算過的關鍵字不要重複算
                temp = fail[temp];
            }
        }
        return res;
    }
};