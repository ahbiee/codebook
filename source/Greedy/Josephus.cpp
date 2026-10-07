// n 個人 (編號 0..n-1) 圍圈，每數到第 k 個就淘汰，回傳最後存活者編號 (0-based)
int josephus(int n, int k) { // O(n)：J(1)=0, J(i) = (J(i-1) + k) % i
    int w = 0;
    for (int i = 1; i <= n; i++) w = (w + k) % i;
    return w;
}
ll josephus_fast(ll n, ll k) { // O(k log n)，n 很大 (1e18) 但 k 小時用
    if (n == 1) return 0;
    if (k == 1) return n - 1;
    if (k > n) return (josephus_fast(n - 1, k) + k) % n;
    ll res = josephus_fast(n - n / k, k) - n % k;
    if (res < 0) res += n;
    else res += res / (k - 1);
    return res;
}
/* 變形 (UVa 151 Power Crisis): 一定先淘汰 1 號，再每 k 個淘汰一個，求讓 13 號最後存活的最小 k
   → 1 號先淘汰後剩 n-1 人，從 2 號開始重新編號 0..n-2，13 號變成 11
   for k = 1..: if (josephus(n - 1, k) == 11) 答案為 k
   要知道「第 m 個被淘汰的人」: 用 ordered_set / BIT 第 k 小模擬，O(n log n) */
