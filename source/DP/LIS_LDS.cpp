/*
二維套疊問題 (Russian Doll Envelopes / 箱子堆疊)
題意： 給你一堆信封，每個有寬度和高度，問你最多可以把幾個信封像俄羅斯娃娃一樣套在一起
解法： 將寬度由小到大排序；當寬度相同時，高度必須由大到小排。接著，直接對高度的陣列求 LIS

橋樑/連線不交叉問題 (Building Bridges)
題意： 南岸和北岸各有 N 座城市，題目給定連線配對。要求建最多座橋，且橋與橋之間不能交叉
解法： 把南岸的城市編號由小到大排序，然後對它們對應的北岸城市編號求 LIS

最少覆蓋路徑 / 導彈攔截系統 (Dilworth 定理)
題意： 系統每次只能攔截「高度遞減」的飛彈。給你一連串飛彈的高度，問你「最少」需要裝備幾套攔截系統？
解法： 「最少需要的遞減子序列數量」 等價於 「最長遞增子序列 (LIS) 的長度」。求出 LIS 長度就直接是答案！

最長雙坡子序列 (Bitonic Subsequence)
題意： 求一個數列，先嚴格遞增再嚴格遞減的最長長度。
解法： 從左到右跑一次 LIS，記錄每個位置結尾的 LIS 長度；再從右到左跑一次 LIS（相當於 LDS），記錄每個位置開頭的 LDS 長度。兩者相加減 1 的最大值即為所求。
*/

// 1. 最長遞增子序列 (LIS) - (嚴格)遞增
int get_lis(const vector<int>& arr) {
    vector<int> dp; 
    for (int x : arr) {
        // lower_bound: 找第一個 >= x 的位置 (若要求非嚴格遞增，改用 upper_bound)
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x); // 比所有數字都大，序列長度 + 1
        } else {
            *it = x; // 貪心策略：替換成較小的結尾，增加後續串接的潛力
        }
    }
    return dp.size(); // dp 陣列的長度就是 LIS 的長度 (注意：dp 內容不一定是真實 LIS)
}

// 2. 最長遞減子序列 (LDS) - (嚴格)遞減
int get_lds(const vector<int>& arr) {
    vector<int> dp;
    for (int x : arr) {
        // LDS 只需要搭配 greater<int>() 來找第一個 <= x 的位置
        // 若要求非嚴格遞減，改用 less_equal<int>() 等自訂比較
        auto it = lower_bound(dp.begin(), dp.end(), x, greater<int>());
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    return dp.size();
}
