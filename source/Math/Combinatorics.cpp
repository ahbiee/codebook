const ll MOD = 1e9 + 7; // [改] 依題目
// 一、帕斯卡三角形 (n <= 5000)：只有加法，MOD 不是質數也能用
const int MAXC = 2005;
int C[MAXC][MAXC];
void build_pascal() {
    for (int i = 0; i < MAXC; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}
// 二、階乘 + 逆元 (n <= 1e6)，MOD 必須是質數。需要 fast_pow
const int MAXN = 1000005;
ll fact[MAXN], ifact[MAXN];
void build_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    ifact[MAXN - 1] = fast_pow(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 1; i > 0; i--) ifact[i - 1] = ifact[i] * i % MOD;
}
ll nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
// 三、Lucas: n,k 很大 (1e18) 但質數 p 小 (<= 1e6)。要先把 MOD 設成 p 再 build_fact
ll lucas(ll n, ll k, ll p) {
    if (k == 0) return 1;
    return nCr(n % p, k % p) * lucas(n / p, k / p, p) % p;
}
// 四、n 小 k 小但不取模: C(n,k) 用 res = res * (n-i) / (i+1) 逐步算 (先乘後除會整除)
