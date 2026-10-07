// 後綴陣列 O(N log N)。sa[i] = 字典序第 i 小的後綴起點；lcp[i] = sa[i] 與 sa[i-1] 的 LCP
vector<int> sa, rk, lcp;
void build_sa(const string &s0) {
    string s = s0 + '\0'; // 加最小字元當結尾
    int n = s.size();
    sa.assign(n, 0); rk.assign(n, 0);
    vector<int> tmp(n), cnt(max(256, n), 0);
    for (int i = 0; i < n; i++) cnt[(unsigned char)s[i]]++;
    for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--cnt[(unsigned char)s[i]]] = i;
    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++) rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i++) tmp[i] = (sa[i] - k + n) % n; // 依第二關鍵字排好
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) cnt[rk[tmp[i]]]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[rk[tmp[i]]]] = tmp[i];
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {rk[sa[i]], rk[(sa[i] + k) % n]}, prv = {rk[sa[i - 1]], rk[(sa[i - 1] + k) % n]};
            tmp[sa[i]] = tmp[sa[i - 1]] + (cur != prv);
        }
        rk = tmp;
        if (rk[sa[n - 1]] == n - 1) break;
    }
    sa.erase(sa.begin()); // 去掉 '\0' 那個後綴
    n--; rk.assign(n, 0);
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
    lcp.assign(n, 0); // Kasai
    for (int i = 0, k = 0; i < n; i++) {
        if (rk[i] == 0) { k = 0; continue; }
        int j = sa[rk[i] - 1];
        while (i + k < n && j + k < n && s0[i + k] == s0[j + k]) k++;
        lcp[rk[i]] = k;
        if (k) k--;
    }
}
/* [應用]
- 相異子字串個數 = n(n+1)/2 - Σ lcp[i]
- 最長重複子字串 = max lcp[i]
- 最長共同子字串 (s, t): 對 s + '#' + t 建 SA，相鄰且分屬兩邊的 lcp 最大值
- 兩後綴 LCP = lcp[rk+1..rk'] 的區間最小值 (配 Sparse Table)
*/
