// 1. 單次質數檢驗
// 適用時機：只詢問極少數幾個數字，且數字可能很大 (<= 1e14)
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // 效能優化：除了 2 和 3，質數一定出現在 6k-1 或 6k+1
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// =======================================================

// 2. 埃拉托斯特尼篩法 (Sieve of Eratosthenes)
// 適用時機：需要大量查詢 1 ~ 10^7 內的質數
const int MAXN = 1e7 + 10;
vector<int> primes;
bool is_prime[MAXN];

void sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i); // 收集質數
            
            // 重要優化：從 i * i 開始篩，因為 i * 2, i * 3... 在之前已經被 2, 3... 篩過了
            // 注意型態轉型避免 i * i 爆 int
            for (long long j = (long long)i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}