// pi[i] = s[0..i] 最長「相等真前後綴」的長度
vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1]; // 失配就往回跳
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
// p 在 t 中所有出現的起點 (0-based)，O(|t| + |p|)
vector<int> kmp(const string &t, const string &p) {
    vector<int> pi = prefix_function(p), res;
    for (int i = 0, j = 0; i < (int)t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j]) j++;
        if (j == (int)p.size()) { res.push_back(i - j + 1); j = pi[j - 1]; }
    }
    return res;
}
// 最小循環節: k = n - pi[n-1]。n % k == 0 → s 由 s.substr(0,k) 重複 n/k 次；否則答案是 n
int min_period(const string &s) {
    int n = s.size(), k = n - prefix_function(s).back();
    return n % k == 0 ? k : n;
}
/* [變形]
- 不重疊計數: 匹配成功後 j = 0 (而不是 pi[j-1])
- s 的所有「既是前綴也是後綴」的長度: j = pi[n-1], 一直 j = pi[j-1] 直到 0
- 最短補字元變迴文 (補在後面): t = rev(s) + '#' + s，答案 n - pi.back()
*/
