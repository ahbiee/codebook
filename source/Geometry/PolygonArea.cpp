#include <cmath>
using namespace std;

// 依賴前面的 Point 結構與 cross 函數

const int MAXV = 1005;
Point poly[MAXV]; // 儲存多邊形的頂點 (必須依照順時針或逆時針順序排列)
int n;            // 頂點數量

// 求任意多邊形面積 (Shoelace Formula)
double polygon_area() {
    double area = 0;
    for (int i = 0; i < n; ++i) {
        // 讓最後一個點與第 0 個點連線，形成封閉圖形
        int next = (i + 1) % n; 
        area += cross(poly[i], poly[next]);
    }
    // 外積和有可能是負的 (取決於順逆時針)，所以取絕對值並除以 2
    return fabs(area) / 2.0; 
}

/*
補充: 假設兩個矩形的左下角與右上角座標分別為
矩形 A：左下 (x1, y1)，右上 (x2, y2)
矩形 B：左下 (x3, y3)，右上 (x4, y4)

把矩形投影到 X 軸上，就變成了兩個線段 [x1, x2] 與 [x3, x4]
它們重疊的長度，等於「兩個右邊界的較小值」減去「兩個左邊界的較大值」
如果算出來是負數，代表它們根本沒碰到，直接跟 0 取最大值即可

因此計算矩形交集面積即為
int W = max(0, min(x2, x4) - max(x1, x3));
int H = max(0, min(y2, y4) - max(y1, y3));
int intersect_area = W * H;
*/