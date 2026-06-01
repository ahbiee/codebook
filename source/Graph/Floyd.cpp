#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const long long INF = 1e18;
long long dist[MAXN][MAXN];
int n, m;

void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
}

// 注意：讀邊時若為多重邊 (Multigraph, 即 A->B 不只一條direct path)，需寫成 dist[u][v] = min(dist[u][v], w);

void floyd() {
    // 中繼點 k 必須在最外層！
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 必須確認 i->k 和 k->j 都是通的
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}