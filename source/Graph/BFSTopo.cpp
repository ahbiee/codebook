const int MAXN = 200005;
int n, m, indeg[MAXN], dist_[MAXN];
vector<int> g[MAXN]; // 多筆測資: for(i=0..n) g[i].clear(), indeg[i]=0;

// 1. 拓樸排序 (Kahn)。回傳順序，size < n 代表有環
vector<int> topo_sort() {
    queue<int> q; vector<int> res;          // [改] 要字典序最小: priority_queue<int,vector<int>,greater<int>>
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop(); res.push_back(u);
        for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
    }
    return res;
}
// DAG 上 DP: 依拓樸順序轉移，例如最長路 dp[v] = max(dp[v], dp[u] + w)、路徑數 dp[v] += dp[u]

// 2. BFS: 無權圖最短路 (邊權全為 1)
void bfs(int s) {                       // [改] 多源 BFS: 把所有起點一開始都 push、dist = 0
    fill(dist_, dist_ + n + 1, -1);
    queue<int> q; q.push(s); dist_[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist_[v] == -1) dist_[v] = dist_[u] + 1, q.push(v);
    }
}
// 3. 網格 BFS
const int MAXR = 1005;
int R, C, gd[MAXR][MAXR];
char grid[MAXR][MAXR];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}; // [改] 8 方向 / 騎士走法
void grid_bfs(int sx, int sy) {
    for (int i = 0; i < R; i++) fill(gd[i], gd[i] + C, -1);
    queue<pair<int, int>> q; q.push({sx, sy}); gd[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (grid[nx][ny] == '#' || gd[nx][ny] != -1) continue; // [改] 障礙物條件
            gd[nx][ny] = gd[x][y] + 1; q.push({nx, ny});
        }
    }
}
// 4. 0-1 BFS: 邊權只有 0 或 1，用 deque，權 0 推前面、權 1 推後面，O(V+E)
vector<pair<int, int>> wg[MAXN];
int d01[MAXN];
void bfs01(int s) {
    fill(d01, d01 + n + 1, INT_MAX);
    deque<int> dq; dq.push_back(s); d01[s] = 0;
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : wg[u]) if (d01[u] + w < d01[v]) {
            d01[v] = d01[u] + w;
            w ? dq.push_back(v) : dq.push_front(v);
        }
    }
}
// 例: 網格「最少拆幾道牆」/「最少轉向次數」→ 走空地權 0、拆牆/轉向權 1
