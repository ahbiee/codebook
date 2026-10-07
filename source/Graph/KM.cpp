// 帶權二分圖「最大權完美匹配」，左右各 n 點，O(n^3)。1-based
// 點數不同或沒有邊: 補虛擬點/權重 0 的邊 (不能選的邊設 -INF 級大負數)
// 要「最小權」: 權重全部取負，答案再取負
const int MAXN = 505;
const ll INF = 1e18;
int n, match_y[MAXN], pre_[MAXN];
ll w[MAXN][MAXN], lx[MAXN], ly[MAXN], slack[MAXN];
bool vis_y[MAXN];
void km_bfs(int root) {
    fill(slack, slack + n + 1, INF);
    fill(vis_y, vis_y + n + 1, false);
    fill(pre_, pre_ + n + 1, 0);
    int y = 0;
    match_y[0] = root;
    while (true) {
        int x = match_y[y], ny = 0;
        ll delta = INF;
        vis_y[y] = true;
        for (int i = 1; i <= n; i++) if (!vis_y[i]) {
            ll d = lx[x] + ly[i] - w[x][i];
            if (d < slack[i]) slack[i] = d, pre_[i] = y;
            if (slack[i] < delta) delta = slack[i], ny = i;
        }
        for (int i = 0; i <= n; i++) {
            if (vis_y[i]) lx[match_y[i]] -= delta, ly[i] += delta;
            else slack[i] -= delta;
        }
        y = ny;
        if (match_y[y] == 0) break; // 找到沒配對的右邊點
    }
    while (y) match_y[y] = match_y[pre_[y]], y = pre_[y]; // 沿路翻轉
}
ll km() { // 先填好 n 與 w[1..n][1..n]
    fill(match_y, match_y + n + 1, 0);
    fill(ly, ly + n + 1, 0);
    for (int i = 1; i <= n; i++) lx[i] = *max_element(w[i] + 1, w[i] + n + 1);
    for (int i = 1; i <= n; i++) km_bfs(i);
    ll res = 0;
    for (int i = 1; i <= n; i++) res += w[match_y[i]][i]; // 右 i 配到左 match_y[i]
    return res;
}
