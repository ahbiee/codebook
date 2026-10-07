// 最少會議室: 依開始時間排序，heap 存「每間使用中房間的結束時間」
int min_rooms(vector<pair<int, int>> seg) { // {start, end}
    sort(seg.begin(), seg.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [s, e] : seg) {
        if (!pq.empty() && pq.top() <= s) pq.pop(); // [改] 閉區間 (結束當下不能接): <
        pq.push(e);
    }
    return pq.size();
}
// 要輸出每個會議分到哪間: heap 改存 {結束時間, 房號}，pop 出來的房號給目前的會議
// 答案也等於「同一時間最多重疊幾個區間」→ 也可以用 SweepLine
