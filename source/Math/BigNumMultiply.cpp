// 大數: vector<int> 反向存 (個位在 [0])。先想想 __int128 (到 1.7e38) 夠不夠
typedef vector<int> Big;
Big to_big(const string &s) { Big a; for (int i = s.size() - 1; i >= 0; i--) a.push_back(s[i] - '0'); return a; }
void trim(Big &a) { while (a.size() > 1 && a.back() == 0) a.pop_back(); }
void print(const Big &a) { for (int i = a.size() - 1; i >= 0; i--) cout << a[i]; cout << '\n'; }
int cmp(const Big &a, const Big &b) { // -1: a<b, 0: a==b, 1: a>b
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    for (int i = a.size() - 1; i >= 0; i--) if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
    return 0;
}
Big add(const Big &a, const Big &b) {
    Big c; int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % 10); carry /= 10;
    }
    return c;
}
Big sub(const Big &a, const Big &b) { // 需 a >= b
    Big c = a; int borrow = 0;
    for (size_t i = 0; i < c.size(); i++) {
        c[i] -= borrow + (i < b.size() ? b[i] : 0);
        borrow = c[i] < 0;
        if (borrow) c[i] += 10;
    }
    trim(c); return c;
}
Big mul_small(const Big &a, ll b) { // b 到 1e9 都可
    Big c; ll carry = 0;
    for (size_t i = 0; i < a.size() || carry; i++) {
        if (i < a.size()) carry += a[i] * b;
        c.push_back(carry % 10); carry /= 10;
    }
    trim(c); return c;
}
Big mul(const Big &a, const Big &b) { // O(N*M)
    vector<ll> c(a.size() + b.size(), 0);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];
    Big r; ll carry = 0;
    for (size_t i = 0; i < c.size(); i++) { carry += c[i]; r.push_back(carry % 10); carry /= 10; }
    trim(r); return r;
}
Big div_small(const Big &a, ll b, ll &rem) { // 商與餘數
    Big c(a.size()); rem = 0;
    for (int i = a.size() - 1; i >= 0; i--) { rem = rem * 10 + a[i]; c[i] = rem / b; rem %= b; }
    trim(c); return c;
}
