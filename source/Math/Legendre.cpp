// n! 中質數 p 的次數
long long Legendre(long long n, long long p) {
    long long ans = 0;
    while (n) {
        n /= p;
        ans += n;
    }
    return ans;
}

// 應用在組合數中
long long Cvp(long long n, long long k, long long p) {
    return Legendre(n, p)
         - Legendre(k, p)
         - Legendre(n - k, p);
}

/*
用途：

n! 中質因數次數
n! trailing zeros (CSES)
判斷 m 是否整除 n!
組合數的質因數次數
*/