// 把 "abc" 變成 "$#a#b#c#^"，奇偶長度統一處理。p[i] = 以 t[i] 為中心的半徑
// p[i] 剛好等於「原字串中對應迴文的長度」，起點 = (i - p[i]) / 2
string t;
vector<int> p;
void manacher(const string &s) {
    t = "$#";
    for (char c : s) t += c, t += '#';
    t += '^';
    int n = t.size(), c = 0, r = 0;
    p.assign(n, 0);
    for (int i = 1; i < n - 1; i++) {
        if (i < r) p[i] = min(r - i, p[2 * c - i]);              // 抄鏡像
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;       // 暴力擴展
        if (i + p[i] > r) c = i, r = i + p[i];
    }
}
string longest_palindrome(const string &s) {
    manacher(s);
    int best = 1;
    for (int i = 1; i + 1 < (int)t.size(); i++) if (p[i] > p[best]) best = i;
    return s.substr((best - p[best]) / 2, p[best]);
}
ll count_palindromes(const string &s) { // 迴文子字串總數 (位置不同算不同)
    manacher(s);
    ll total = 0;
    for (int i = 1; i + 1 < (int)t.size(); i++) total += (p[i] + 1) / 2;
    return total;
}
// s[l..r] 是否迴文: 中心 i = l + r + 2，檢查 p[i] >= r - l + 1
