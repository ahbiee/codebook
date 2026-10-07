// 堆疊存 index。O(N)。0-based，找不到為 -1
const int MAXN = 200005;
int n, a[MAXN], nxt[MAXN], prv[MAXN];
void next_greater() { // nxt[i] = i 右邊第一個「> a[i]」的位置
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) { // [改] 下一個更小: >
            nxt[st.top()] = i; st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) nxt[st.top()] = -1, st.pop();
}
void prev_greater() { // prv[i] = i 左邊第一個「> a[i]」的位置
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop(); // [改] 前一個更小: >=
        prv[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}
/* [應用] 直方圖最大矩形: 對每個 i 找左右第一個「更矮」的 L,R，
   面積 = a[i] * (R - L - 1)。「以 a[i] 為最小值的最長區間」都是這招 */
