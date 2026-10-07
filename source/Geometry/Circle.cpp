// 需要 point.cpp。圓用 {圓心 P, 半徑 ld} 表示
// 三點決定的圓 (三角形外接圓)。三點共線時半徑回傳 -1
pair<P, ld> circumcircle(P a, P b, P c) {
    P ab = b - a, ac = c - a;
    ld d = 2 * cross(ab, ac);
    if (sign(d) == 0) return {{0, 0}, -1};
    ld b2 = dot(ab, ab), c2 = dot(ac, ac);
    P o = a + P{(ac.second * b2 - ab.second * c2) / d, (ab.first * c2 - ac.first * b2) / d};
    return {o, len(o - a)};
}
// 直線 ab 與圓 (o, r) 的交點 (0~2 個)
vector<P> circle_line(P o, ld r, P a, P b) {
    P h = projection(o, a, b);                 // 需要 PointLine.cpp
    ld d2 = r * r - dot(h - o, h - o);
    if (sign(d2) < 0) return {};
    P dir = (b - a) / len(b - a);
    ld s = sqrtl(max((ld)0, d2));
    if (sign(s) == 0) return {h};
    return {h - dir * s, h + dir * s};
}
// 兩圓關係 (d = 圓心距): d > r1+r2 相離；d == r1+r2 外切；|r1-r2| < d < r1+r2 相交；
// d == |r1-r2| 內切；d < |r1-r2| 內含
