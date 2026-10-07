/* 莫隊 (離線區間查詢): 不能用線段樹合併的資訊 (例: 區間內相異數字個數、眾數次數)
   只要「左右端點各移動一格」時能 O(1) 更新答案就能用。O((N + Q) sqrt N) */
const int MAXN = 200005, MAXV = 1000005;
int n, q, a[MAXN], ql[MAXN], qr[MAXN], qid[MAXN], cnt_[MAXV];
ll cur, ans[MAXN];
void add(int i) { if (cnt_[a[i]]++ == 0) cur++; }    // [改] 加入 a[i] 時答案怎麼變
void remove_(int i) { if (--cnt_[a[i]] == 0) cur--; } // [改] 移除 a[i] 時答案怎麼變
void mo() { // 詢問存在 ql[i], qr[i] (0-based、閉區間)
    int B = max(1, (int)(n / sqrt(q + 1)));
    iota(qid, qid + q, 0);
    sort(qid, qid + q, [&](int x, int y) {
        if (ql[x] / B != ql[y] / B) return ql[x] < ql[y];
        return (ql[x] / B & 1) ? qr[x] > qr[y] : qr[x] < qr[y]; // 奇偶交錯，常數小一半
    });
    int L = 0, R = -1; cur = 0;
    for (int k = 0; k < q; k++) {
        int i = qid[k];
        while (R < qr[i]) add(++R);      // 先擴張再縮小，避免區間變成負的
        while (L > ql[i]) add(--L);
        while (R > qr[i]) remove_(R--);
        while (L < ql[i]) remove_(L++);
        ans[i] = cur;
    }
}
// a[i] 值很大時先座標壓縮。有修改的版本 (帶修莫隊) 很少考，遇到再說
