// 應用場景： 題目問你「在 1 ~ N 裡面，有幾個數字跟 N 互質？」。
long long phi(long long n) {
    long long res = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // 發現質因數 i，套用公式 res = res * (1 - 1/i)
            while (n % i == 0) n /= i;
            res -= res / i; 
        }
    }
    // 如果 n 本身最後剩下一個大於 sqrt(n) 的質數
    if (n > 1) res -= res / n;
    return res;
}
