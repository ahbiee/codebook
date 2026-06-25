long long inv(long long a, long long mod) {
    return fast_pow(a, mod - 2, mod);
}

// 應用範例：計算 (a / b) % mod
long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * inv(b, mod) % mod;
}
