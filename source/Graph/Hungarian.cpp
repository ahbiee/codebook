#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30005; // 依題目需求調整右側/左側最大點數
int n, m, e;              // n: 左側點數, m: 右側點數
vector<int> G[MAXN];   // G[u] 存左側點 u 連向右側的哪些點
int L[MAXN];         // L[v] 記錄右側點 v 配對到的左側點
bool T[MAXN];          // T[v] 記錄右側點 v 在單次 DFS 中是否已拜訪

bool match(int u) { // 核心 DFS：幫左側點 u 尋找增廣路徑
    for (int v : G[u]) {
        if (T[v]) continue; 
        T[v] = true;
        
        // 若右側點 v 還沒選對象，或其原本對象可以讓出位子
        if (L[v] == -1 || match(L[v])) {
            L[v] = u; // 配對成功
            return true;
        }
    }
    return false;
}

int solve() { // 執行最大匹配
    int ans = 0;
    memset(L, -1, sizeof(L)); // 依照需求假設點編號為 0-based 或 1-based
    
    // 假設左側點編號為 1 ~ n (若為 0 ~ n-1 請自行改迴圈範圍)
    for (int i = 1; i <= n; ++i) {
        memset(T, false, sizeof(T));
        if (match(i)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    while (cin >> n >> m){
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
        }
        
        int u, v; // 讀取每個邊，存到adjacency list中
        for (int i = 0; i < e; ++i) {
            cin >> u >> v;
            G[u].push_back(v); 
        }
        
        // 依照需求做更改，這裡的範例是: 找到的最大匹配數等於邊的數量，即完成最大匹配
        if(solve() == e) cout << "YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}