bool isPrime(long long n) { // 一、直接查，只問極少次，且數字可能很大 (n<= 1e14)
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 二、質數表，大量查詢 1 ~ 10^7 內的質數
const int MAXN = 1e7 + 10;
vector<int> primes;
bool is_prime[MAXN];

void build(int n) {
    fill(is_prime, is_prime + n + 1, true); // 初始化全設為true
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i); // 放到primes vector中記錄

            for (ll j = (ll)i * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}