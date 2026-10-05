// 題型：給定數種硬幣，求「湊出金額 K 的最大方法數」
// 注意：
// 1. 大陣列 (如 1e6) 務必宣告為 Global Variable 或使用 vector，避免 Stack Overflow。
// 2. 方法數成長極快，若無 Modulo 限制，請一律使用 long long。

const int MAXN = 1e6 + 5; // 依照題目給定的最大金額調整
const ll MOD = 1e9 + 7;
ll dp[MAXN]; // 一維dp就夠了，coin儲存在另一個陣

/* 
 * 情境一：【Permutation (排列)】- 順序不同視為不同方法 (如 CSES Coin Combinations I)
 * 例如：2+3 和 3+2 視為兩種不同的湊法。
 * 核心想法：考慮「最後一枚加上的硬幣」是哪一種。
 */
void coin_change_permutation(const vector<int>& coins, int k) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Base case: 湊出 0 元的方法有 1 種
    
    // 【外層迴圈：Target Amount】【內層迴圈：Coins】
    for (int i = 1; i <= k; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }
}

/* 
 * 情境二：【Combination (組合)】- 順序不同視為相同方法 (如 UVa 357, CSES Coin Combinations II)
 * 例如：2+3 和 3+2 視為同一種湊法。
 * 核心想法：強迫硬幣必須「按照特定順序」拿取（先拿完面額 A，才能拿面額 B）。
 */
void coin_change_combination(const vector<int>& coins, int k) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Base case
    
    // 【外層迴圈：Coins】【內層迴圈：Target Amount】
    for (int coin : coins) {
        for (int i = coin; i <= k; ++i) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
}