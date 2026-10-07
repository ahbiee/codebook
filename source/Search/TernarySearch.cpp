// 單峰/單谷函數求極值。以「求最小值」為例；求最大值把 > 改成 <、min 改 max
double f(double x) { return (x - 2) * (x - 2); } // [改] 目標函數
double ternary_double(double L, double R) { // 回傳極值所在的 x
    for (int it = 0; it < 200; it++) {
        double m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        if (f(m1) > f(m2)) L = m1; else R = m2;
    }
    return L;
}
ll fi(ll x) { return (x - 2) * (x - 2); } // 整數版目標函數
ll ternary_int(ll L, ll R) { // 回傳最小的函數值
    while (R - L > 2) {
        ll m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        if (fi(m1) > fi(m2)) L = m1; else R = m2;
    }
    ll best = fi(L);
    for (ll x = L + 1; x <= R; x++) best = min(best, fi(x)); // 剩 <= 3 個直接暴力
    return best;
}
// 注意: 函數有「平台」(連續相等的值) 時三分搜可能失敗 → 整數可改二分搜 f(x) 與 f(x+1) 的大小關係
