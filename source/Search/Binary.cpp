Binary Search = 找答案，但不一定是對陣列二分搜

// === 基本找值 === 
// 需要在sorted array
while(l <= r){
    int mid = l + (r-l)/2; // 避免 overflow
    if(mid == target) return mid;
    else if(mid < target) l = mid+1; // mid在target左邊
    else r = mid-1;
}
// 可以直接用 lower_bound(st, ed, target) 找位置

// === 對答案二分搜 ===
/* 
找 「最大值的最小值 Minimax」 或 「最小值的最大值 Maximin」
要求答案具有單調性 即 X 合法，則 <= 或 >= X 者都合法
*/

// === 實數二分搜 ===
/*
需要用 eps 來決定停止狀態 while(r - l > eps)
或者是固定迭代次數，例如 for 100次後停下
*/

// === 找第一個合法(最小) === 
// 答案必在 [l, r] 間
while (l < r) {
    int mid = l + (r - l) / 2;

    if (checkValid(mid))
        r = mid; // 縮短右邊界，盡可能找最小
    else
        l = mid + 1;
}
return l; // 回傳是找到的左邊界

// === 最後一個合法(最大) ===
while (l < r) {
    int mid = l + (r - l + 1) / 2; // 一定要 +1 才能找最大

    if (checkValid(mid))
        l = mid; // 縮短左邊界，盡可能找最大
    else
        r = mid - 1;
}
return l;