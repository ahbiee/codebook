// 滑動視窗 = 同向雙指針 + 維護視窗內的統計 (計數陣列/map)
// 1. 最長「不含重複字元」的子字串
int longest_unique(const string &s) {
    int cnt[256] = {}, best = 0;
    for (int l = 0, r = 0; r < (int)s.size(); r++) {
        cnt[(unsigned char)s[r]]++;
        while (cnt[(unsigned char)s[r]] > 1) cnt[(unsigned char)s[l++]]--;
        best = max(best, r - l + 1);
    }
    return best;
}
// 2. 「最多 K 種不同值」的子陣列個數 (恰好 K 種 = atMost(K) - atMost(K-1))
ll at_most_k_distinct(const vector<int> &a, int k) {
    map<int, int> cnt; ll res = 0;
    for (int l = 0, r = 0; r < (int)a.size(); r++) {
        cnt[a[r]]++;
        while ((int)cnt.size() > k) { if (--cnt[a[l]] == 0) cnt.erase(a[l]); l++; }
        res += r - l + 1; // 以 r 結尾的合法子陣列有 r-l+1 個
    }
    return res;
}
// 3. 固定長度 len 的子陣列最小和: 先算前 len 個，之後每步 +a[i] -a[i-len]
// 視窗內最大/最小值 → 單調隊列 (MonotonicQueue)
// 包含 t 所有字元的最短子字串: need[] 計數，滿足時一直縮左邊並更新答案
