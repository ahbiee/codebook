// pi 陣列 (Longest Prefix Suffix): pi[i] 代表 pattern[0..i] 的最長相同前後綴長度
vector<int> build_pi(const string& s) {
    int m = s.length();
    vector<int> pi(m, -1);
    for (int i = 1, j = -1; i < m; ++i) {
        // 如果不匹配，就利用 pi 陣列往回跳
        while (j >= 0 && s[i] != s[j+1]) j = pi[j];
        if (s[i] == s[j+1]) j++;
        pi[i] = j;
    }
    return pi;
}

// 可用 pi 陣列尋找一個字串的最小循環節
int getMinimumPeriod(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    vector<int> pi = build_pi(s); // 取得 index 陣列

    // 取得整個字串的最長相同前後綴長度
    int maxPrefixLength = pi[n - 1] + 1; // 若 pi[n-1] == -1，則長度為0

    // 計算可能的最小循環節長度
    int period = n - maxPrefixLength;

    // 檢查總長度是否能被 period 整除
    if (maxPrefixLength > 0 && n % period == 0) {
        return period;
    }
    
    // 若無法整除，代表沒有更小的週期，最小循環節為字串本身
    return n; 
}
// 最終，最小循環節長度即為回傳的 period -> s.substr(0, period);

// 執行字串匹配
vector<int> kmp(const string& text, const string& pattern) {
    vector<int> res;
    if (pattern.empty()) return res;
    
    vector<int> pi = build_pi(pattern);
    for (int i = 0, j = -1; i < text.length(); ++i) {
        while (j >= 0 && text[i] != pattern[j+1]) j = pi[j];
        if (text[i] == pattern[j+1]) j++;
        
        if (j == pattern.length() - 1) { // 完全匹配
            res.push_back(i - j);      // 紀錄起始 index
            j = pi[j];            // 繼續尋找下一個可能的匹配
        }
    }
    return res; // 回傳的這個vector包含所有完全匹配的index位置
}
