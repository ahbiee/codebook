/* 斜率優化 DP: 轉移長得像 dp[i] = min_j ( m_j * x_i + b_j ) + c_i
   → 每個 j 是一條直線 y = m_j x + b_j，求在 x_i 的最小值 → 李超線段樹
   x 的範圍 [XL, XR] 要是整數 (太大先壓縮)。O(log C) 每次插入/查詢 */
const ll INF = 4e18;
const int XL = 0, XR = 100000;                  // [改] x 的範圍 (到 1e6 時約 64MB)
const int MAXNODE = 4 * (XR - XL + 1);
ll lm[MAXNODE], lb[MAXNODE];                    // 節點存的直線 y = lm*x + lb
bool has[MAXNODE];
ll f(int id, ll x) { return lm[id] * x + lb[id]; }
void insert_line(ll m, ll b, int id = 1, int l = XL, int r = XR) {
    if (!has[id]) { lm[id] = m; lb[id] = b; has[id] = true; return; }
    int mid = l + (r - l) / 2;
    bool lef = m * l + b < f(id, l), md = m * mid + b < f(id, mid); // [改] 求 max: < 改 >
    if (md) swap(lm[id], m), swap(lb[id], b);   // 節點保留在 mid 比較好的線
    if (l == r) return;
    if (lef != md) insert_line(m, b, id * 2, l, mid);
    else insert_line(m, b, id * 2 + 1, mid + 1, r);
}
ll query(ll x, int id = 1, int l = XL, int r = XR) { // x 處所有直線的最小值
    if (!has[id]) return INF;                    // [改] 求 max: -INF
    int mid = l + (r - l) / 2;
    ll res = f(id, x);
    if (l == r) return res;
    if (x <= mid) return min(res, query(x, id * 2, l, mid)); // [改] max
    return min(res, query(x, id * 2 + 1, mid + 1, r));      // [改] max
}
/* 用法: dp[0] = 0; insert_line(m_0, b_0);
   for i: dp[i] = query(x_i) + c_i; insert_line(m_i, b_i);  (m_i, b_i 由 dp[i] 算出)
   例: dp[i] = min_j dp[j] + (s_i - s_j)^2 → 展開: s_i^2 + min_j(-2 s_j * s_i + dp[j] + s_j^2)
       直線 m = -2 s_j, b = dp[j] + s_j^2，查 x = s_i
   多筆測資: fill(has, has + MAXNODE, false) */
