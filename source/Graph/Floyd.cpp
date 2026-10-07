// 全點對最短路 O(V^3)，V <= 500。可有負邊 (不可有負環)
const int MAXN = 505;
const ll INF = 1e18;
int n, nxt[MAXN][MAXN];
ll d[MAXN][MAXN];
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i][j] = (i == j ? 0 : INF), nxt[i][j] = j;
}
// 讀邊: d[u][v] = min(d[u][v], w); (重邊取 min！無向圖兩個方向都設)
void floyd() {
    for (int k = 1; k <= n; k++) // k (中繼點) 一定在最外層
        for (int i = 1; i <= n; i++) if (d[i][k] < INF)
            for (int j = 1; j <= n; j++) if (d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                d[i][j] = d[i][k] + d[k][j]; // [改] 瓶頸: max(d[i][k], d[k][j]) 再取 min
                nxt[i][j] = nxt[i][k];       // 路徑還原
            }
}
vector<int> path(int i, int j) { // 需 d[i][j] < INF
    vector<int> p = {i};
    while (i != j) i = nxt[i][j], p.push_back(i);
    return p;
}
/* [變形]
- 有負環: 跑完後 d[i][i] < 0 的點在負環上
- 遞移閉包 (誰能到誰): bool 版 reach[i][j] |= reach[i][k] && reach[k][j]，可用 bitset 加速
- 最小環 (無向): 在 k 迴圈「更新前」先算 min(d[i][j] + w[i][k] + w[k][j])，i<j<k
*/
