/* 區間覆蓋: 用最少的區間蓋滿 [0, L]。灑水器版 (UVa 10382): 草地寬 W，
   灑水器在 pos、半徑 r，能蓋到的範圍是 pos ± sqrt(r^2 - (W/2)^2)
   作法: 依左端排序，每次在「左端 <= 目前已蓋到的位置」的區間中選右端最遠的 */
const double eps = 1e-9;
int min_cover(vector<pair<double, double>> seg, double L) { // seg = {左, 右}，無解回傳 -1
    sort(seg.begin(), seg.end());
    int cnt = 0, i = 0, n = seg.size();
    double reach = 0;                   // [改] 起點
    while (reach < L - eps) {
        double best = reach;
        while (i < n && seg[i].first <= reach + eps) best = max(best, seg[i].second), i++;
        if (best <= reach + eps) return -1; // 接不上
        reach = best; cnt++;            // 要輸出選了哪些: 記錄 best 是哪個區間
    }
    return cnt;
}
// 灑水器轉區間: if (r * 2 <= W) 跳過；half = sqrt(r*r - W*W/4.0); seg.push_back({pos - half, pos + half});
// 整數點版本 (要蓋住點 1..L，[1,3] 與 [4,5] 算接起來): 條件改成 seg[i].first <= reach + 1
