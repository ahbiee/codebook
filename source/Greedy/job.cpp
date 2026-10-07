// 最小化最大延遲: 每個工作 {耗時, 期限}，一台機器依序做。依「期限」由早到晚做最好
ll min_max_lateness(vector<pair<ll, ll>> jobs) { // {time, deadline}
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a.second < b.second; });
    ll t = 0, ans = 0;
    for (auto [len, dl] : jobs) t += len, ans = max(ans, t - dl);
    return ans; // 0 代表全部準時
}
// 最小化「總完成時間」(或平均等待時間): 依耗時由短到長 (SJF)
// 加權版 Σ w_i * C_i: 依 time / weight 由小到大 (比較時用交叉相乘避免浮點)
// 交換論證: 相鄰兩工作 i, j 交換前後的代價比較 → 得到排序的比較函式 (自己寫 cmp 的萬用方法)
