// 兩序列 LCS，當「每個值在 A 中出現次數很少」(例如 A、B 都是排列) 時 O(K log K)
// 把 B 中每個數換成它在 A 中的位置 (由大到小放)，對新序列求嚴格 LIS = LCS 長度
int lcs_by_lis(const vector<int> &A, const vector<int> &B) {
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < (int)A.size(); i++) pos[A[i]].push_back(i);
    vector<int> seq;
    for (int x : B) {
        auto it = pos.find(x);
        if (it == pos.end()) continue;
        for (int k = (int)it->second.size() - 1; k >= 0; k--) seq.push_back(it->second[k]); // 反向避免同一個 B 元素配到兩次
    }
    vector<int> tail;
    for (int x : seq) {
        auto p = lower_bound(tail.begin(), tail.end(), x);
        if (p == tail.end()) tail.push_back(x); else *p = x;
    }
    return tail.size();
}
