// 題型：計算 1 ~ N 中，有幾個數字能被 primes 陣列中的「至少一個」質數整除
long long inclusion_exclusion(long long n, const vector<long long>& primes) {
    int m = primes.size();
    long long ans = 0;
    
    // 利用 Bitmask 枚舉所有可能的子集組合 (1 到 2^m - 1)
    // 例如 m=3，mask 從 001 數到 111
    for (int mask = 1; mask < (1 << m); ++mask) {
        long long lcm_val = 1; // 該子集的最小公倍數
        int bits = 0;          // 紀錄這個子集選了幾個質數 (奇/偶數)
        
        for (int i = 0; i < m; ++i) {
            // 檢查 mask 的第 i 位是否為 1 (代表選了第 i 個質數)
            if ((mask >> i) & 1) {
                bits++;
                lcm_val *= primes[i]; // 質數的 LCM 直接相乘即可
                if (lcm_val > n) break; // 防溢位與無效計算優化
            }
        }
        
        if (lcm_val > n) continue; // 組合出來的條件比 N 還大，裡面絕對沒有倍數
        
        // 排容核心：奇加偶減
        long long count = n / lcm_val; // 滿足此條件的數字個數
        
        if (bits % 2 == 1) {
            ans += count; // 奇數個集合的交集：加
        } else {
            ans -= count; // 偶數個集合的交集：減
        }
    }
    return ans;
}

// 變體應用：若題目問「1 ~ N 中與 K 互質的數有幾個？」
// 解法：先把 K 質因數分解，得到質數陣列 primes。
// 然後用 n 減去 inclusion_exclusion(n, primes) 即為答案。
