// 多個 pattern 同時在文章中匹配。root = 0
const int MAXN = 1000005, SIGMA = 26; // MAXN = pattern 總長 + 1
int tr[MAXN][SIGMA], fail_[MAXN], occ[MAXN], cnt = 0;
vector<int> order_; // BFS 順序
int insert(const string &s) { // 回傳 s 的結尾節點 (記下來查答案用)
    int u = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (!tr[u][c]) tr[u][c] = ++cnt;
        u = tr[u][c];
    }
    return u;
}
void build() { // 全部 insert 完再呼叫
    queue<int> q;
    for (int c = 0; c < SIGMA; c++) if (tr[0][c]) fail_[tr[0][c]] = 0, q.push(tr[0][c]);
    while (!q.empty()) {
        int u = q.front(); q.pop(); order_.push_back(u);
        for (int c = 0; c < SIGMA; c++) {
            int v = tr[u][c];
            if (v) fail_[v] = tr[fail_[u]][c], q.push(v);
            else tr[u][c] = tr[fail_[u]][c]; // 不存在的路直接連到 fail 的對應點
        }
    }
}
// 文章 text 跑一次。之後 pattern i 出現次數 = occ[end_node[i]]，O(|text| + 總長)
void query(const string &text) {
    int u = 0;
    for (char ch : text) u = tr[u][ch - 'a'], occ[u]++;
    for (int i = (int)order_.size() - 1; i >= 0; i--) { // 由深到淺，把次數加到 fail
        int v = order_[i];
        occ[fail_[v]] += occ[v];
    }
}
/* [變形]
- 只問「有幾個 pattern 出現過」: 看 occ[end_node[i]] > 0 的個數
- 文章不能包含任何 pattern (禁止字串 DP): 先把 bad[v] |= bad[fail[v]] (按 BFS 順序)，
  dp[長度][AC 節點]，轉移 v = tr[u][c]，跳過 bad[v] 的狀態
*/
