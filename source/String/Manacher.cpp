// 求最長迴文
struct Manacher {
    vector<int> p; // p[i] 記錄以 i 為中心的最長迴文半徑
    string t;      // 轉換後的字串
    
    Manacher(const string& s) {
        // 預處理：將 "abc" 變成 "$#a#b#c#^" 來統一奇偶長度
        // 頭尾放不同的字元 ($ 和 ^) 可省去邊界判斷
        t = "$#";
        for (char c : s) { t += c; t += '#'; }
        t += '^';
        
        int n = t.length();
        p.assign(n, 0);
        int c = 0, r = 0; // c: 目前最靠右的迴文中心, r: 該迴文的右界
        
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * c - i; // i 關於 c 的對稱點
            
            // 如果 i 在迴文右界 r 內，可以直接抄對稱點的答案
            if (r > i) p[i] = min(r - i, p[mirror]);
            
            // 暴力往外擴展半徑
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            
            // 如果這個新迴文的右界超過了 r，更新 c 和 r
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
    }
    
    // 回傳原字串中的最長迴文長度
    int get_max_len() {
        int max_len = 0;
        for (int len : p) max_len = max(max_len, len);
        return max_len;
    }

    // 回傳所有出現的迴文，包含位置不同的重複字串
    // 如果要不重複就把vector改成set進行去重，再for輸出就好
    vector<string> get_all_palindromes(const string& s) {
        vector<string> result;
        // 遍歷所有可能的迴文中心
        for (int i = 1; i < t.length() - 1; i++) {
            // p[i] 是以 i 為中心的最大迴文長度
            // 每次往內縮 2 (砍掉頭尾字元)，即可得到以此為中心的所有較短迴文
            for (int len = p[i]; len > 0; len -= 2) {
                // 神奇的公式：(i - len) / 2 可以精準對應到原字串 s 的起點索引
                int start_idx = (i - len) / 2;
                result.push_back(s.substr(start_idx, len));
            }
        }
        return result;
    }

    // 僅計算所有迴文子字串的「總數量」
    long long count_all_palindromes() {
        long long total = 0;
        for (int i = 1; i < t.length() - 1; i++) {
            // 對於中心 i，包含的迴文數量恰好是 ceil(p[i] / 2)
            total += (p[i] + 1) / 2; 
        }
        return total;
    }
};
