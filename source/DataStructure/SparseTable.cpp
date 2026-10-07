// 靜態 (不會修改) 區間 max/min/gcd 查詢。0-based
const int MAXN = 200005, LOG = 18; // 2^LOG > MAXN 即可 (1e6 用 20)
int st[LOG][MAXN];
void build(int n, int *a) {
    for (int i = 0; i < n; i++) st[0][i] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]); // [改] min/gcd
}
int query(int l, int r) { // [l, r]
    int j = __lg(r - l + 1);
    return max(st[j][l], st[j][r - (1 << j) + 1]); // [改]
}
// 注意: 只能用在「重疊不影響答案」的運算 (max/min/gcd/and/or)，sum 不行
