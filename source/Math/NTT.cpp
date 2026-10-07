// 多項式乘法 (卷積) mod 998244353，O(N log N)
// 用途: 大數乘法、「兩數和 = k 的配對數」、計數生成函數相乘
const ll P = 998244353, G = 3; // 需要 fast_pow
void ntt(vector<ll> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll w = fast_pow(G, (P - 1) / len, P);
        if (invert) w = fast_pow(w, P - 2, P);
        for (int i = 0; i < n; i += len) {
            ll wn = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = a[i + j + len / 2] * wn % P;
                a[i + j] = (u + v) % P;
                a[i + j + len / 2] = (u - v + P) % P;
                wn = wn * w % P;
            }
        }
    }
    if (invert) {
        ll inv_n = fast_pow(n, P - 2, P);
        for (ll &x : a) x = x * inv_n % P;
    }
}
vector<ll> multiply(vector<ll> a, vector<ll> b) { // 係數須 < P
    int need = a.size() + b.size() - 1, n = 1;
    while (n < need) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
    ntt(a, true);
    a.resize(need);
    return a;
}
// 大數相乘: 每位數字當係數 (反向)，乘完再進位。係數 <= 81 * 長度 < P 才安全
