/* === 同向雙指針 ===
例如: Subarray sum maximum length
給定一個不含負數的array與一個定值x，要求在array中找到總合為x的最長subarray(不可分割)，輸出最長的長度
若有負數，使用 PrefixSum + Map
*/
int arr[n] = {...};
int total = 0, max_len = -1;
for(int l = 0, r = 0; r < n; ++r){ // O(n)，r往右移n次
    total += arr[r];
    while(total > x && l <= r){
        total -= arr[l]; // 扣掉最左邊的值
        ++l; // l 右移
    }
    if(total == x){
        max_len = max(max_len, r-l+1);
    }
}

/*
題意: 給定 target 與 array nums，求nums中 >= target 的 subarray，最小長度是多少
題解: r 指針不斷向右跑，每次都加新數字進來；隨後判斷目前值是否超過target，如果超過就不斷地將最左側(l 指針)的數字剔除，最後回傳 len (我們維護的最小長度)
*/
int minSubArrayLen(int target, vector<int>& nums) {
    int total = 0;
    int len = 0x3f3f3f3f;
    for(int l=0, r=0; r<nums.size(); ++r){
        total += nums[r];
        while(total >= target){
            len = min(len, r-l+1);
            total -= nums[l++];
        }
    }
    return len == 0x3f3f3f3f ? 0 : len;
}

/*
題意：給定一個array，請問在固定長度 len 的情況下所能得到的subarray的minimum
*/
int minLenSubArray(int len, vector<int>& nums) {
    if (nums.size() < len) return 0; 

    int cur = 0;
    for (int i = 0; i < len; ++i) cur += nums[i]; // 最一開始就是前len個
    int mini = cur;
    for (int i = len; i < nums.size(); ++i) {
        cur += nums[i];         // 加上右邊新進來的元素
        cur -= nums[i - len];   // 扣掉左邊被擠出去的元素
        mini = min(mini, cur);
    }
    
    return mini;
}

/* === 對向雙指針 ===
例如: 2 Sum
給定一個array與一個定值x，找出在array中是否存在兩個數的和為x
*/
int arr[n] = {...};
sort(arr, arr+n); // 先做排序，2 Sum要有序才能用Two-Pointers O(nlogn)
bool found = false;
int l = 0, r = n-1;
while(l < r && !found){  // 當 l == r 即表示不存在
    int sum = arr[l] + arr[r];
    if(sum == x) found = true;
    else if(sum < x) ++l; // 如果sum比x小，左邊界往右移
    else --r; // 反之往左移
}

/*
更難的 3 Sum 最佳解也是用 Two-Pointer (O(N^2))
給定一個array與一個定值x，找出在array中是否存在三個數的和為x
*/
int arr[n] = {...}; // 給定陣列
sort(arr, arr + n); // 必須先排序 O(nlogn)
bool found = false;

// 先枚舉第一個數字(從0~n-3，最後兩個(n-2, n-1)是l, r)
for(int i = 0; i < n - 2; ++i){
    // [優化] 如果當前數字與前一個相同，則跳過，避免算出重複的組合 (不能直接unique是因為如果數字 x == 3*k，k被unique了就本來有解變無解)
    if(i > 0 && arr[i] == arr[i - 1]) continue; 

    int target = x - arr[i]; // 剩下的兩數之和目標 -> 從這裡開始變回 2 Sum
    int l = i + 1, r = n - 1; // 雙指針範圍從 i 的下一個到結尾

    while(l < r){
        int sum = arr[l] + arr[r];
        
        if(sum == target){
            found = true;
            break; // 如果只要找「是否存在」就可以直接 break
            
            /* 若是要找「所有不重複組合」，可以改成：
            ans.push_back({arr[i], arr[l], arr[r]});
            while(l < r && arr[l] == arr[l+1]) ++l; // 跳過重複的左邊界
            while(l < r && arr[r] == arr[r-1]) --r; // 跳過重複的右邊界
            ++l; --r; // 繼續尋找下一組
            */
        }
        else if(sum < target){
            ++l; // 太小，左邊界右移
        } else {
            --r; // 太大，右邊界左移
        }
    }
    if(found) break; // 如果已找到，提早結束外層迴圈
}

// === 快慢雙指針 ===
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        break;
}