long long inv(long long a, long long mod) {
    return fast_pow(a, mod - 2, mod);
}

// 應用範例：計算 (a / b) % mod
long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * inv(b, mod) % mod;
}

// 模逆元建表，數論 證略，可以直接查表找模逆元
void build(){
    inv[1] = 1;
    for(int i=2; i<MAXN; ++i){
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
}
