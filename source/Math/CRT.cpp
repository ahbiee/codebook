// 需要 exGCD.cpp 的 extgcd
// 中國剩餘定理 (模數不必互質): x = r[i] (mod m[i])，回傳 {x, lcm}，無解回傳 {-1,-1}
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m) {
    ll R = 0, M = 1;
    for (int i = 0; i < (int)r.size(); i++) {
        ll x, y, g = extgcd(M, m[i], x, y);
        ll diff = ((r[i] - R) % m[i] + m[i]) % m[i];
        if (diff % g) return {-1, -1};
        ll t = m[i] / g;
        ll k = (__int128)(diff / g) * ((x % t + t) % t) % t;
        R += M * k; M *= t;            // M 可能超過 1e18 時要注意
        R = (R % M + M) % M;
    }
    return {R, M};
}
