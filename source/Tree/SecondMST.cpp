#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

// 1. 定義邊與 DSU
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

// struct DSU {}; 跟上面的一樣

int n, m; // 點數, 邊數
vector<Edge> edges;

// 2. 尋找次小生成樹
// 回傳值：pair<最小生成樹權重, 次小生成樹權重>
// 若圖不連通或不存在次小生成樹，對應的權重會回傳 -1
pair<long long, long long> second_mst() {
    sort(edges.begin(), edges.end()); // 權重由小到大排序
    
    DSU dsu;
    dsu.init(n);
    long long mst_weight = 0;
    int edge_cnt = 0;
    vector<int> mst_edges; // 紀錄第一次 MST 用到的「邊的 index」

    // Step 1: 求標準 MST 並記錄使用的邊
    for (int i = 0; i < edges.size(); ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst_weight += edges[i].w;
            mst_edges.push_back(i);
            edge_cnt++;
        }
    }
    
    // 如果連第一次 MST 都構建不出來 (圖不連通)
    if (edge_cnt != n - 1) return {-1, -1};

    long long sec_mst_weight = INF;

    // Step 2: 依序拔除 MST 上的每一條邊，嘗試構造新的生成樹
    for (int removed_idx : mst_edges) {
        dsu.init(n); // 每次都要重置並查集
        long long cur_weight = 0;
        int cur_cnt = 0;

        for (int i = 0; i < edges.size(); ++i) {
            if (i == removed_idx) continue; // 【關鍵】禁用這條邊
            
            if (dsu.unite(edges[i].u, edges[i].v)) {
                cur_weight += edges[i].w;
                cur_cnt++;
            }
        }

        // 如果拔掉該邊後，剩下的邊還是能連通所有點 (形成生成樹)
        if (cur_cnt == n - 1) {
            sec_mst_weight = min(sec_mst_weight, cur_weight);
        }
    }

    if (sec_mst_weight == INF) sec_mst_weight = -1; // 不存在次小生成樹
    return {mst_weight, sec_mst_weight};
}