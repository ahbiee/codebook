// 全部 1-based，讓 index 0 當作 0，免判斷邊界
const int MAXN = 1005;
int n, m;
ll a[MAXN], pre[MAXN];               // 1D
ll A[MAXN][MAXN], P[MAXN][MAXN];     // 2D
ll d[MAXN], D[MAXN][MAXN];           // 差分

void build1() { for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i]; } // [改] XOR: ^
ll query1(int l, int r) { return pre[r] - pre[l - 1]; }                     // XOR: pre[r]^pre[l-1]

void build2() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + A[i][j];
}
ll query2(int x1, int y1, int x2, int y2) { // 左上 (x1,y1) 右下 (x2,y2)
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
}

// 1D 差分: 大量「區間加」，最後才查
void add1(int l, int r, ll v) { d[l] += v; d[r + 1] -= v; }
void restore1() { for (int i = 1; i <= n; i++) d[i] += d[i - 1]; } // 之後 a[i] += d[i]

// 2D 差分
void add2(int x1, int y1, int x2, int y2, ll v) {
    D[x1][y1] += v; D[x2 + 1][y1] -= v; D[x1][y2 + 1] -= v; D[x2 + 1][y2 + 1] += v;
}
void restore2() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
}
/* [變形]
- 子陣列和 = k 的個數 (有負數): map<ll,int> cnt; cnt[0]=1; 每步 ans += cnt[pre-k]; cnt[pre]++
- 子陣列和可被 k 整除: 同上，key 改成 ((pre%k)+k)%k
- 最長和為 0 的子陣列: 記錄每個 pre 值「第一次出現」的位置
*/
