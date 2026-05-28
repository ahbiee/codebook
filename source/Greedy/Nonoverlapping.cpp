int countRemoves(vector<pair<int, int>> &intervals) {
    if(intervals.empty()) return 0; // 不需要移除任何東西
    
    // 用結束時間做排序
    sort(intervals.begin(), intervals.end(), [](const auto&a, const auto&b){return a.second < b.second;});

    int removed = 0;
    int cur_end = intervals[0].second; // 一開始必定選第一個任務
    for(int i=1; i<intervals.size(); ++i){ // 遍歷所有任務
        if(cur_end > intervals[i].first) ++removed; // 如果我目前的end能覆蓋到當前i的左邊界就移除i
        else cur_end = intervals[i].second; // 否則我就要選i，並設為當前右邊界
    }

    return removed;
}