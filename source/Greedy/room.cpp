struct Interval {
    int st, ed;
    bool operator<(const Interval &o) const {
        if (st != o.st) return st < o.st;  // 先以開始時間排序
        return ed < o.ed; // 開始時間相同，較早結束的排前面
    }
};

int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;

    // 1. 依照開始時間排序
    sort(intervals.begin(), intervals.end());

    // 2. 建立一個 Min-Heap，專門用來儲存「使用中會議室的結束時間」
    // !!如果需要印出順序，只要把int(結束時間)改成pair<int, int>(結束時間, 房間編號)!!
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // 3. 掃描每一個會議
    for (const auto& interval : intervals) {
        // 如果pq不為空，且最早結束的會議已經可以使用了 (當前會議的開始時間 >= 最早空出來的房間時間)
        if (!min_heap.empty() && interval.st >= min_heap.top()) {
            min_heap.pop(); // 該會議室空出來了，把舊的結束時間 pop 掉 (準備重複利用)
        }
        
        // 把當前會議的結束時間塞進去 (代表佔用了一間會議室)
        // 不管是開了一間新房間，還是接續前一間，當前的結束時間都要記錄
        min_heap.push(interval.ed);
    }

    return min_heap.size(); // 最終 Heap 裡面剩下幾個元素，就代表我們同時需要幾間會議室
}