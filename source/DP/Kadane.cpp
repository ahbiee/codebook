// 應用場景： 題目要求在一個陣列中，找出一小段「連續」的數字，使得它們的總和最大。
long long kadane(const vector<long long>& arr) {
    long long max_so_far = -1e18; // 紀錄歷史最大值 (預設極小值以防全負數)
    long long curr_max = 0;       // 紀錄加上當前數字後的局部最大值

    for (long long x : arr) {
        // 核心精神：如果加上自己，比自己單獨一個還要小，那不如「從自己重新開始」
        curr_max = max(x, curr_max + x);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
