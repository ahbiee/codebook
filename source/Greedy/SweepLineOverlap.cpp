// 掃描線: 同一時刻最多重疊幾個區間。開始 +1、結束 -1，依時間排序
int max_overlap(const vector<pair<int, int>> &seg) {
    vector<pair<int, int>> ev;
    for (auto [s, e] : seg) ev.push_back({s, +1}), ev.push_back({e, -1});
    sort(ev.begin(), ev.end()); // 同時間時 -1 排在 +1 前面
    int cur = 0, best = 0;
    for (auto [t, d] : ev) cur += d, best = max(best, cur);
    return best;
}
/* 同一時間點的順序很重要 (和題目定義有關，看清楚！):
   - 半開區間 [s, e)：e 時刻已離開 → 先 -1 再 +1 (上面的預設)
   - 閉區間 [s, e]  ：e 時刻還在   → 先 +1 再 -1 → 把結束事件改成 {e + 1, -1} (整數時間)
   聯集總長度: 掃描時 cur > 0 的區段長度加總
   二維 (矩形面積聯集): x 方向掃描線 + 線段樹維護 y 方向被覆蓋的長度 */
