vector<int> lcs_to_lis(const vector<int>& A, const vector<int>& B) {
    unordered_map<int, vector<int>> pos_A;
    
    // 1. 紀錄序列 A 中每個元素出現的所有索引
    for (int i = 0; i < A.size(); ++i) {
        pos_A[A[i]].push_back(i);
    }

    vector<int> transformed;
    
    // 2. 走訪序列 B，將其替換為 A 中的索引
    for (int x : B) {
        if (pos_A.count(x)) {
            // 重點：必須從大到小（反向）加入索引！
            // 避免 B 中的同一個元素，匹配到 A 中的多個相同元素。
            for (int i = pos_A[x].size() - 1; i >= 0; --i) {
                transformed.push_back(pos_A[x][i]);
            }
        }
    }

    // 3. 找出轉換後的 LIS 陣列
    vector<int> lis;
    for (int x : transformed) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x; // 貪心策略：替換掉第一個大於等於 x 的數字
        }
    }

    return lis; // LIS長度與LCS一致，可直接 return lis.size(); 就是 LCS 的長度
}

/*
如果要對 LIS 序列找 LCS：
1. A 為原序列，B 為 sort(A)
2. 直接對 A、B 做 LCS
*/