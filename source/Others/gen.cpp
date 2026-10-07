// ===== gen.cpp: 隨機測資產生器。N 與數值都要調小 (N <= 10、值 <= 100)，WA 時才看得懂 =====
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll L, ll R) { return uniform_int_distribution<ll>(L, R)(rng); } // [L, R] 的隨機整數

// ---------- 1. 陣列與字串 ----------
void gen_array(int n, ll L, ll R) { for (int i = 0; i < n; i++) cout << rnd(L, R) << " \n"[i == n - 1]; }
void gen_permutation(int n) { // 1~n 不重複
    vector<int> p(n); iota(p.begin(), p.end(), 1); shuffle(p.begin(), p.end(), rng);
    for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
}
void gen_few_distinct(int n, ll L, ll R, int k) { // 只有 k 種不同的值 (測重複值)
    vector<ll> pool(k); for (ll &x : pool) x = rnd(L, R);
    for (int i = 0; i < n; i++) cout << pool[rnd(0, k - 1)] << " \n"[i == n - 1];
}
void gen_sorted(int n, ll L, ll R, bool rev) { // 已排序 / 完全反序
    vector<ll> a(n); for (ll &x : a) x = rnd(L, R);
    sort(a.begin(), a.end()); if (rev) reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
}
void gen_string(int n, string cs = "abc") { for (int i = 0; i < n; i++) cout << cs[rnd(0, cs.size() - 1)]; cout << '\n'; }
void gen_intervals(int n, ll mx) { // n 個區間 [l, r]
    for (int i = 0; i < n; i++) { ll l = rnd(1, mx), r = rnd(1, mx); if (l > r) swap(l, r); cout << l << ' ' << r << '\n'; }
}

// ---------- 2. 樹 (n 個點、n-1 條邊) ----------
// 共用: 打亂點的編號與邊的順序，避免「編號剛好有順序」讓錯的 code 也 AC
void print_tree(int n, vector<pair<int, int>> e, bool weighted = false, ll maxw = 10) {
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0); shuffle(p.begin() + 1, p.end(), rng);
    shuffle(e.begin(), e.end(), rng);
    for (auto [u, v] : e) {
        u = p[u]; v = p[v]; if (rnd(0, 1)) swap(u, v);
        cout << u << ' ' << v; if (weighted) cout << ' ' << rnd(1, maxw); cout << '\n';
    }
}
void gen_random_tree(int n, bool w = false) { vector<pair<int, int>> e; for (int i = 2; i <= n; i++) e.push_back({(int)rnd(1, i - 1), i}); print_tree(n, e, w); }
void gen_chain(int n, bool w = false) { vector<pair<int, int>> e; for (int i = 2; i <= n; i++) e.push_back({i - 1, i}); print_tree(n, e, w); } // 一條線 (卡遞迴深度)
void gen_star(int n, bool w = false) { vector<pair<int, int>> e; for (int i = 2; i <= n; i++) e.push_back({1, i}); print_tree(n, e, w); }      // 一個中心 (卡 O(度數^2))
void gen_binary_tree(int n, bool w = false) { vector<pair<int, int>> e; for (int i = 2; i <= n; i++) e.push_back({i / 2, i}); print_tree(n, e, w); } // 完全二元樹
void gen_caterpillar(int n, bool w = false) { // 毛毛蟲: 一條主幹，其他點都直接掛在主幹上
    vector<pair<int, int>> e; int len = rnd(1, n);
    for (int i = 2; i <= len; i++) e.push_back({i - 1, i});
    for (int i = len + 1; i <= n; i++) e.push_back({(int)rnd(1, len), i});
    print_tree(n, e, w);
}

