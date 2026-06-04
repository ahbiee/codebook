struct Interval {
    int l, r;
    // 依右界由小到大排序，右界相同時左界小的優先
    bool operator<(const Interval& o) const {
        if (r != o.r) return r < o.r;
        return l < o.l;
    }
};

int minPoints(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());

    int cnt = 1;
    int current_r = intervals[0].r;

    for (int i = 1; i < intervals.size(); ++i) {
        // 若當前區間左界 > 目前紀錄的右界，代表無法共用同一個點
        if (intervals[i].l > current_r) {
            cnt++;
            current_r = intervals[i].r; // 更新右界
        }
    }
    return cnt;
}