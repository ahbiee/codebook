// 單源最短路，邊權 >= 0。O((V+E) log V)
const int MAXN = 200005;
const ll INF = 1e18;
int n, par[MAXN];
ll dist[MAXN], ways[MAXN];
vector<pair<int, ll>> g[MAXN]; // g[u] = {v, w}；無向圖兩邊都加
void dijkstra(int s) {         // [改] 多源: 所有起點 dist = 0 並 push
    fill(dist, dist + n + 1, INF);
    fill(ways, ways + n + 1, 0);
    fill(par, par + n + 1, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // {距離, 點}
    dist[s] = 0; ways[s] = 1; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // 過期的資料
        for (auto [v, w] : g[u]) {
            ll nd = d + w;           // [改] 瓶頸路 (路徑上最大邊最小): nd = max(d, w)
            if (nd < dist[v]) {
                dist[v] = nd; par[v] = u; ways[v] = ways[u];
                pq.push({nd, v});
            } else if (nd == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % 1000000007; // 最短路條數 (邊權需 > 0)
            }
        }
    }
}
vector<int> get_path(int t) { // 先確認 dist[t] != INF
    vector<int> path;
    for (int v = t; v != -1; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}
/* [常見變形]
- 所有點到「同一個終點」: 建反向圖，從終點跑一次
- 必經某點 k: dist(s,k) + dist(k,t)，從 s 和 k 各跑一次
- 某條邊 (u,v,w) 是否在某條最短路上: ds[u] + w + dt[v] == ds[t] (ds 從 s, dt 從 t 在反向圖)
- 點也有權重: 把點權加到「進入該點的邊」上，或拆點 (v_in → v_out 權 = 點權)
- 多一個條件 (次數/時間/燃料/鑰匙...) → 看「分層圖 / 狀態圖」那一節
- 第 K 短路 (可重複點): 每個點最多被 pop K 次，第 K 次 pop 到終點即答案
*/
