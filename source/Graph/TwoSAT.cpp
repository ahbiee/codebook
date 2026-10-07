/* 2-SAT: n 個布林變數，條件都是「a 或 b」(每個子句 2 個變數)。需要 SCC.cpp
   變數 x 的「真」= 點 x，「假」= 點 x + N。總點數 2N
   (a or b) 等價於 (not a → b) 且 (not b → a) */
int N; // 變數個數，SCC 那邊的 n 設成 2N
int neg(int x) { return x <= N ? x + N : x - N; }
void add_or(int a, int b) { g[neg(a)].push_back(b); g[neg(b)].push_back(a); } // a or b
// 常用條件 (x 代表 x 為真，neg(x) 代表 x 為假):
//   x 一定為真: add_or(x, x)        a、b 不能同時為真: add_or(neg(a), neg(b))
//   a → b: add_or(neg(a), b)          a、b 恰好一個為真: add_or(a,b), add_or(neg(a),neg(b))
bool two_sat(vector<int> &val) { // val[i] = 1 表示變數 i 為真
    n = 2 * N;
    find_scc();
    val.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (scc[i] == scc[i + N]) return false; // x 與 not x 在同一個 SCC → 無解
        val[i] = scc[i] < scc[i + N];          // Tarjan 編號小 = 拓樸序後面 → 選它
    }
    return true;
}
