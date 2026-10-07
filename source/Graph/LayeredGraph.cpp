/* 分層圖 / 狀態圖：題目在最短路上「多一個條件」時用
   核心: 狀態 = (點, 額外資訊)。把每個狀態當成一個新的點，演算法本身不用改！
   例 (NCPC 型): 最多 K 次可以讓一條邊免費 → 狀態 (v, 已用次數 k)
     (u,k) → (v,k)   權 w   : 正常走
     (u,k) → (v,k+1) 權 0   : 用一次特權 (k < K)
   答案 = min over k of dist(t, k)
*/
// 方法一 (推薦): 直接建出大圖，然後呼叫原本的 Dijkstra (Dijkstra 的 MAXN 要開 >= N*(K+1)+1)
int N, K; // 原圖點數 (1-based)、特權次數
int id(int v, int k) { return k * N + v; }
void build_layered(const vector<array<ll, 3>> &edges) { // 原圖的邊 {u, v, w}
    n = N * (K + 1); // Dijkstra 用的 n 變成「狀態總數」
    for (int i = 0; i <= n; i++) g[i].clear();
    for (auto [u, v, w] : edges)
        for (int k = 0; k <= K; k++) {
            g[id(u, k)].push_back({id(v, k), w});                // [改] 同層轉移
            if (k < K) g[id(u, k)].push_back({id(v, k + 1), 0}); // [改] 跨層轉移 (折半: w/2)
            // 無向圖: 反方向 (v→u) 也要加同樣兩條
        }
}
// 用法: build_layered(edges); dijkstra(id(s, 0));
//       ll ans = INF; for (k = 0..K) ans = min(ans, dist[id(t, k)]);  [改] 必須恰好用 K 次 → 只看 k = K

// 方法二: 狀態放在 dist 的第二維 (狀態太多、或轉移是「當場算出來」時，例如網格+鑰匙)
const int MAXV = 100005, MAXK = 11;
ll ds[MAXV][MAXK];
vector<pair<int, ll>> adj[MAXV];
void state_dijkstra(int s) {
    for (int i = 0; i <= N; i++) fill(ds[i], ds[i] + K + 1, INF);
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    ds[s][0] = 0; pq.push({0, s, 0});
    auto relax = [&](int v, int k, ll nd) { if (nd < ds[v][k]) ds[v][k] = nd, pq.push({nd, v, k}); };
    while (!pq.empty()) {
        auto [d, u, k] = pq.top(); pq.pop();
        if (d > ds[u][k]) continue;
        for (auto [v, w] : adj[u]) {
            relax(v, k, d + w);              // [改] 一般轉移
            if (k < K) relax(v, k + 1, d);   // [改] 特殊轉移
        }
    }
}
/* 常見的「額外資訊」(狀態數 × 轉移數 要 <= 約 1e7~1e8):
   | 題目條件                     | 狀態                 |
   | 最多 K 次免費/折扣/瞬移      | (v, 已用次數)        |
   | 收集鑰匙開門 (鑰匙 <= 10 種) | (x, y, 鑰匙 bitmask) |
   | 油箱容量 C、加油站           | (v, 剩餘油量)        |
   | 紅綠燈/週期 T 的時間限制     | (v, 時間 mod T)      |
   | 走奇數/偶數步、交替顏色邊    | (v, 奇偶 / 上一條邊顏色) |
   | 轉彎次數、不能連續同方向     | (x, y, 方向)         |
   | 是否經過特定點/是否已用技能  | (v, 0/1)             |
   邊權全 1 → BFS；只有 0/1 → 0-1 BFS；一般非負 → Dijkstra
   狀態之間若是 DAG (例如 k 只會增加且同層無環) 也可以直接 DP
*/
