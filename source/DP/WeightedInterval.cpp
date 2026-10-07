/* 加權區間排程: n 個工作 {開始 s, 結束 e, 獎勵 r}，選出互不衝突的工作使獎勵和最大，並輸出選了哪些
   (沒有獎勵、只求最多幾個 → Greedy「最多不重疊區間」即可)
   作法: 依結束時間排序。dp[i] = 只看前 i 個工作 (排序後) 的最大獎勵
     dp[i] = max( dp[i-1],            不選第 i 個
                  dp[p[i]] + r[i] )    選第 i 個，p[i] = 排序後「結束時間不衝突」的工作有幾個
   p[i] 用二分搜在排好序的結束時間 ed[] 中找。O(N log N) */
const int MAXN = 200005;
int n, id_[MAXN], p[MAXN];
ll s[MAXN], e[MAXN], r[MAXN], ed[MAXN], dp[MAXN];
bool TOUCH_OK = true; // [改] true : 端點相接不算衝突 (e == 下一個的 s 可以接著做)
                      //       false: 端點相接也算衝突 (必須 e < 下一個的 s)
ll weighted_interval(vector<int> &chosen) { // 輸入 s[1..n], e[1..n], r[1..n]；chosen 回傳原始編號 (1-based)
    for (int i = 1; i <= n; i++) id_[i] = i;
    sort(id_ + 1, id_ + n + 1, [](int a, int b) { return make_pair(e[a], s[a]) < make_pair(e[b], s[b]); }); // 依結束時間排序 (同時結束再比開始)
    for (int i = 1; i <= n; i++) ed[i] = e[id_[i]];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll st = s[id_[i]];
        if (TOUCH_OK) p[i] = upper_bound(ed + 1, ed + i, st) - (ed + 1); // 結束 <= st 的個數
        else          p[i] = lower_bound(ed + 1, ed + i, st) - (ed + 1); // 結束 <  st 的個數
        dp[i] = max(dp[i - 1], dp[p[i]] + r[id_[i]]);
    }
    chosen.clear(); // 回溯: dp[i] == dp[i-1] 代表沒選第 i 個，否則選了它並跳到 p[i]
    for (int i = n; i > 0;) {
        if (dp[i] == dp[i - 1]) i--;
        else chosen.push_back(id_[i]), i = p[i];
    }
    sort(chosen.begin(), chosen.end()); // [改] 要依時間順序輸出: 改成依 s 排序
    return dp[n];
}
int main() { // 輸入: n，接著 n 行 s e r；輸出最大獎勵與選的工作編號
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i] >> e[i] >> r[i];
    vector<int> chosen;
    cout << weighted_interval(chosen) << '\n';
    for (int i = 0; i < (int)chosen.size(); i++) cout << chosen[i] << " \n"[i + 1 == (int)chosen.size()];
    return 0;
}
/* 範例: (1,3,5) (2,4,6) (3,5,5) (4,6,4)
   TOUCH_OK = true : 10 (選 1,3 或 2,4)    TOUCH_OK = false: 9 (選 1,4)
   [變形]
   - 時間是「第幾天」且 [s, e] 兩天都要佔用 (整數閉區間) → TOUCH_OK = false
   - 求「最多幾個工作」→ r 全設 1 (也可直接用 Greedy)
   - 時間很大 (1e9) 也沒關係，只用到排序和二分搜，不用開時間大小的陣列 */
