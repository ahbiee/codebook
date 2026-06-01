struct DFS{
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;

    void init(int _n) {
        n = _n;
        adj.assign(n + 1, vector<int>());
        vis.assign(n + 1, false);
        subtree_size.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 無向圖就兩個都加
    }

    // 基礎 DFS：走訪與找連通塊
    void dfs(int u) {
        vis[u] = true;
        // 如有需要，處理抵達 u 時的邏輯 (Pre/In/Post-order)
        
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    }
};

/*
補充1:
當題目節點數量 N <= 10，需要找一條 "最短路徑"，且每個邊的最大degree只有2
可以使用 DFS 進行枚舉，從各個節點開始跑，對所有可能的路徑跑DFS
邊跑邊更新最長路徑答案，跑完是 O(N!) -> N=10 -> 小於400萬，能跑
*/

/*
補充2:
如果發現題目要找樹的直徑時，可以使用兩次dfs求解
如: 樹上最遠兩點距離? 從一個人開始通知，每秒傳到相鄰節點，最短多久可以全收到? 路徑唯一最長鏈?
*/
vector<int> adj[MAXN];
int max_dist;
int farthest_node;

void dfs(int cur, int parent, int dist){
    if(dist > max_dist){
        max_dist = dist;
        farthest_node = cur;
    }
    for(int &next : adj[cur]){
        if(next != parent) dfs(cur->next, cur, dist+1);
    }
}

void solve(){
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; ++i){ // 讀入圖
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    max_dist = -1;
    dist(1, -1, 0); // 一開始從任意點第一次DFS

    int first_farthest = farthest_node;
    max_dist = -1;
    dist(first_farthest, -1, 0);
    // 最長距離為max_dist, 點:first_farthest, farthest_node
}