// 1. 枚舉所有子集合 (n <= 20)
//    for (int mask = 0; mask < (1 << n); mask++) for (i) if (mask >> i & 1) ... 選了第 i 個
// 2. 枚舉所有排列 (n <= 10): 先 sort，do { ... } while (next_permutation(a.begin(), a.end()));
// 3. 回溯 + 剪枝 (例: N 皇后)
int n, cnt_;
bool col[20], d1[40], d2[40];
void queens(int r) {
    if (r == n) { cnt_++; return; }                   // [改] 找到一組解
    for (int c = 0; c < n; c++) {
        if (col[c] || d1[r + c] || d2[r - c + n]) continue; // 剪枝: 不合法就不往下
        col[c] = d1[r + c] = d2[r - c + n] = true;
        queens(r + 1);
        col[c] = d1[r + c] = d2[r - c + n] = false;   // 回溯: 還原
    }
}
// 剪枝技巧: 目前答案已經比 best 差就 return；先試「比較可能成功」的選項；記憶化相同狀態

// 4. 折半枚舉 (Meet in the middle): n <= 40，子集合和 = target 的個數，O(2^(n/2) * n)
vector<ll> half_sums(const vector<ll> &v) {
    vector<ll> s = {0};
    for (ll x : v) { int k = s.size(); for (int i = 0; i < k; i++) s.push_back(s[i] + x); }
    return s;
}
ll count_subset_sum(const vector<ll> &a, ll target) {
    int h = a.size() / 2;
    vector<ll> L = half_sums(vector<ll>(a.begin(), a.begin() + h));
    vector<ll> R = half_sums(vector<ll>(a.begin() + h, a.end()));
    sort(R.begin(), R.end());
    ll res = 0;
    for (ll x : L) res += upper_bound(R.begin(), R.end(), target - x) - lower_bound(R.begin(), R.end(), target - x);
    return res; // [改] 最接近 target: 對每個 x 在 R 中 lower_bound 找最近的
}
