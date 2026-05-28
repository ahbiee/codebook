// 計算 (a^b) % mod
// 競賽中 mod 通常為 1e9+7 或 998244353
long long fast_pow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod; // 預防初始底數 a 大於等於 mod
    
    while (b > 0) {
        // 如果當前次方數是奇數，把當前的 a 乘進答案裡
        if (b & 1) res = res * a % mod;
        a = a * a % mod; // 底數平方
        b >>= 1;         // 次方數除以 2
    }
    return res;
}