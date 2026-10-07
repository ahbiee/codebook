// 活動選擇: 找到最多選幾個互不重疊的區間 (或= n - 最少刪除數)。依「結束時間」排序，能選就選
int max_non_overlap(vector<pair<int, int>> seg) { // {start, end}，[s, e) 半開區間
    sort(seg.begin(), seg.end(), [](auto &a, auto &b) { return a.second < b.second; });
    int cnt = 0; ll cur_end = LLONG_MIN; // 一開始什麼都沒選；第一個 (最早結束的) 會在迴圈裡被選到
    for (auto [s, e] : seg) // 寫法已保證 s == e (長度為0) 時也會成功選中
        if (s >= cur_end) cnt++, cur_end = e; // [改] 閉區間 (端點碰到也算重疊): s > cur_end
    return cnt; // cnt 直接是答案
}
// 另一種寫法 (CSES Movie Festival): cnt = 1, cur_end = 第一個的 end，迴圈「從第二個開始」
// 兩種起始值不能混用: cnt = 1 配 LLONG_MIN 會把第一個算兩次
// 有權重 (每個活動有獎勵) → 不能 Greedy，看 DP 的「加權區間排程」(WeightedInterval.cpp)
