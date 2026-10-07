// 需要 point.cpp。Andrew 單調鏈，O(N log N)，回傳逆時針凸包 (不含共線點)
vector<P> convex_hull(vector<P> pts) {
    sort(pts.begin(), pts.end()); // pair 預設先比 x 再比 y
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size();
    if (n <= 2) return pts;
    vector<P> h(2 * n);
    int m = 0;
    for (int i = 0; i < n; i++) { // 下凸包 (左→右)
        while (m >= 2 && sign(cross(h[m - 2], h[m - 1], pts[i])) <= 0) m--; // [改] 保留共線點: < 0
        h[m++] = pts[i];
    }
    for (int i = n - 2, t = m + 1; i >= 0; i--) { // 上凸包 (右→左)
        while (m >= t && sign(cross(h[m - 2], h[m - 1], pts[i])) <= 0) m--;
        h[m++] = pts[i];
    }
    h.resize(m - 1); // 起點被加了兩次
    return h;
}
// 旋轉卡尺: 凸包直徑 (最遠點對距離的平方)，h 為逆時針凸包
ld farthest_pair(const vector<P> &h) {
    int n = h.size();
    if (n == 1) return 0;
    if (n == 2) return dot(h[0] - h[1], h[0] - h[1]);
    ld best = 0;
    for (int i = 0, j = 1; i < n; i++) {
        while (cross(h[i], h[(i + 1) % n], h[(j + 1) % n]) > cross(h[i], h[(i + 1) % n], h[j])) j = (j + 1) % n;
        best = max({best, dot(h[i] - h[j], h[i] - h[j]), dot(h[(i + 1) % n] - h[j], h[(i + 1) % n] - h[j])});
    }
    return best;
}
// 凸包周長 = Σ len(h[i+1] - h[i])；面積用 polygon_area(h)
