#include <cmath>
using namespace std;

// 依賴前面的 Point, sign, cross, length 函數

struct Circle {
    Point c;  // 圓心
    double r; // 半徑
    Circle(Point _c = Point(0, 0), double _r = 0) : c(_c), r(_r) {}
};

// 三點求圓 (求三角形外接圓)
Circle get_circle(Point a, Point b, Point c) {
    // 將座標平移，以 c 點為原點計算，可大幅簡化方程式
    double a2 = a.x - c.x, a3 = a.y - c.y;
    double b2 = b.x - c.x, b3 = b.y - c.y;
    
    double d1 = a.x * a.x + a.y * a.y - c.x * c.x - c.y * c.y;
    double d2 = b.x * b.x + b.y * b.y - c.x * c.x - c.y * c.y;
    
    // 行列式值 det 其實剛好就是 cross(a-c, b-c)
    double det = a2 * b3 - a3 * b2; 
    
    // 如果外積為 0，代表三點共線，無法構成圓形
    if (sign(det) == 0) return Circle(Point(1e18, 1e18), -1); 
    
    // 利用克拉瑪公式求解
    double cx = (b3 * d1 - a3 * d2) / (2 * det);
    double cy = (a2 * d2 - b2 * d1) / (2 * det);
    Point center(cx, cy);
    
    // 半徑就是圓心到任意頂點 (如 a 點) 的距離
    return Circle(center, length(center - a));
}

/*
補充: 四心
外心(三點求圓)：利用中垂線交點來求。
重心：就是座標平均值 (A + B + C) / 3。
內心：內切圓的圓心。公式是三個頂點按對邊長度的加權平均：(A*a + B*b + C*c) / (a + b + c)。
垂心：三條高的交點。利用歐拉線公式推導：垂心 = 3 * 重心 - 2 * 外心。
*/