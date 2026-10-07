// 輸入量超大 (> 1e6 個數) 才需要；一般 ios::sync_with_stdio(false) 就夠
inline ll read() {
    ll x = 0; int c = getchar(); bool neg = false;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    if (c == '-') neg = true, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
    return neg ? -x : x;
}
// __int128 (約 ±1.7e38) 不能直接 cin/cout
void print128(__int128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print128(x / 10);
    putchar('0' + x % 10);
}
__int128 read128(const string &s) {
    __int128 x = 0; int i = (s[0] == '-');
    for (; i < (int)s.size(); i++) x = x * 10 + (s[i] - '0');
    return s[0] == '-' ? -x : x;
}
