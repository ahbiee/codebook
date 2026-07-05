// JosephusProblem，只是規定要先砍 1 號
// 所以當作有 n - 1 個人，目標的 13 號移成 12
// 再者從 0 開始比較好算，所以目標 12 順移成 11

// O(n)
int getWinner(int n, int k) {
    int winner = 0;
    for (int i = 1; i <= n; ++i)
        winner = (winner + k) % i;
    return winner;
}

int main() {
    int n;
    while (cin >> n && n) {
        --n; // 因為要用 初始idx為 0
        for (int k = 1; k <= n; ++k) {
            if (getWinner(n, k) == 11) { // 依據目標進行修改
                printf("%d\n", k);
                break;
            }
        }
    }

    return 0;
}

// O(k log(n))
int josephus(int n, int k) {
    if (n == 1) return 0;
    if (k == 1) return n - 1;
    if (k > n) return (josephus(n - 1, k) + k) % n;

    int res = josephus(n - n / k, k);
    res -= n % k;
    if (res < 0) res += n;     // 依據需求 mod n
    else res += res / (k - 1); // 還原位置

    return res;
}