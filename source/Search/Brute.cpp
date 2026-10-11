// 1. 枚舉所有子集合 (n <= 20)
//    for (int mask = 0; mask < (1 << n); mask++) for (i) if (mask >> i & 1) ... 選了第 i 個
// 2. 枚舉所有排列 (n <= 10): 先 sort，do { ... } while (next_permutation(a.begin(), a.end()));
// 排列 vs 組合 (先問: 順序重不重要？)
//   排列 N!: 每層 for i = 0..n-1 跳過 used[i]；used[i] = 1; dfs(); used[i] = 0; ← 一定要還原
//   組合 2^N: 只看「選了哪些」→ 下一個只能從 i+1 開始選，或用下面 5. 的選/不選
//   只標記不還原 → 第二個分支起會漏枚舉；組合題寫成排列 → 同一組被走 k! 次而 TLE
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

// 5. 選 / 不選 (分成兩組): 每層只決定第 idx 個放哪，O(2^n)。例: CSES 1623 兩組重量差最小
ll a[45];
ll split(int idx, ll L, ll R) {
    if (idx == n) return llabs(L - R);               // [改] 全部分完才算答案
    return min(split(idx + 1, L + a[idx], R),          // 第 idx 個放左
               split(idx + 1, L, R + a[idx]));         // 第 idx 個放右
}   // 呼叫 split(0, 0, 0)；總和可到 2e10 用 ll；第 0 個固定放左可砍半
// 答案是兩組的差 |L - R| = |total - 2L|，不是 |L - total/2| (total 奇數時整數除法會錯)

// 6. 有重複字母的「相異」排列 (CSES 1622): 記「每個字母還剩幾個」，不記「哪個位置用過」
//    每層從 a 試到 z → 同一層同一個字母只走一次 → 自動去重，產生順序就是字典序 (不用 set)
int cnt[26]; string cur; vector<string> res;  // 先 for (char c : s) cnt[c - 'a']++; n = s.size()
void perm() {
    if ((int)cur.size() == n) { res.push_back(cur); return; }
    for (int i = 0; i < 26; i++) if (cnt[i]) {
        cnt[i]--; cur.push_back('a' + i);  // 共用的狀態「每一個」都要做…
        perm();
        cnt[i]++; cur.pop_back();          // …也都要還原 (只還原字串、沒還原 cnt → 變成可重複選)
    }
}   // 要先輸出總數 → 先存進 res，最後印 res.size() 再印內容
// 傳值 perm(cur + c) 也對 (回來不用 pop)，但每層複製字串；狀態大時用共用 + 還原
// 另解: sort(s) 後 do {...} while (next_permutation(s.begin(), s.end())) 也只產生相異排列
