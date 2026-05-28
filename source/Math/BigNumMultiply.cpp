// 1. 大數 x 小整數 (BigInt * int)
// 適用場景：算階乘、連續乘上範圍在 int 內的數值
// 時間複雜度：O(N)
vector<int> multiply_small(const vector<int>& a, int b) {
    if (b == 0 || (a.size() == 1 && a[0] == 0)) return {0};
    
    vector<int> c;
    long long carry = 0; // 使用 long long 避免溢位
    
    for (size_t i = 0; i < a.size() || carry > 0; i++) {
        if (i < a.size()) carry += 1LL * a[i] * b;
        c.push_back(carry % 10);
        carry /= 10;
    }
    return c;
}

// 2. 大數 x 大數 (BigInt * BigInt)
// 適用場景：兩個長度未知的超大整數相乘
// 時間複雜度：O(N * M)
vector<int> multiply_big(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {0};
    if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) return {0};
    
    // 結果的最大可能長度為兩者長度相加
    vector<int> c(a.size() + b.size(), 0);
    
    for (size_t i = 0; i < a.size(); i++) {
        long long carry = 0;
        for (size_t j = 0; j < b.size() || carry > 0; j++) {
            // 注意：要加上原本在 c[i+j] 已經算出的值
            long long cur = c[i + j] + 1LL * a[i] * (j < b.size() ? b[j] : 0) + carry;
            c[i + j] = cur % 10;
            carry = cur / 10;
        }
    }
    
    // 移除多餘的前導零 (例如 00 變成 0)
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    
    return c;
}

// 輔助函式：將字串轉換為大數陣列 (反向存入)
vector<int> string_to_bigint(const string& s) {
    vector<int> res;
    for (int i = s.length() - 1; i >= 0; i--) {
        res.push_back(s[i] - '0');
    }
    return res;
}

// 輔助函式：印出大數 (反向印出)
void print_bigint(const vector<int>& a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
}