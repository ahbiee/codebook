// Jump Game II: 站在 i 最遠可以跳到 i + a[i]，從 0 到 n-1 最少跳幾次 (到不了回傳 -1)。O(N)
// 想法: BFS 一層一層擴展，[目前這一跳能到的範圍] 內找下一跳最遠能到哪
int min_jumps(const vector<int> &a) {
    int n = a.size(), jumps = 0, cur_end = 0, farthest = 0;
    if (n <= 1) return 0;
    for (int i = 0; i < n - 1; i++) {
        if (i > farthest) return -1;          // 根本走不到 i
        farthest = max(farthest, i + a[i]);
        if (i == cur_end) {                   // 這一跳的範圍用完，必須再跳
            if (farthest <= i) return -1;
            jumps++; cur_end = farthest;
            if (cur_end >= n - 1) break;
        }
    }
    return cur_end >= n - 1 ? jumps : -1;
}
