const int MAXN = 200005; // 依N大小變動
const int LOG = 20; // LOG = floor(ln(N))+1，在 N=10^6 範圍時，20就夠了
int st[MAXN][LOG];

// 建表 (以區間最大值為例)
void build_ST(int n, const vector<int>& a) {
    for(int i = 0; i < n; i++) st[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

// 查詢 [L, R]
int query(int L, int R) {
    int j = __lg(R - L + 1);
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}