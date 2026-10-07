// 求 ax + by = gcd(a,b) 的一組解，回傳 gcd
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
/* 解 ax + by = c: g = gcd(a,b)，c % g != 0 → 無解
   否則 x0 = x*(c/g), y0 = y*(c/g)；通解 x = x0 + k*(b/g), y = y0 - k*(a/g)
   最小非負 x: t = b/g; x = (x0 % t + t) % t  (注意 x*(c/g) 可能溢位 → __int128) */

// 模逆元 (m 不必是質數)，不存在回傳 -1
ll inverse(ll a, ll m) {
    ll x, y;
    if (extgcd(a, m, x, y) != 1) return -1;
    return (x % m + m) % m;
}
