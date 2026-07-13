// === Next Greater Element === 
int a[105] = {}; // 存好值的 array
int ans[105] = {}; // 存答案的 array
stack<int> st; // 注意是存 index 不是value，value在 a[st.top()]

for (int i = 0; i < n; i++) {
    // 第一輪會跳過，因為st是empty
    while (!st.empty() && a[st.top()] < a[i]) {
        ans[st.top()] = i;
        st.pop();
    }

    st.push(i);
}

while (!st.empty()) { // 重設
    ans[st.top()] = -1;
    st.pop();
}

// === Next Smaller Element ===
只需要把 while 改成 
while (!st.empty() && a[st.top()] > a[i]) // (因為要找更小)

// === Previous Greater ===
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i])
        st.pop();

    if (st.empty())
        ans[i] = -1;
    else
        ans[i] = st.top();

    st.push(i);
}

while (!st.empty()) {
    ans[st.top()] = -1;
    st.pop();
}