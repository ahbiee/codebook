// 區間選點: 最少選幾個點，使每個區間 [l, r] 內至少有一個點。依「右端」排序，點盡量放右端
int min_points(vector<pair<int, int>> seg) { // seg = {l, r}
    sort(seg.begin(), seg.end(), [](auto &a, auto &b) { return a.second < b.second; });
    int cnt = 0; ll last = LLONG_MIN;
    for (auto [l, r] : seg)
        if (l > last) cnt++, last = r; // 這個區間還沒被蓋到 → 在它的右端放一個點
    return cnt;
}
// 答案也等於「最多能選幾個互不相交的區間」(同一個 greedy)
