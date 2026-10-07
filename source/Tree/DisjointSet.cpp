const int MAXN = 200005;
int f[MAXN], sz[MAXN];
void init(int n) { for (int i = 0; i <= n; i++) f[i] = i, sz[i] = 1; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); } // 路徑壓縮
bool unite(int a, int b) { // 回傳是否真的合併 (Kruskal 判環用)
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b); // 小掛大
    f[b] = a; sz[a] += sz[b];
    return true;
}
/* [變形]
1. 集合大小: sz[find(x)]；集合個數: 一開始 n，每次 unite 成功就 -1
2. 帶權 DSU (x 到根的距離/差值 w[x])，find 時累加:
   int find(int x){ if(f[x]==x) return x; int r=find(f[x]); w[x]+=w[f[x]]; return f[x]=r; }
   (此時 find 不能先改 f[x]：要先存 root 再加 w，如上)
3. 二分圖/敵人關係: 開 2n 個點，x 與 y 敵對 → unite(x, y+n), unite(x+n, y)
4. 「下一個可用位置」(跳過已刪除): 刪 i 時 f[i] = i+1，find(i) 即右邊第一個沒刪的
5. 離線刪邊 → 反過來變成加邊
*/
