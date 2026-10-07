// 1-based！n = 上界。每筆測資: fill(bit, bit+n+1, 0)
const int MAXN = 200005;
int n;
ll bit[MAXN];
void add(ll *t, int x, ll v) { for (; x <= n; x += x & -x) t[x] += v; }
ll sum(ll *t, int x) { ll r = 0; for (; x > 0; x -= x & -x) r += t[x]; return r; }
// 基本用法: 單點加 add(bit,i,v)；區間和 sum(bit,r) - sum(bit,l-1)

// [變形1] 區間加 + 單點查: 對差分建 BIT
//   add(bit,l,v); add(bit,r+1,-v);  a[x] = sum(bit,x)
// [變形2] 區間加 + 區間和: 兩棵 BIT
ll B1[MAXN], B2[MAXN];
void range_add(int l, int r, ll v) {
    add(B1, l, v); add(B1, r + 1, -v);
    add(B2, l, v * (l - 1)); add(B2, r + 1, -v * r);
}
ll pre(int x) { return sum(B1, x) * x - sum(B2, x); }
ll range_sum(int l, int r) { return pre(r) - pre(l - 1); }

// [變形3] 第 k 小: bit 存「值 x 出現幾次」，回傳最小 x 使 sum(bit,x) >= k
int kth(ll k) {
    int pos = 0;
    for (int pw = 1 << __lg(n); pw; pw >>= 1)
        if (pos + pw <= n && bit[pos + pw] < k) pos += pw, k -= bit[pos];
    return pos + 1; // 回傳 n+1 代表總數 < k
}
// [變形4] 逆序對: 值先壓縮到 1..n，i=1..n 由左往右:
//   ans += (i-1) - sum(bit, a[i]); add(bit, a[i], 1);   // 前面比 a[i] 大的個數
