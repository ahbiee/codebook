// 二元樹用陣列存: lc[u], rc[u] (0 = 沒有子節點)，root 通常為 1
const int MAXN = 200005;
int lc[MAXN], rc[MAXN];
vector<int> pre_order, in_order, post_order;
void dfs(int u) {
    if (!u) return;
    pre_order.push_back(u);   // 前序: 根 左 右
    dfs(lc[u]);
    in_order.push_back(u);    // 中序: 左 根 右 (BST 的中序 = 排序好的)
    dfs(rc[u]);
    post_order.push_back(u);  // 後序: 左 右 根
}
vector<int> level_order(int root) { // 層序 (BFS)
    vector<int> res; queue<int> q; q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop(); res.push_back(u);
        if (lc[u]) q.push(lc[u]);
        if (rc[u]) q.push(rc[u]);
    }
    return res;
}
// 給前序 + 中序，輸出後序 (字元版)。O(N^2)，N 大時用 map 記 in 的位置
string pre_in_to_post(const string &pre, const string &in) {
    if (pre.empty()) return "";
    char root = pre[0];
    int k = in.find(root);    // 左子樹大小
    return pre_in_to_post(pre.substr(1, k), in.substr(0, k))
         + pre_in_to_post(pre.substr(k + 1), in.substr(k + 1)) + root;
}
// 給後序 + 中序 → 根在後序最後一個，其餘同理
// 一般樹 (不只二元): vector<int> ch[u] 存小孩，DFS 遞迴每個小孩即可
