// 最大連續子陣列和 O(N)。全部是負數時回傳最大的那個負數
ll kadane(const vector<ll> &a) {
    ll best = LLONG_MIN, cur = 0;
    for (ll x : a) {
        cur = max(x, cur + x); // 接在前面 vs 從自己重新開始
        best = max(best, cur);
    }
    return best; // 允許空陣列 (答案至少 0): best 初始 0
}
/* [變形]
- 最大子矩形和 (N,M <= 300): 枚舉上下列 r1..r2，把每行壓成一個數 (行前綴和)，對它做 kadane，O(N^2 M)
- 環狀陣列: max(一般 kadane, 總和 - 最小子陣列和)；全負時只取一般 kadane
- 長度至少 K: 前綴和 pre，ans = max(pre[i] - min(pre[0..i-K]))
- 最大子陣列乘積: 同時維護 cur_max、cur_min (負負得正) */
