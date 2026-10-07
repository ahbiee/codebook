// 需要 point.cpp
bool on_segment(P p, P a, P b) { // p 是否在線段 ab 上 (含端點)
    return sign(cross(a, b, p)) == 0 && sign(dot(a - p, b - p)) <= 0;
}
// 線段 ab 與 cd 是否相交 (含端點接觸、共線重疊)
bool seg_intersect(P a, P b, P c, P d) {
    int d1 = sign(cross(a, b, c)), d2 = sign(cross(a, b, d));
    int d3 = sign(cross(c, d, a)), d4 = sign(cross(c, d, b));
    if (d1 * d2 < 0 && d3 * d4 < 0) return true; // 嚴格交叉 (跨立實驗)
    return on_segment(c, a, b) || on_segment(d, a, b) || on_segment(a, c, d) || on_segment(b, c, d);
}
// 直線 ab 與直線 cd 的交點 (先確認不平行: sign(cross(b-a, d-c)) != 0)
P line_intersection(P a, P b, P c, P d) {
    ld t = cross(c - a, d - c) / cross(b - a, d - c);
    return a + (b - a) * t;
}
/* 軸對齊矩形交集 (左下 (x1,y1) 右上 (x2,y2)，與 (x3,y3)-(x4,y4)):
   W = max(0, min(x2,x4) - max(x1,x3)), H = max(0, min(y2,y4) - max(y1,y3))，面積 = W * H
   (只問「有沒有碰到」: W >= 0 && H >= 0) */
