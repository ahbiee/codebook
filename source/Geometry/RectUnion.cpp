/* 矩形面積聯集: x 方向掃描線 + 線段樹 (cover 次數 + 被蓋住的 y 長度)，O(N log N)
   矩形 (x1, y1) 左下、(x2, y2) 右上 */
const int MAXR = 200005;   // 矩形數 * 2
vector<ll> ys;
int cov[4 * MAXR];
ll len_[4 * MAXR];
void upd(int ql, int qr, int v, int id, int l, int r) { // 線段樹節點 [l, r] 代表 y 區間 [ys[l], ys[r+1]]
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) cov[id] += v;
    else { int m = (l + r) / 2; upd(ql, qr, v, id * 2, l, m); upd(ql, qr, v, id * 2 + 1, m + 1, r); }
    if (cov[id] > 0) len_[id] = ys[r + 1] - ys[l];          // 整段被蓋住
    else if (l == r) len_[id] = 0;
    else len_[id] = len_[id * 2] + len_[id * 2 + 1];
}
ll rect_union(const vector<array<ll, 4>> &rects) { // {x1, y1, x2, y2}
    vector<array<ll, 4>> ev; // {x, +1/-1, y1, y2}
    ys.clear();
    for (auto [x1, y1, x2, y2] : rects) {
        ev.push_back({x1, 1, y1, y2}); ev.push_back({x2, -1, y1, y2});
        ys.push_back(y1); ys.push_back(y2);
    }
    sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(ev.begin(), ev.end());
    int m = ys.size() - 1; // 線段樹管理 m 段 [ys[i], ys[i+1]]
    if (m <= 0) return 0;
    fill(cov, cov + 4 * m, 0); fill(len_, len_ + 4 * m, 0);
    ll area = 0;
    for (int i = 0; i < (int)ev.size(); i++) {
        if (i > 0) area += len_[1] * (ev[i][0] - ev[i - 1][0]);
        int l = lower_bound(ys.begin(), ys.end(), ev[i][2]) - ys.begin();
        int r = lower_bound(ys.begin(), ys.end(), ev[i][3]) - ys.begin() - 1;
        if (l <= r) upd(l, r, ev[i][1], 1, 0, m - 1);
    }
    return area; // 聯集周長: 每次事件累加 |len_[1] 的變化| (x 方向)，y 方向再做一次
}
