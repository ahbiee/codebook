// z[i] = s 與 s[i..] 的最長共同前綴長度 (z[0] 定義為 0)，O(N)
vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) { // [l, r] 為目前最右的匹配區間
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
// 字串匹配: s = p + '$' + t ('$' 不能出現在 p,t 中)
vector<int> z_match(const string &t, const string &p) {
    vector<int> z = z_function(p + '$' + t), res;
    for (int i = p.size() + 1; i < (int)z.size(); i++)
        if (z[i] == (int)p.size()) res.push_back(i - p.size() - 1);
    return res;
}
// 最小週期: 最小的 i 使 i + z[i] == n (且 n % i == 0 才是整除循環)
