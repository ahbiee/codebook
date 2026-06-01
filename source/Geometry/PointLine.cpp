#include <cmath>
using namespace std;

// 依賴前面的 Point, Vector, sign, cross, dot

// 輔助函數：求向量長度
// 原理：向量自己跟自己做內積，等於長度的平方
double length(Vector a) {
    return sqrt(dot(a, a));
}

// 1. 判斷點 P 是否在線段 AB 上
// 原理：
// (1) cross(p-a, b-a) == 0 代表三點共線
// (2) dot(a-p, b-p) <= 0 代表 PA 向量與 PB 向量方向相反 (即 P 夾在 A, B 中間)
bool on_segment(Point p, Point a, Point b) {
    return sign(cross(p - a, b - a)) == 0 && sign(dot(a - p, b - p)) <= 0;
}

// 2. 點 P 到「直線」AB 的距離
// 原理：平行四邊形面積 = 底 * 高 => 高 = 面積 / 底
double dist_to_line(Point p, Point a, Point b) {
    // 面積剛好是外積的絕對值，底邊長是 AB 的長度
    return fabs(cross(b - a, p - a)) / length(b - a);
}

// 3. 點 P 到「線段」AB 的最短距離 (賽場極易錯考點)
// 原理：用內積判斷 P 點的「投影」是否掉出線段外
double dist_to_segment(Point p, Point a, Point b) {
    if (a == b) return length(p - a); // A, B 根本是同一個點
    
    // 鈍角測試 1：角 PAB 是鈍角，代表 P 在 A 的外側，離 A 最近
    if (sign(dot(b - a, p - a)) < 0) return length(p - a);
    
    // 鈍角測試 2：角 PBA 是鈍角，代表 P 在 B 的外側，離 B 最近
    if (sign(dot(a - b, p - b)) < 0) return length(p - b);
    
    // 如果都不是鈍角，代表 P 的投影乖乖落在線段 AB 上，距離就是點到直線距離
    return dist_to_line(p, a, b);
}