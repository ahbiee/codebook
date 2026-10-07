/* 數位 DP: 「1~N (N 到 1e18) 中有幾個數滿足某個跟『每一位數字』有關的性質」
   答案 [L, R] = solve(R) - solve(L - 1)
   從最高位往低位填，tight = 前面是否都貼著 N 的上限，lead = 是否還在前導零
   例: 計算 0~N 中「數字和 = S」的個數 */
string num;
int S;
ll memo[20][200][2][2];
bool seen[20][200][2][2];
ll go(int pos, int sum, bool tight, bool lead) {
    if (sum > S) return 0;                              // 剪枝
    if (pos == (int)num.size()) return sum == S;        // [改] 結尾判斷
    ll &res = memo[pos][sum][tight][lead];
    if (seen[pos][sum][tight][lead]) return res;
    seen[pos][sum][tight][lead] = true; res = 0;
    int lim = tight ? num[pos] - '0' : 9;
    for (int dgt = 0; dgt <= lim; dgt++)
        res += go(pos + 1, sum + dgt, tight && dgt == lim, lead && dgt == 0); // [改] 狀態轉移
    return res;
}
ll solve(ll n) {
    if (n < 0) return 0;
    num = to_string(n);
    memset(seen, 0, sizeof seen);
    return go(0, 0, true, true);
}
/* [改] 常見狀態: 數字和 / 數字和 mod k / 數字本身 mod k / 上一位數字 (不能有相鄰相同、
   不含 "4" 或 "62") / 出現過某些數字的 bitmask。lead 只有在「0 會影響答案」時需要
   (例如數 0 的個數、上一位不能相同)，否則可以拿掉 */
