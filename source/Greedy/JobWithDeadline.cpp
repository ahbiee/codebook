struct Task {
    int deadline, penalty;
    // 依懲罰由大到小排序
    bool operator<(const Task& o) const {
        return penalty > o.penalty;
    }
};

// 利用並查集快速找尋「最晚可用的空閒天數」
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
};

long long taskScheduling(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end());

    int max_deadline = 0;
    for (const auto& t : tasks) {
        max_deadline = max(max_deadline, t.deadline);
    }

    DSU dsu(max_deadline);
    long long total_penalty = 0;

    for (const auto& t : tasks) {
        // 尋找此任務到期日之前，最晚可用的空檔
        int available_slot = dsu.find(t.deadline);

        if (available_slot > 0) {
            // 有空位：佔用這天，並將這天的 parent 指向前一天
            dsu.parent[available_slot] = dsu.find(available_slot - 1);
        } else {
            // 沒空位：只能放棄並承受懲罰
            total_penalty += t.penalty;
        }
    }
    return total_penalty;
}