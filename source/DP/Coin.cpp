#include <iostream>
#include <vector>
using namespace std;

// 題型：給定數種硬幣，求「湊出金額 N 有幾種方法？」 (例如 UVa 357)
// 注意：方法數通常成長得非常快，必定會超過 int，請一律使用 long long！

const int MAX_AMOUNT = 30005; // 依據題目給定的最大金額修改
long long dp[MAX_AMOUNT];
int coins[] = {1, 5, 10, 25, 50}; // 依據題目給定的硬幣種類修改

// 預處理建表：在 main() 迴圈開始前呼叫一次即可
void build_coin_change() {
    // Base case: 湊出金額 0 的方法只有 1 種 (就是所有硬幣都不拿)
    dp[0] = 1;
    
    // 【核心陷阱：必須先枚舉硬幣，再枚舉金額】
    // 這樣求出來的才是「組合數」(1+5 和 5+1 視為同一種方法)
    for (int coin : coins) {
        // 從該硬幣的面額開始往上推，因為金額小於硬幣面額時根本用不到這枚硬幣
        for (int j = coin; j < MAX_AMOUNT; ++j) {
            dp[j] += dp[j - coin]; 
        }
    }
}

/* * 延伸變體：如果題目是求「湊出金額 N 最少需要幾枚硬幣？」
 * 1. 將 dp 陣列初始化為 INF，dp[0] = 0。
 * 2. 轉移方程式改為：dp[j] = min(dp[j], dp[j - coin] + 1);
 */
