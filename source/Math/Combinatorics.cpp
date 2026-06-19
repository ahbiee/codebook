const long long MOD = 1e9 + 7; // 依照題目給的質數修改

// 【方法一】巴斯卡三角形 (適用於 N <= 2000)
// 優勢：全加法無除法，不怕模數非質數。時間複雜度 O(N^2)
const int MAXC = 2005;
long long C[MAXC][MAXC];

void build_pascal() {
    for (int i = 0; i < MAXC; ++i) {
        C[i][0] = 1; // 從 n 個取 0 個的方法數永遠是 1
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

// 【方法二】階乘與模逆元 (適用於 N <= 10^6，且 MOD 必須是質數)
// 優勢：快速查詢。預處理 O(N)，查詢 O(1)
const int MAXN = 1000005;
long long fact[MAXN], invFact[MAXN];

// 預處理所有數字的階乘與其逆元
void build_fact() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    // 先算出最大數字的逆元，再利用 (i-1)!^-1 = i!^-1 * i 倒推回去，節省 O(N log MOD)
    invFact[MAXN - 1] = fast_pow(fact[MAXN - 1], MOD - 2); // 使用快速冪
    for (int i = MAXN - 2; i >= 1; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// O(1) 查詢組合數
long long nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}