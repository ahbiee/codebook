/* 雙指針 (同向): r 每次往右一格，l 在「條件被破壞」時往右縮。總共 O(N)
   能用的條件: 區間變大條件只會更難滿足 (單調性)，例如「和 <= x 且元素非負」 */
const int MAXN = 200005;
int n, a[MAXN];
// 1. 和 <= x 的最長子陣列 (a 非負)
int longest_sum_at_most(ll x) {
    ll sum = 0; int best = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (sum > x) sum -= a[l++]; // [改] 縮的條件
        best = max(best, r - l + 1);
    }
    return best;
}
// 2. 和 >= target 的最短子陣列 (a 非負)，找不到回傳 0
int shortest_sum_at_least(ll target) {
    ll sum = 0; int best = INT_MAX;
    for (int l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (l <= r && sum >= target) best = min(best, r - l + 1), sum -= a[l++];
    }
    return best == INT_MAX ? 0 : best;
}
// 3. 對向: 排序後找兩數和 = x (3 Sum: 固定第一個數，剩下做 2 Sum，O(N^2))
bool two_sum(ll x) { // a 已排序
    for (int l = 0, r = n - 1; l < r;) {
        ll s = a[l] + a[r];
        if (s == x) return true;
        s < x ? l++ : r--;
    }
    return false;
}
// 有負數時「和 = k 的子陣列」不能用雙指針 → 前綴和 + map
// 4. Floyd 判圈 (函數迭代 x → f(x) 找環): slow 走 1 步、fast 走 2 步，相遇代表有環
