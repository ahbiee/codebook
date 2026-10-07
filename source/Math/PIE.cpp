// 排容: 1~n 中能被 ps 中「至少一個」整除的個數。O(2^m * m)
ll inclusion_exclusion(ll n, const vector<ll> &ps) {
    int m = ps.size();
    ll ans = 0;
    for (int mask = 1; mask < (1 << m); mask++) {
        ll l = 1; int bits = 0;
        for (int i = 0; i < m && l <= n; i++)
            if (mask >> i & 1) {
                bits++;
                l = (l > n / ps[i]) ? n + 1 : l * ps[i]; // [改] 不是質數要用 lcm；防溢位
            }
        if (l > n) continue;
        ans += (bits & 1) ? n / l : -(n / l); // 奇加偶減
    }
    return ans;
}
/* 1~n 與 K 互質的個數 = n - inclusion_exclusion(n, K 的質因數)
   錯排 D(n) = (n-1)(D(n-1)+D(n-2))，D(1)=0, D(2)=1
   「每個條件都不滿足」= 總數 - 至少滿足一個；「恰好 k 個」可用二項式反演 */
