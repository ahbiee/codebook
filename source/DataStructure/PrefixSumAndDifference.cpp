using ll = long long; 

// === 1D prefix ===
// 建前綴表 build
for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + a[i];

    // 如果是XOR就把+換^ -> pre[i] = pre[i-1] ^ a[i];

// 查詢含l,r的區間 query [l, r] = query [0, r] - query [0, l-1]
ll query(int l, int r) {
    return pre[r] - pre[l - 1];
    // XOR(l,r) = pre[r] ^ pre[l-1];
}

// === 2D prefix ===

// pre 是 前綴和 array，a 是 原始數據 array
// 必須全是 "1-indexed"，避免[-1]的判斷
// i是row，從1~n 、 j是col，從1~m
void build() {
    // 迴圈從 1 開始，當 i=1 或 j=1 時，存取到 0 的位置都會剛好是 0，完美相消
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
        }
    }
}

// query[(x1, y1) ~ (x2, y2)]，傳入的 x1, y1, x2, y2 也必須是 1-based 的索引
int query(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

// === 1D Difference ===

// 區間加 val -> 從 l + val，到 r+1 不再加 val
diff[l] += val;
diff[r + 1] -= val;

// 還原值
for (int i = 1; i <= n; i++)
    a[i] = a[i - 1] + diff[i];

// === 2D Difference ===

// 區間加 k
diff[x1][y1] += k;
diff[x2+1][y1] -= k;
diff[x1][y2+1] -= k;
diff[x2+1][y2+1] += k;

// 還原
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        diff[i][j] += diff[i-1][j]
                    + diff[i][j-1]
                    - diff[i-1][j-1];
    }
}
// 此時 diff[i][j] 是 "經過處理後的值"，如果有原始陣列 a，需再加上 a[i][j]