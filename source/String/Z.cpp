// z[i] 代表 s[0..n-1] 與 s[i..n-1] 的最長共同前綴 (LCP) 長度
// 若要找 pattern 在 text 中的位置，可傳入 s = pattern + "$" + text
vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    // l, r 記錄目前「最靠右」的匹配區間 [l, r]
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        // 如果 i 在區間內，可以直接利用對稱性 (i - l) 抄答案
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        
        // 暴力往後擴展 (因為有前面的加速，這裡實際上只會做很少次)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        // 如果新匹配的區間超過了原有的 r，更新 [l, r] 視窗
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

string pattern = "aba";
string text = "abacaba";

string s = pattern + "$" + text;

vector<int> z = z_function(s);

for(int i = 0; i < s.size(); i++) {
    if(z[i] == pattern.size()) {
        cout << "found at " << i - pattern.size() - 1 << '\n';
    }
    /*
    found at 0
    found at 4
    */
}