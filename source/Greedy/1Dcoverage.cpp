/*
題目敘述: 給定 N 個灑水器，每個灑水器包含座標P 與半徑R，已知草坪長度為L，寬度為W，請問最少需要開啟幾個灑水器就能覆蓋整個區間 (或指定哪些灑水器)

題解: 先將灑水器圍轉化為 一個struct point，用l, r區間表示能覆蓋的左右範圍，然後自訂operator<
1. 用開始位置排序
2. 每次都在 小於當前右界的區間中，選擇能往右最多的那個
3. 重複直到右區間<L，得到最少數量；或者是在當前右邊界內找不到可選擇的表示不存在解
*/
const double eps = 1e-8;
struct point{
    double L, R;
    bool operator<(const point&o) const{
        return L < o.L;
    }
};

vector<point> v;
double pos, rad;
for(int i=0; i<n; ++i){
    cin >> pos >> rad;
    double real;
    if(rad - w/2.0 <  eps) continue; // 判斷如果半徑小於寬度就不可能被選，直接不加入
    real = sqrt(rad*rad - (w/2.0)*(w/2.0)); // real表示實際可覆蓋距離
    v.push_back({pos-real, pos+real});
}
sort(v.begin(), v.end());

int cnt = 0; // 總計數，如果要指定哪些灑水器就用vector存每次加入的
int i = 0;
double furthest = 0.0;
bool noAns = false;

while(L - furthest > eps){ // L > furthest
    double cur = furthest;
    while(i < v.size() && v[i].L - furthest < eps){
        cur = max(cur, v[i].R);
        ++i;
    }
    if(cur - furthest < eps){
        noAns = true;
        break;
    }
    furthest = cur;
    ++cnt;
}
if(noAns) cout << -1 << '\n';
else cout << cnt << '\n'; 