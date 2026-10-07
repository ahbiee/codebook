// Sliding Window Maximum: 每個長度 k 的視窗的最大值。O(N)
const int MAXN = 200005;
int n, k, a[MAXN];
vector<int> window_max() {
    deque<int> dq; // 存 index，對應的值由前到後遞減
    vector<int> res;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front(); // 過期
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back(); // [改] 最小值: >=
        dq.push_back(i);
        if (i >= k - 1) res.push_back(a[dq.front()]);
    }
    return res;
}
// [應用] DP 優化: dp[i] = max(dp[j]) + c, j in [i-k, i-1] → 對 dp 做 monotonic queue
