// 64-bit 質數判斷 (確定性) + Pollard Rho 分解，N <= 1e18
ll mul(ll a, ll b, ll m) { return (__int128)a * b % m; }
ll pw(ll a, ll b, ll m) { ll r = 1; for (a %= m; b; b >>= 1, a = mul(a, a, m)) if (b & 1) r = mul(r, a, m); return r; }
bool miller_rabin(ll n) {
    if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        if (n % p == 0) return n == p;
    ll d = n - 1; int s = 0;
    while (d % 2 == 0) d /= 2, s++;
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        ll x = pw(a, d, n);
        if (x == 0 || x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int i = 1; i < s && comp; i++) { x = mul(x, x, n); if (x == n - 1) comp = false; }
        if (comp) return false;
    }
    return true;
}
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
ll pollard(ll n) { // 回傳 n 的一個非平凡因數 (n 為合數)
    if (n % 2 == 0) return 2;
    while (true) {
        ll x = rng64() % (n - 2) + 2, y = x, c = rng64() % (n - 1) + 1, d = 1;
        auto f = [&](ll v) { return (mul(v, v, n) + c) % n; };
        while (d == 1) { x = f(x); y = f(f(y)); d = __gcd(abs(x - y), n); }
        if (d != n) return d;
    }
}
void factor(ll n, vector<ll> &res) { // 質因數 (含重複，未排序)
    if (n == 1) return;
    if (miller_rabin(n)) { res.push_back(n); return; }
    ll d = pollard(n);
    factor(d, res); factor(n / d, res);
}
