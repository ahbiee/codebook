/* 二分搜的本質: 答案有「單調性」(x 可行 → 比 x 大的都可行，或反過來)
   題目問「最大值的最小值 / 最小值的最大值 / 最少需要多少才能...」→ 對答案二分搜 + check()
   寫 check(x) 時就當作「答案已知是 x」，問題通常會變成簡單的 greedy */
bool check(ll x) { return true; } // [改] x 可行嗎？

// 1. 找第一個 (最小) 可行的 x：check 長得像 F F F T T T
ll first_true(ll lo, ll hi) { // 答案在 [lo, hi]；全部不可行會回傳 hi+1
    hi++;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid; else lo = mid + 1;
    }
    return lo;
}
// 2. 找最後一個 (最大) 可行的 x：check 長得像 T T T F F F
ll last_true(ll lo, ll hi) { // 全部不可行會回傳 lo-1
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2; // +1 才不會死迴圈
        if (check(mid)) lo = mid; else hi = mid - 1;
    }
    return lo;
}
// 3. 實數: 固定跑 100 次 (比 while(r-l>eps) 安全)
double real_bs(double lo, double hi) {
    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2;
        if (check(mid)) hi = mid; else lo = mid;
    }
    return lo;
}
/* 4. 陣列 (要先排序):
   lower_bound(a, a+n, x) - a: 第一個 >= x 的 index；upper_bound: 第一個 > x
   x 出現次數 = upper - lower；<= x 的個數 = upper_bound(...) - a
   [常見 check]
   - 切成 <= k 段，使每段和的最大值最小: check(x) = greedy 切，每段和 <= x，算段數 <= k
   - 放 k 個東西，使最近距離最大 (Aggressive cows): check(x) = 從左邊開始，距離 >= x 就放
   - 第 k 小的「某種組合」(例: 兩兩差、矩陣乘法表): 二分值 x，check = 「<= x 的有幾個」>= k
   - 平均值最大 (分數規劃): 二分 x，每個數減 x 後看能否 >= 0 */
// [例] 構造: 給前綴和的正負號 (+,-,0)，求元素皆非 0 時「最大絕對值」的最小值
// check(M): 維護前綴和可能範圍 [L, R]，每步 L -= M, R += M 再依符號截斷，L > R 不可行
