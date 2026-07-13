deque<int> dq; // 注意一樣是存 index
int k = 5; // 最大窗口大小 maximum window length

// 以尋找最長遞減序列為例 (maximum)
for (int i = 0; i < n; i++) {
    // pop掉超出窗口的部分
    while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

    // 維持遞減狀態
    while (!dq.empty() && a[dq.back()] <= a[i])
        dq.pop_back();
    // 如果是minimum的話 改成
    while (!dq.empty() && a[dq.back()] >= a[i])
    

    dq.push_back(i);

    if (i >= k - 1)
        ans.push_back(a[dq.front()]);
}