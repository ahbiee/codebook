// n! 中質數 p 的次數 = Σ floor(n / p^k)，O(log_p n)
ll legendre(ll n, ll p) {
    ll ans = 0;
    while (n) n /= p, ans += n;
    return ans;
}
// C(n,k) 中 p 的次數
ll c_vp(ll n, ll k, ll p) { return legendre(n, p) - legendre(k, p) - legendre(n - k, p); }
/* 用途: n! 尾端 0 的個數 = legendre(n, 5)
   m 是否整除 n!: 把 m 質因數分解，每個 p^e 檢查 legendre(n,p) >= e
   n! 在 b 進位的尾 0: b = Π p^e → min( legendre(n,p) / e ) */
