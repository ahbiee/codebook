#include <algorithm>
using namespace std;

// 依賴上一節的 Point 結構與 sign, cross 函數

// 輔助函數：判斷點 P 是否在線段 AB 的「邊界框 (Bounding Box)」內
// 實戰意義：當三點共線時，單靠外積無法確認 P 是否在線段上(可能在延長線上)
bool on_segment(Point p, Point a, Point b) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

// 核心函數：判斷線段 AB 與線段 CD 是否相交
bool segment_intersect(Point a, Point b, Point c, Point d) {
    // 1. 計算四個外積值 (跨立實驗)
    // 意義：判斷 C 點和 D 點分別在直線 AB 的哪一側
    double c1 = cross(b - a, c - a);
    double c2 = cross(b - a, d - a);
    
    // 意義：判斷 A 點和 B 點分別在直線 CD 的哪一側
    double c3 = cross(d - c, a - c);
    double c4 = cross(d - c, b - c);
    
    // 2. 規範相交 (Strictly Intersect)
    // 如果 C, D 在 AB 兩側 (外積正負號相反，相乘 < 0)
    // 且 A, B 在 CD 兩側，則保證兩線段相交
    if (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) {
        return true;
    }
    
    // 3. 特殊情況處理 (端點相交 或 共線重疊)
    // 如果外積為 0，代表該點在另一條直線上。
    // 接著必須用 on_segment 確保它真的落在「線段區間」內，而不是在延長線上。
    if (sign(c1) == 0 && on_segment(c, a, b)) return true;
    if (sign(c2) == 0 && on_segment(d, a, b)) return true;
    if (sign(c3) == 0 && on_segment(a, c, d)) return true;
    if (sign(c4) == 0 && on_segment(b, c, d)) return true;
    
    return false; // 以上皆非，則不相交
}