// ---------- 3. 圖 (n 個點、m 條邊) ----------
void gen_graph(int n, int m, bool w = false, bool directed = false) { // 無自環、無重邊。m <= n(n-1)/2
    set<pair<int, int>> e;
    while ((int)e.size() < m) {
        int u = rnd(1, n), v = rnd(1, n);
        if (u == v) continue;
        if (!directed && u > v) swap(u, v);
        e.insert({u, v});
    }
    vector<pair<int, int>> ev(e.begin(), e.end()); shuffle(ev.begin(), ev.end(), rng);
    for (auto [u, v] : ev) { cout << u << ' ' << v; if (w) cout << ' ' << rnd(1, 10); cout << '\n'; }
}
void gen_connected_graph(int n, int m, bool w = false) { // 保證連通: 先產生一棵隨機樹，再補 m-(n-1) 條邊
    set<pair<int, int>> e;
    for (int i = 2; i <= n; i++) e.insert({(int)rnd(1, i - 1), i});
    while ((int)e.size() < m) { int u = rnd(1, n), v = rnd(1, n); if (u != v) e.insert({min(u, v), max(u, v)}); }
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0); shuffle(p.begin() + 1, p.end(), rng);
    vector<pair<int, int>> ev(e.begin(), e.end()); shuffle(ev.begin(), ev.end(), rng);
    for (auto [u, v] : ev) { cout << p[u] << ' ' << p[v]; if (w) cout << ' ' << rnd(1, 10); cout << '\n'; }
}
void gen_dag(int n, int m, bool w = false) { // 有向無環: 只產生「小編號 → 大編號」的邊，再打亂編號
    set<pair<int, int>> e;
    while ((int)e.size() < m) { int u = rnd(1, n - 1); e.insert({u, (int)rnd(u + 1, n)}); }
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0); shuffle(p.begin() + 1, p.end(), rng);
    vector<pair<int, int>> ev(e.begin(), e.end()); shuffle(ev.begin(), ev.end(), rng);
    for (auto [u, v] : ev) { cout << p[u] << ' ' << p[v]; if (w) cout << ' ' << rnd(1, 10); cout << '\n'; }
}
void gen_complete_graph(int n, bool w = false) { gen_graph(n, n * (n - 1) / 2, w); } // 完全圖 (卡 O(E^2))
void gen_grid(int r, int c, int wall_pct = 20) { // 網格地圖: '#' 牆、'.' 空地
    cout << r << ' ' << c << '\n';
    for (int i = 0; i < r; i++) { for (int j = 0; j < c; j++) cout << (rnd(1, 100) <= wall_pct ? '#' : '.'); cout << '\n'; }
}

int main() { // [改] 依題目的輸入格式組合上面的函式
    int T = 1;            // 多筆測資時: T = rnd(1, 3); cout << T << '\n';
    while (T--) {
        int n = rnd(2, 8), m = rnd(n - 1, n * (n - 1) / 2);
        cout << n << ' ' << m << '\n';
        gen_connected_graph(n, m, true);
    }
}
/* ===== 使用步驟 =====
1. 同一個資料夾放: sol.cpp (你的解)、brute.cpp (暴力但保證對)、gen.cpp、check.sh 或 check.bat
2. 改 gen.cpp 的 main，產生符合題目格式的「小」測資
3. 執行 check，出現 WA 時: in.txt = 讓你錯的測資，ans.txt = 正確答案，out.txt = 你的答案

===== check.sh (Linux / Git Bash)，第一次先 chmod +x check.sh =====
g++ -O2 gen.cpp -o gen && g++ -O2 sol.cpp -o sol && g++ -O2 brute.cpp -o brute
for ((i = 1; ; i++)); do
    ./gen > in.txt; ./sol < in.txt > out.txt; ./brute < in.txt > ans.txt
    if ! diff -w out.txt ans.txt > /dev/null; then echo "WA on test $i"; cat in.txt; break; fi
    echo "Test $i: AC"
done

===== check.bat (Windows)，先手動編譯成 gen.exe / sol.exe / brute.exe =====
:loop
gen > in.txt & sol < in.txt > out.txt & brute < in.txt > ans.txt
fc /w out.txt ans.txt > nul || (echo WA & type in.txt & exit /b)
goto loop
*/
