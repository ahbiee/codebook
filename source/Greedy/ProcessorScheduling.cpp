// m 台機器、n 個工作，最小化最晚完工時間 (NP-hard)。LPT 近似: 耗時大的先做，交給最早空出來的機器
ll lpt_schedule(vector<ll> jobs, int m) {
    sort(jobs.rbegin(), jobs.rend());
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // {完工時間, 機器編號}
    for (int i = 0; i < m; i++) pq.push({0, i});
    for (ll t : jobs) {
        auto [done, id] = pq.top(); pq.pop();
        pq.push({done + t, id});
    }
    ll ans = 0;
    while (!pq.empty()) ans = max(ans, pq.top().first), pq.pop();
    return ans;
}
// 注意: 這只是近似解！題目要精確最佳解時，可以「對答案二分搜 + 檢查能不能塞進 m 台」
