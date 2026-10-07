// phi(n) = 1~n 中與 n 互質的個數，O(sqrt N)
ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        while (n % i == 0) n /= i;
        res -= res / i; // res *= (1 - 1/i)
    }
    if (n > 1) res -= res / n;
    return res;
}
// 1~n 全部的 phi，O(N log log N)
const int MAXN = 1000005;
int ph[MAXN];
void phi_table(int n) {
    for (int i = 0; i <= n; i++) ph[i] = i;
    for (int i = 2; i <= n; i++)
        if (ph[i] == i) // i 是質數
            for (int j = i; j <= n; j += i) ph[j] -= ph[j] / i;
}
// 性質: Σ_{d|n} phi(d) = n；1~n 中與 n 互質的數總和 = n*phi(n)/2 (n>1)
// gcd(i,n)=d 的 i 個數 = phi(n/d) → Σ gcd(i,n) = Σ_{d|n} d*phi(n/d)
