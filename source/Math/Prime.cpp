// 一、單一數字判斷 / 分解，O(sqrt N)，N <= 1e12 可用 (更大用 Miller-Rabin)
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
vector<pair<ll, int>> factorize(ll n) { // {質因數, 次方}
    vector<pair<ll, int>> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int c = 0;
        while (n % i == 0) n /= i, c++;
        res.push_back({i, c});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}
// 二、線性篩 O(N): 質數表 + 最小質因數 spf，N <= 1e7
const int MAXN = 10000005;
int spf[MAXN];
vector<int> primes;
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);
        for (int p : primes) {
            if (p > spf[i] || (ll)i * p > n) break;
            spf[i * p] = p;
        }
    }
}
// 有 spf 後，分解 x 只要 O(log x): while(x > 1){ int p = spf[x]; x /= p; ... }
// 因數個數 = Π(e_i + 1)；因數和 = Π(p^(e+1)-1)/(p-1)
// 區間篩 [L,R] (R 到 1e12, R-L 到 1e6): 用 sqrt(R) 內的質數去劃掉 [L,R] 內的倍數

/* 哥德巴赫: N 最少拆成幾個質數的和
   N 是質數 → 1；N 偶數 (N>2) → 2；N 奇數且 N-2 是質數 → 2；其他 → 3 */
