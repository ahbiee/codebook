// 可有負權邊的單源最短路 + 負環偵測。平均快，最差 O(VE)
const int MAXN = 100005;
const ll INF = 1e18;
int n, cnt_[MAXN];
ll dist[MAXN];
bool inq[MAXN];
vector<pair<int, ll>> g[MAXN];
bool spfa(int s) { // false = 從 s 走得到負環
    fill(dist, dist + n + 1, INF);
    fill(inq, inq + n + 1, false);
    fill(cnt_, cnt_ + n + 1, 0);
    queue<int> q;
    dist[s] = 0; q.push(s); inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (auto [v, w] : g[u]) if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            if (!inq[v]) {
                if (++cnt_[v] >= n) return false; // 入隊 >= n 次 → 負環
                q.push(v); inq[v] = true;
            }
        }
    }
    return true;
}
/* [變形]
- 判斷「整張圖」有沒有負環: 建超級源點 0 連到每個點權 0，從 0 跑 (n 要算進 0 → 用 n+1 判斷)
- 差分約束: 條件 x[v] - x[u] <= w → 邊 u→v 權 w。超級源點 0 → 每點權 0
  有負環 = 無解；否則 dist 就是一組解 (x[v]-x[u] >= w 改寫成 x[u]-x[v] <= -w)
- 最長路: 權重取負後跑最短路 (正環 = 最長路無限大)
*/
