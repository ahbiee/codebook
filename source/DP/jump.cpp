/* PUPC 2025 River Crossing: v[i]=1 可踩、0 不可踩，一次最多跳 K 格，
   求從 0 到 n-1 最少跳幾次並輸出路徑 (同步數時選 index 較小的前一格)。O(N*K) */
const int MAXN = 200005, INF = 0x3f3f3f3f;
int n, K = 3, v[MAXN], f[MAXN], pre_[MAXN];  // [改] K
void solve() {
    fill(f, f + n, INF); fill(pre_, pre_ + n, -1);
    f[0] = 0;
    for (int i = 1; i < n; i++) {
        if (!v[i]) continue;
        for (int j = 1; j <= K && i - j >= 0; j++)
            if (v[i - j] && f[i - j] != INF && f[i - j] + 1 <= f[i]) // <= : 同步數時換成更小的 index
                f[i] = f[i - j] + 1, pre_[i] = i - j;
    }
    if (f[n - 1] == INF) { cout << -1 << '\n'; return; }
    vector<int> path;
    for (int i = n - 1; i != -1; i = pre_[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    cout << f[n - 1] << '\n';
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
}
// 若 K 很大: f[i] = min(f[i-K..i-1]) + 1 → 用單調隊列，O(N)
// 不用輸出路徑時: 用 Greedy「間隔跳躍」O(N)
