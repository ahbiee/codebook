// 合併 n 堆，每次合併代價 = 兩堆重量和，求最小總代價: 每次挑最小的兩堆 (min-heap)
ll huffman_cost(const vector<ll> &w) {
    priority_queue<ll, vector<ll>, greater<ll>> pq(w.begin(), w.end());
    ll cost = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        cost += a + b; pq.push(a + b);
    }
    return cost;
}
// Huffman 編碼: 用陣列存樹 (lc, rc；-1 = 葉子)，葉子 i 對應字元 ch[i]
const int MAXN = 600;
int lc[MAXN], rc[MAXN], node_cnt;
char ch[MAXN];
map<char, string> code;
void get_code(int u, const string &s) {
    if (lc[u] == -1) { code[ch[u]] = s.empty() ? "0" : s; return; } // 只有一種字元時給 "0"
    get_code(lc[u], s + "0"); get_code(rc[u], s + "1");
}
int build_huffman(const string &text) { // 回傳根
    map<char, int> freq;
    for (char c : text) freq[c]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {頻率, 節點}
    node_cnt = 0; code.clear();
    for (auto [c, f] : freq) ch[node_cnt] = c, lc[node_cnt] = rc[node_cnt] = -1, pq.push({f, node_cnt++});
    while (pq.size() > 1) {
        auto [f1, a] = pq.top(); pq.pop();  // 最小的放左 (0)
        auto [f2, b] = pq.top(); pq.pop();  // [改] 題目規定左右/同頻率的順序時要改這裡
        lc[node_cnt] = a; rc[node_cnt] = b;
        pq.push({f1 + f2, node_cnt++});
    }
    int root = pq.top().second;
    get_code(root, "");
    return root; // 解碼: 從 root 依 0/1 走 lc/rc，走到葉子輸出 ch 並回到 root
}
