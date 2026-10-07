// 最小費用最大流 (SPFA 找最便宜的增廣路)。邊 e 的反向邊是 e ^ 1
const int MAXN = 5005, MAXE = 100005;
const ll INF = 1e18;
int n, ecnt, to[MAXE], pe[MAXN];
ll cap[MAXE], cost[MAXE], dist[MAXN];
bool inq[MAXN];
vector<int> g[MAXN];
void init(int _n) { n = _n; ecnt = 0; for (int i = 0; i <= n; i++) g[i].clear(); }
void add_edge(int u, int v, ll c, ll w) { // 容量 c、單位費用 w
    to[ecnt] = v; cap[ecnt] = c; cost[ecnt] = w; g[u].push_back(ecnt++);
    to[ecnt] = u; cap[ecnt] = 0; cost[ecnt] = -w; g[v].push_back(ecnt++);
}
pair<ll, ll> mcmf(int s, int t) { // {最大流, 最小費用}
    ll flow = 0, tot = 0;
    while (true) {
        fill(dist, dist + n + 1, INF); fill(inq, inq + n + 1, false);
        queue<int> q; q.push(s); dist[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); inq[u] = false;
            for (int e : g[u]) if (cap[e] > 0 && dist[u] + cost[e] < dist[to[e]]) {
                dist[to[e]] = dist[u] + cost[e]; pe[to[e]] = e;
                if (!inq[to[e]]) inq[to[e]] = true, q.push(to[e]);
            }
        }
        if (dist[t] == INF) break;      // [改] 只要費用最小 (不必最大流): dist[t] >= 0 就 break
        ll f = INF;
        for (int v = t; v != s; v = to[pe[v] ^ 1]) f = min(f, cap[pe[v]]);
        for (int v = t; v != s; v = to[pe[v] ^ 1]) cap[pe[v]] -= f, cap[pe[v] ^ 1] += f;
        flow += f; tot += f * dist[t];
    }
    return {flow, tot};
}
// 最大費用: 費用取負。指派問題 (n 人 n 工作) 也可以用這個或 KM
