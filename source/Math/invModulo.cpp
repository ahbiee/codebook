// 模逆元 (Modular Multiplicative Inverse)
// 條件：mod 必須是質數 (利用費馬小定理)
// 應用：計算 (x / y) % mod 等同於計算 (x * inv(y, mod)) % mod
long long inv(long long a, long long mod) {
    return fast_pow(a, mod - 2, mod);
}

// 應用範例：計算 (a / b) % mod
long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * mod_inv(b, mod) % mod;
}
