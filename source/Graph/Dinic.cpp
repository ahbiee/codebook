#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 1005; // 依據題目點數調整
const long long INF = 1e18;

// 儲存邊的結構
struct Edge {
    int to;
    long long cap, flow;
    int rev; // 紀錄這條邊的「反向邊」在對方 adj 陣列裡的位置 (index)
};

vector<Edge> adj[MAXV];
int level[MAXV]; // BFS 分層圖，紀錄起點到該點的距離
int ptr[MAXV];   // 【當前弧優化】紀錄 DFS 目前探索到哪條邊，避免走廢邊
int n, s, t;     // 總點數, 源點(Source), 匯點(Sink)

// 加入一條有向邊 (若是無向邊，請再呼叫一次反方向，或直接把反向邊的 cap 也設為 w)
void add_edge(int from, int to, long long w) {
    adj[from].push_back({to, w, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

// 1. BFS 建立分層圖
bool bfs() {
    fill(level, level + n + 1, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            // 如果這條邊還有剩餘容量，且終點還沒被分層
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1; // 回傳是否還能走到匯點 T
}

// 2. DFS 尋找增廣路徑並推播流量
long long dfs(int v, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;

    // 利用 ptr[v] 紀錄上次走到哪一條邊，這是 Dinic 不會 TLE 的關鍵！
    // 注意 cid 必須宣告為 reference (&) 才能真正更新 ptr 陣列
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;

        // 條件：只能往下一層走，且邊要有剩餘容量
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;

        long long push = dfs(tr, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;

        // 更新正向與反向邊的流量
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

// 主函式：計算最大流
long long dinic(int _n, int _s, int _t) {
    n = _n; s = _s; t = _t;
    long long flow = 0;
    
    // 只要還能走到匯點，就持續建分層圖
    while (bfs()) {
        fill(ptr, ptr + n + 1, 0); // 每次重新分層後，DFS 指標要歸零
        
        // 在同一層圖中，盡可能把所有增廣路徑榨乾
        while (long long pushed = dfs(s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

// 若有多筆測資，請記得在 main 裡面先跑：
// for(int i = 0; i <= n; ++i) adj[i].clear();
