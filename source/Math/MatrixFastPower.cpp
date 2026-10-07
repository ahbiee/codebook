// 線性遞迴 f(n) = c1 f(n-1) + ... + ck f(n-k)，n 到 1e18 → 矩陣快速冪 O(k^3 log n)
const ll MOD = 1e9 + 7;
typedef vector<vector<ll>> Mat;
Mat mul(const Mat &A, const Mat &B) { // (n x k) * (k x m)
    int n = A.size(), k = B.size(), m = B[0].size();
    Mat C(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int t = 0; t < k; t++) if (A[i][t])
            for (int j = 0; j < m; j++) C[i][j] = (C[i][j] + A[i][t] * B[t][j]) % MOD;
    return C;
}
Mat mpow(Mat A, ll p) { // A 必須是方陣
    int n = A.size();
    Mat R(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) R[i][i] = 1; // 單位矩陣
    for (; p; p >>= 1, A = mul(A, A)) if (p & 1) R = mul(R, A);
    return R;
}
/* 例: Fibonacci  [F(n+1)]   [1 1]^n [F(1)]
                  [F(n)  ] = [1 0]   [F(0)]  → F(n) = mpow({{1,1},{1,0}}, n)[1][0]
   一般 k 階: 第一列放係數 c1..ck，下面是單位矩陣往下平移一格
   有常數項 +d: 狀態向量多放一個 1，矩陣多一行一列
   圖上「恰好走 k 步」的路徑數 = 鄰接矩陣^k；(min,+) 版本可求恰好 k 步最短路 */
