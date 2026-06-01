#include <algorithm>
using namespace std;

// 依賴前面的 Point 結構與 cross 函數

const int MAXN = 100005;
Point pts[MAXN];  // 存放所有輸入的點
Point hull[MAXN]; // 存放最終構成凸包的點
int n;            // 輸入點的數量

// 回傳凸包上的頂點數量
int convex_hull() {
    // 點太少直接就是凸包
    if (n <= 2) {
        for (int i = 0; i < n; ++i) hull[i] = pts[i];
        return n;
    }

    // 1. 將所有點由左至右、下至上排序
    sort(pts, pts + n);

    int m = 0; // m 代表目前凸包 (hull) 裡面有幾個點

    // 2. 蓋下半部凸包 (Lower Hull) - 從左走到右
    for (int i = 0; i < n; ++i) {
        // 【核心邏輯】
        // cross <= 0 代表「往右轉」或是「直走」。
        // 凸包的邊緣必須一直「往左轉」，如果發現往右轉（凹進去了），就把最後一個點踢掉！
        // (若想保留共線的點，把 <= 改成 < 即可)
        while (m >= 2 && cross(hull[m - 1] - hull[m - 2], pts[i] - hull[m - 2]) <= 0) {
            m--; // 踢掉最後一個點
        }
        hull[m++] = pts[i]; // 把新點加進來
    }

    // 3. 蓋上半部凸包 (Upper Hull) - 從右走回左
    // 注意：下半部已經蓋了 m 個點，為了不踢掉下半部的點，我們設定底線為 t
    int t = m + 1;
    for (int i = n - 2; i >= 0; --i) {
        // 邏輯跟上面一模一樣，只是倒著走
        while (m >= t && cross(hull[m - 1] - hull[m - 2], pts[i] - hull[m - 2]) <= 0) {
            m--; 
        }
        hull[m++] = pts[i];
    }

    // 4. 起點 (最左下的點) 會在頭尾被重複加入一次，所以總數量要減 1
    return m - 1;
    // 如果需要知道所有選擇的點，就是hull[0]~hull[m-1]
    // 然後有了這些點又可以用面積公式直接得到整個的面積
}