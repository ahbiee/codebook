// root = 0，節點從 1 開始編號；tr[u][c] == 0 代表沒有這條路
const int MAXN = 1000005, SIGMA = 26; // MAXN = 所有字串總長 + 1；[改] 二進位 XOR: SIGMA = 2
int tr[MAXN][SIGMA], pass_cnt[MAXN], end_cnt[MAXN], cnt = 0;
void trie_init() { // 多筆測資: 只清用過的節點
    for (int i = 0; i <= cnt; i++) memset(tr[i], 0, sizeof tr[i]), pass_cnt[i] = end_cnt[i] = 0;
    cnt = 0;
}
void insert(const string &s) {
    int u = 0; pass_cnt[u]++;
    for (char ch : s) {
        int c = ch - 'a';          // [改] 字元集
        if (!tr[u][c]) tr[u][c] = ++cnt;
        u = tr[u][c]; pass_cnt[u]++;
    }
    end_cnt[u]++;
}
int walk(const string &s) { // 走到 s 的節點，不存在回傳 -1
    int u = 0;
    for (char ch : s) { u = tr[u][ch - 'a']; if (!u) return -1; }
    return u;
}
int count_word(const string &s) { int u = walk(s); return u == -1 ? 0 : end_cnt[u]; }   // s 出現幾次
int count_prefix(const string &s) { int u = walk(s); return u == -1 ? 0 : pass_cnt[u]; } // 以 s 為前綴的個數
void erase(const string &s) { // 需確定 s 存在
    int u = 0; pass_cnt[u]--;
    for (char ch : s) { u = tr[u][ch - 'a']; pass_cnt[u]--; }
    end_cnt[u]--;
}
// [變形] 最大 XOR 配對: SIGMA=2，把數字從高位 (bit 30 → 0) 插入；
// 查 x 時每一位盡量走「相反」的 bit: int b = x>>i&1; if(tr[u][!b] && pass_cnt[tr[u][!b]]) res|=1<<i, u=tr[u][!b]; else u=tr[u][b];
