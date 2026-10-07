// 字串雜湊: O(1) 比較任意兩個子字串是否相等。mod 2^61-1 幾乎不會碰撞
typedef unsigned long long ull;
const ull MODH = (1ULL << 61) - 1;
ull mulh(ull a, ull b) { return (__int128)a * b % MODH; }
const ull BASE = mt19937_64(chrono::steady_clock::now().time_since_epoch().count())() % (MODH - 1000) + 500;
const int MAXN = 1000005;
ull h[MAXN], pw[MAXN]; // h[i] = s[0..i-1] 的雜湊
void build_hash(const string &s) {
    int n = s.size(); pw[0] = 1; h[0] = 0;
    for (int i = 0; i < n; i++) {
        h[i + 1] = (mulh(h[i], BASE) + (ull)s[i]) % MODH;
        pw[i + 1] = mulh(pw[i], BASE);
    }
}
ull get_hash(int l, int r) { // s[l..r] (0-based, 含 r)
    return (h[r + 1] + MODH - mulh(h[l], pw[r - l + 1])) % MODH;
}
/* [應用]
- 兩字串比較: 對 s + '#' + t 建一次，或開第二組 h2
- 最長重複子字串 / 最長共同子字串: 二分長度 L + 把所有長度 L 的 hash 放進 set
- 迴文判斷: 對 s 和 reverse(s) 各建一組，比較 s[l..r] 與反轉後對應的區段
- 求 s 與 t 的 LCP: 二分長度 + hash 比較 → 可以做字串比較大小
*/
