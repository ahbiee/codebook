const long long MOD = 1e9 + 7; // 依照題目給的質數修改

// 一、帕斯卡三角形 (N <= 2000)，全加法無除法，不怕MOD非質數，O(N^2)
const int MAXN = 2005;
long long C[MAXN][MAXN];

void build_pascal() {
    for (int i = 0; i < MAXN; ++i) {
        C[i][0] = 1; // 從 n 個取 0 個的方法數永遠是 1
        for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}

// 二、階乘與模逆元 (N <= 10^6)，MOD必須是質數，O(N)
long long fact[MAXN], invFact[MAXN];

void build_fact() { // 建表
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
    invFact[MAXN - 1] = fast_pow(fact[MAXN - 1], MOD - 2); // 使用快速冪
    for(int i=MAXN-2;i >= 1; --i)invFact[i]=invFact[i + 1] * (i + 1) % MOD;
}

long long nCr(int n, int k) { // 查詢
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}