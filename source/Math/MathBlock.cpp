// Σ_{i=1..n} floor(n/i)，O(sqrt N)。同一個區塊 [l, r] 的 n/i 都相同
ll math_block(ll n) {
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);          // 與 l 商相同的最右邊界
        ans += (r - l + 1) * (n / l); // [改] Σ f(i)*floor(n/i): 改成 (F(r)-F(l-1))*(n/l)，F 為 f 的前綴和
    }
    return ans;
}
// 兩個: Σ floor(n/i)*floor(m/i) → r = min(n/(n/l), m/(m/l))，l 跑到 min(n,m)
// 只要 i 在 1..k (k<n): r = min(r, k)
