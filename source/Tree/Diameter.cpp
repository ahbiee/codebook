/*
如果發現題目要找樹的直徑時，可以使用兩次dfs求解 (前提是樹邊權不能是負的)
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