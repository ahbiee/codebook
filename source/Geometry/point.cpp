#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9; // 用來處理浮點數誤差的極小值

// 符號判斷函數 (極度重要！)
// 判斷一個浮點數是 正數(1)、負數(-1) 還是 0(0)
int sign(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y; //通用double
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // 向量加減法與常數乘除
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double d) const { return Point(x * d, y * d); }
    Point operator/(double d) const { return Point(x / d, y / d); }

    // 判斷兩點是否相等 (利用 sign 來避免浮點數誤差)
    bool operator==(const Point& p) const {
        return sign(x - p.x) == 0 && sign(y - p.y) == 0;
    }

    bool operator<(const Point& a, const Point& b) const{
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

// 在幾何中，向量和點的表示法一樣，給它一個別名增加可讀性
using Vector = Point; 

// 1. 內積 (Dot Product)
// 計算方式：x1*x2 + y1*y2
// 實戰意義：用來判斷兩向量夾角。大於0為銳角，小於0為鈍角，等於0為垂直。
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

// 2. 外積 (Cross Product)
// 計算方式：x1*y2 - x2*y1
// 實戰意義：用來判斷方向與面積。
// 若 cross(a, b) > 0，代表 b 在 a 的逆時針方向 (偏左)
// 若 cross(a, b) < 0，代表 b 在 a 的順時針方向 (偏右)
// 若 cross(a, b) == 0，代表 a 和 b 平行或共線
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}