// 高斯消去解 n 元一次方程組 A x = b (浮點數)。a[i][n] 放 b[i]
// 回傳: 0 無解, 1 唯一解 (存於 x), 2 無限多解
const double EPS = 1e-9;
int gauss(vector<vector<double>> a, vector<double> &x) {
    int n = a.size(), m = a[0].size() - 1;
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) if (fabs(a[i][col]) > fabs(a[sel][col])) sel = i;
        if (fabs(a[sel][col]) < EPS) continue;
        swap(a[sel], a[row]);
        where[col] = row;
        for (int i = 0; i < n; i++) if (i != row) {
            double c = a[i][col] / a[row][col];
            for (int j = col; j <= m; j++) a[i][j] -= a[row][j] * c;
        }
        row++;
    }
    x.assign(m, 0);
    for (int i = 0; i < m; i++) if (where[i] != -1) x[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; i++) {
        double s = 0;
        for (int j = 0; j < m; j++) s += x[j] * a[i][j];
        if (fabs(s - a[i][m]) > EPS) return 0;
    }
    for (int i = 0; i < m; i++) if (where[i] == -1) return 2;
    return 1;
}
// 模質數版: 除法改成乘逆元、fabs>EPS 改成 != 0；XOR 版 (開關燈問題): 減法改 ^，用 bitset

// XOR 線性基: 從一堆數選子集，XOR 最大值 / 能否湊出 x
ll basis[64];
bool insert_xor(ll x) {
    for (int i = 63; i >= 0; i--) if (x >> i & 1) {
        if (!basis[i]) { basis[i] = x; return true; }
        x ^= basis[i];
    }
    return false; // x 已能被湊出
}
ll max_xor() { ll r = 0; for (int i = 63; i >= 0; i--) r = max(r, r ^ basis[i]); return r; }
