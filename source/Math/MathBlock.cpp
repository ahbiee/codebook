// 應用場景： 題目要你算從 i ~ N 中 N / i 取下高斯後的總和分數，sum = sum( floor(n / i) ) for i = 1 to n
long long math_block(long long n) {
    long long ans = 0;
    // l 是當前區塊的左邊界，r 是右邊界
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l); // 魔法公式：直接算出與 l 擁有相同 floor(n/i) 值的右邊界
        
        // r - l + 1 是這個區塊的數字個數，(n / l) 是這個區塊共同的商
        ans += (r - l + 1) * (n / l);
    }
    return ans;
}
