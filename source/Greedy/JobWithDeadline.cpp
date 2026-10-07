// 每個工作耗時 1、有期限 d 與懲罰 p (或利潤)。逾期要付懲罰，求最小總懲罰 (= 最大化準時的利潤)
// 方法一: 懲罰大的先排，放在「期限內最晚的空閒時間」，用 DSU 找空位。近乎 O(N)，期限 <= 1e6
ll min_penalty_dsu(vector<pair<int, int>> jobs) { // {deadline, penalty}
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a.second > b.second; });
    int maxd = 0;
    for (auto [d, p] : jobs) maxd = max(maxd, d);
    vector<int> f(maxd + 1);
    iota(f.begin(), f.end(), 0);
    function<int(int)> find = [&](int x) { return f[x] == x ? x : f[x] = find(f[x]); };
    ll pen = 0;
    for (auto [d, p] : jobs) {
        int slot = find(min(d, maxd));
        if (slot > 0) f[slot] = slot - 1; // 佔用 slot，之後找到 slot 會跳到更早
        else pen += p;                    // 沒有空位 → 逾期
    }
    return pen;
}
// 方法二: 期限很大 (1e9) 時，依期限排序 + min-heap 存已選工作的懲罰。O(N log N)
ll min_penalty_heap(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    ll total = 0, kept = 0;
    for (auto [d, p] : jobs) {
        total += p; pq.push(p); kept += p;
        if ((int)pq.size() > d) kept -= pq.top(), pq.pop(); // 排太多，丟掉懲罰最小的
    }
    return total - kept;
}
// 耗時不是 1 (工作 {耗時 t, 期限 d})，最多完成幾個: 依期限排序，累計時間超過 d 就丟掉耗時最長的 (max-heap)
