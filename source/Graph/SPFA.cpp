#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const long long INF = 1e18;

struct Edge { 
    int v; 
    long long w; 
};

vector<Edge> G[MAXN]; // adjacency list存圖
long long dist[MAXN]; // 起點到任意點的距離
int n, m; // n個點, m個邊

bool SPFA(int start) { // 回傳 false 代表圖中存在負環；回傳 true 代表最短路徑計算成功
    bool inq[MAXN]; // inq[i] 記錄點 i 目前是否在 queue 裡面
    int cnt[MAXN];  // cnt[i] 記錄點 i 進入 queue 的總次數
    queue<int> q;

    fill(dist, dist + n + 1, INF);
    memset(inq, false ,sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    
    dist[start] = 0; // 從start節點開始
    q.push(start);
    inq[start] = true;
    cnt[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false; // 拿出來後就不在 queue 裡了

        for (auto& edge : G[u]) {
            int v = edge.v;
            long long w = edge.w;

            // 鬆弛操作 (relax)
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                
                // 如果被鬆弛的點不在 queue 裡面，就把它加進去
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    cnt[v]++;
                    
                    if (cnt[v] >= n) return false; // 【關鍵】一個點入隊次數 >= n (點總數)，必定有負環
                }
            }
        }
    }
    return true; 
}