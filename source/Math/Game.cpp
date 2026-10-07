/* 博弈 (兩人輪流、無法行動者輸)
- Nim: 多堆石頭任取 → a1 ^ a2 ^ ... ^ an != 0 先手勝
- Bash: 一堆 n 個，每次取 1~k → n % (k+1) != 0 先手勝
- 階梯 Nim: 只看奇數階的 XOR
- 不確定時: 小範圍暴力算 win[] 找規律 (打表!)
- 多個獨立遊戲的組合 → 各自算 SG 值再 XOR，!= 0 先手勝 */
const int MAXN = 100005;
int sg[MAXN];
vector<int> moves = {1, 3, 4}; // [改] 每次可拿的數量
void build_sg(int n) {
    for (int i = 0; i <= n; i++) {
        set<int> s; // 所有後繼狀態的 SG 值
        for (int m : moves) if (i >= m) s.insert(sg[i - m]);
        int g = 0;
        while (s.count(g)) g++; // mex
        sg[i] = g;
    }
}
// sg[i] == 0 → 必敗態 (P-position)；!= 0 → 必勝態
