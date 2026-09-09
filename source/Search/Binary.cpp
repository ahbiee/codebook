Binary Search = 找答案, 但不一定是對陣列二分搜

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
要求答案具有單調性 即 X 合法，則 <= 或 >= X 者都合法，常見於構造題

例題: 給定長度為N的前綴和正負號狀態 (+, -, 0)，求構造符合狀態且元素不含0的陣列內元素最大絕對值的最小值。
如: +0++- 最小cost為2，正確array為: [2, -2, 2, -1, -2]，而非 [1, -1, 1, 1, -3]
*/
bool check(int M, int n, const string& s) { // 步長為M
    long long L = 0, R = 0; // 答案可達到的左(低)、右(高)邊界
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        long long prevL = L, prevR = R;
        
        L = L - M;
        R = R + M;
        
        if (c == '+') L = max(L, 1LL); // 要求+，左邊界至少要是1
        else if (c == '-') R = min(R, -1LL); // 要求-，右邊界至少要是-1
        else if (c == '0') { // 要求0，左右邊界都必須0
            L = max(L, 0LL);
            R = min(R, 0LL);
        }
        
        if (M == 1) {
            if (abs(L) % 2 != (i + 1) % 2) L++;
            if (abs(R) % 2 != (i + 1) % 2) R--;
        } else {
            if (prevL == prevR && L == prevL && R == prevR) { // L, R 因為M不夠大，被迫不變(a為0)
                return false;
            }
        }
        
        if (L > R) return false; // 如果左邊界大於右邊界則這個M無法成功
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int left = 1, right = n, ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, n, s)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << "\n";
}

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