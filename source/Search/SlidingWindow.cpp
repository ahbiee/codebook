// 題意: 給定 target 與 array nums，求nums中 >= target 的 subarray，最小長度是多少

// 題解: r 指針不斷向右跑，每次都加新數字進來；隨後判斷目前值是否超過target，如果超過就不斷地將最左側(l 指針)的數字剔除，最後回傳 len (我們維護的最小長度)
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