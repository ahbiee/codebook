// (a^b) % mod，mod 常為 1e9+7 或 998244353
ll fast_pow(ll a, ll b, ll mod) {
    ll res = 1; a %= mod;
    if (a < 0) a += mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;   // mod > 3e9 時改 (__int128)res * a % mod
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// 費馬小定理降冪: p 質數、gcd(a,p)=1 時 a^b = a^(b mod (p-1)) (mod p)
// 歐拉降冪 (一般 m): b >= phi(m) 時 a^b = a^(b mod phi(m) + phi(m)) (mod m)
