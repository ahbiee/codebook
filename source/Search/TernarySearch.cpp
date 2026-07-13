// 目標函數：根據題目需求實作 (此處以尋找單谷函數(U型, 二次曲線)的最小值為例)
double f(double x) {
    return x * x - 4 * x + 4; // x^2 - 4x + 4
}

// 浮點數三分搜 
double ternary_search_double(double L, double R) {
    // 浮點數一律固定跑 100~200 次 可以保證不會有無窮迴圈與精度問題
    for (int i = 0; i < 100; ++i) {
        double m1 = L + (R - L) / 3.0;
        double m2 = R - (R - L) / 3.0;
        
        // 若找最小值：如果 f(m1) > f(m2)，代表真正的底谷一定在 m1 的右邊
        // (若題目為尋找單峰函數的【最大值】，將 > 改成 < 即可)
        if (f(m1) > f(m2)) L = m1;
        else R = m2;
    }
    return f(L);
}

// 整數三分搜 (尋找單谷函數的最小值)
long long ternary_search_int(long long L, long long R) {
    while (R - L > 2) { // 當區間大於 2 時才進行三分搜
        long long m1 = L + (R - L) / 3;
        long long m2 = R - (R - L) / 3;
        if (f(m1) > f(m2)) L = m1;
        else R = m2;
    }
    // 區間縮小到 2 以內時，直接暴力枚舉 L ~ R 找極值，完美避開死迴圈
    long long ans = f(L);
    for (long long i = L + 1; i <= R; ++i) {
        ans = min(ans, f(i)); // 若找最大值，改用 max
    }
    return ans;
}