// 需要 point.cpp。多邊形頂點依序 (順/逆時針皆可) 存在 vector<P> poly
ld polygon_area(const vector<P> &poly) { // 鞋帶公式，凹多邊形也可
    ld area = 0; int n = poly.size();
    for (int i = 0; i < n; i++) area += cross(poly[i], poly[(i + 1) % n]);
    return fabsl(area) / 2; // 不取絕對值時: > 0 代表逆時針
}
// 點是否在多邊形內: 1 內部, 0 外部, -1 在邊上 (射線法)
int in_polygon(P p, const vector<P> &poly) {
    int n = poly.size(); bool in = false;
    for (int i = 0; i < n; i++) {
        P a = poly[i], b = poly[(i + 1) % n];
        if (on_segment(p, a, b)) return -1;                 // 需要 Intersection.cpp
        if ((a.second > p.second) != (b.second > p.second) &&
            p.first < a.first + (b.first - a.first) * (p.second - a.second) / (b.second - a.second))
            in = !in;
    }
    return in;
}
/* Pick 定理 (頂點都是格子點): 面積 A = I + B/2 - 1
   I = 內部格點數，B = 邊上格點數 = Σ gcd(|dx|, |dy|)  → I = A - B/2 + 1 */
