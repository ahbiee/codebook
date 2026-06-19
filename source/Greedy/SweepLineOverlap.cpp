// 解決「最大區間重疊數」(簡易版Sweep Line)
int sweep_line_overlap(const vector<pair<int, int>>& intervals) {
    // 儲存所有事件: pair<時間點, 變化量>
    vector<pair<int, int>> events;
    
    for (auto& interval : intervals) {
        events.push_back({interval.first, 1});   // 開始時間，需求 +1
        events.push_back({interval.second, -1}); // 結束時間，需求 -1
    }

    // 排序規則：先按時間由小到大排；
    // 若時間相同，變化量小的 (-1) 會自動排在 (+1) 前面！
    // 這確保了「先退房間，再借房間」，不產生多餘的重疊。
    sort(events.begin(), events.end());

    int current_overlap = 0;
    int max_overlap = 0;

    for (auto& event : events) {
        current_overlap += event.second;
        max_overlap = max(max_overlap, current_overlap);
    }

    return max_overlap;
}