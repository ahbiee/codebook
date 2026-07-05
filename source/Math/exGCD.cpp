/*
應用場景:
1. 題目要求解 ax + by = gcd(a, b)
2. 題目要求你算「模逆元 (Modular Inverse)」，但是模數 p 不是質數。

對於 ax + by = c，若 gcd(a, b) 不能整除 c (c不是他的倍數)，就代表沒有整數解
否則，設g = gcd(a, b)，先解出基本解 x', y'
*/
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// 萬能模逆元：求 a 在 mod m 之下的逆元 (無論 m 是否為質數皆可)，-1表示不存在
long long inverse(long long a, long long m) {
    long long x, y;
    long long g = extgcd(a, m, x, y);
    if (g != 1) return -1; // 不互質，無解
    return (x % m + m) % m; // 確保回傳正數
}
