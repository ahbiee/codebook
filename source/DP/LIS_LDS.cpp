// LIS O(N log N)。tail[k] = 長度 k+1 的遞增子序列「最小的結尾」
// 嚴格遞增: lower_bound；非嚴格 (可相等): upper_bound
int lis_length(const vector<int> &a) {
    vector<int> tail;
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x); // [改] 非嚴格: upper_bound
        if (it == tail.end()) tail.push_back(x); else *it = x;
    }
    return tail.size(); // 注意 tail 的內容不一定是真正的 LIS
}
// 要輸出真正的 LIS: 記錄每個元素接在誰後面
vector<int> lis_sequence(const vector<int> &a) {
    int n = a.size();
    vector<int> tail_val, tail_idx, prv(n, -1);
    for (int i = 0; i < n; i++) {
        int k = lower_bound(tail_val.begin(), tail_val.end(), a[i]) - tail_val.begin();
        if (k == (int)tail_val.size()) tail_val.push_back(a[i]), tail_idx.push_back(i);
        else tail_val[k] = a[i], tail_idx[k] = i;
        prv[i] = k ? tail_idx[k - 1] : -1;
    }
    vector<int> res;
    for (int i = tail_idx.empty() ? -1 : tail_idx.back(); i != -1; i = prv[i]) res.push_back(a[i]);
    reverse(res.begin(), res.end());
    return res;
}
// LDS: 把每個數取負再做 LIS (嚴格遞減 → 對 -a 用 lower_bound；非嚴格遞減 → upper_bound)
/* [題型]
- 俄羅斯娃娃/信封 (w,h 都要嚴格大): 依 w 遞增排、w 相同時 h 遞減排，再對 h 做嚴格 LIS
- 橋不交叉: 依南岸排序，對北岸做 LIS
- 最少幾個「遞減序列」覆蓋全部 (攔截飛彈) = 嚴格遞增 LIS 長度 (Dilworth)
- 先增後減 (Bitonic): L[i] = 以 i 結尾的 LIS、R[i] = 以 i 開頭的 LDS，max(L[i]+R[i]-1)
  以 i 結尾的 LIS 長度 = 插入位置 k + 1
- 最少刪幾個變遞增 = n - LIS；最少改幾個變嚴格遞增: 對 a[i]-i 做非嚴格 LIS */
