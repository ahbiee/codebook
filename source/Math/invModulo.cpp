// 需要 fast_pow。p 必須是質數且 a % p != 0；不是質數請用 exGCD 版
ll inv(ll a, ll p) { return fast_pow(a, p - 2, p); }
ll mod_div(ll a, ll b, ll p) { return (a % p + p) % p * inv(b, p) % p; } // (a/b) % p

// O(N) 建 1~n 的逆元表 (p 質數, n < p)
const int MAXN = 1000005;
ll invt[MAXN];
void build_inv(int n, ll p) {
    invt[1] = 1;
    for (int i = 2; i <= n; i++) invt[i] = (p - p / i) * invt[p % i] % p;
}
// 減法取模記得: ((a - b) % p + p) % p
