// 需要 point.cpp
ld dist_to_line(P p, P a, P b) { // 點到「直線」ab: 平行四邊形面積 / 底
    return fabsl(cross(a, b, p)) / len(b - a);
}
ld dist_to_segment(P p, P a, P b) { // 點到「線段」ab
    if (same(a, b)) return len(p - a);
    if (sign(dot(b - a, p - a)) < 0) return len(p - a); // 投影落在 a 外側
    if (sign(dot(a - b, p - b)) < 0) return len(p - b); // 投影落在 b 外側
    return dist_to_line(p, a, b);
}
P projection(P p, P a, P b) { // p 在直線 ab 上的投影點 (垂足)
    return a + (b - a) * (dot(p - a, b - a) / dot(b - a, b - a));
}
P reflection(P p, P a, P b) { return projection(p, a, b) * 2 - p; } // 對直線 ab 的鏡射
// 兩線段距離 (不相交時) = 四個「端點到另一線段」距離取 min
