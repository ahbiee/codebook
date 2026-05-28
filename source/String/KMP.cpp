// failure 陣列 (LPS): pi[i] 代表 pattern[0..i] 的最長相同前後綴長度
vector<int> build_pi(const string& p) {
    int m = p.length();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        // 如果不匹配，就利用 pi 陣列往回跳
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// 執行字串匹配
vector<int> kmp(const string& text, const string& pattern) {
    vector<int> res;
    if (pattern.empty()) return res;
    
    vector<int> pi = build_pi(pattern);
    for (int i = 0, j = 0; i < text.length(); ++i) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        
        if (j == pattern.length()) { // 完全匹配
            res.push_back(i - j + 1); // 紀錄起始 index
            j = pi[j - 1];            // 繼續尋找下一個可能的匹配
        }
    }
    return res; // 回傳的這個vector包含所有完全匹配的index位置
}