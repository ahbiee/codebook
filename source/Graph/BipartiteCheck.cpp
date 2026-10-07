// 二分圖判定 (相鄰點塗不同色)，已處理不連通。color: 0 未塗, 1 / -1
const int MAXN = 200005;
int n, color_[MAXN];
vector<int> g[MAXN];
bool is_bipartite() {
    fill(color_, color_ + n + 1, 0);
    for (int s = 1; s <= n; s++) {
        if (color_[s]) continue;
        queue<int> q; q.push(s); color_[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!color_[v]) color_[v] = -color_[u], q.push(v);
                else if (color_[v] == color_[u]) return false; // 奇環
            }
        }
    }
    return true;
}
// 二分圖 <=> 沒有奇數環。分兩組/兩隊/兩種顏色的題目先想這個
// 每個連通塊可以「翻轉顏色」→ 各塊 (黑數, 白數) 再做背包 DP 求最平均分組
