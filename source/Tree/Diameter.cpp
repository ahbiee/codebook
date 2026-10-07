// 樹直徑: 從任意點找最遠點 a，再從 a 找最遠點 b，dist(a,b) 即直徑。邊權須 >= 0
const int MAXN = 200005;
int n, par_[MAXN];
ll d[MAXN];
vector<pair<int, ll>> g[MAXN]; // 無權樹: w = 1
int farthest(int s) { // BFS 版 (樹上路徑唯一，不必 Dijkstra)，避免遞迴太深
    fill(d, d + n + 1, -1);
    queue<int> q; q.push(s); d[s] = 0; par_[s] = 0;
    int best = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (d[u] > d[best]) best = u;
        for (auto [v, w] : g[u]) if (d[v] == -1) d[v] = d[u] + w, par_[v] = u, q.push(v);
    }
    return best;
}
ll diameter(int &a, int &b) {
    a = farthest(1); b = farthest(a);
    return d[b]; // 路徑: 從 b 沿 par_ 走回 a
}
/* [應用]
- 每個點的最遠距離 = max(dist(v,a), dist(v,b))  (各跑一次 BFS)
- 樹的中心 (最小化最遠距離): 直徑路徑的中點；從一點廣播到全樹的最短時間 = ceil(直徑/2)
*/
