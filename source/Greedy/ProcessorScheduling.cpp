struct Machine {
    int id;
    long long completion_time;
    // Min-Heap：優先選擇最快空閒的機器。若時間相同，優先分給 ID 小的
    bool operator>(const Machine& o) const {
        if (completion_time != o.completion_time)
            return completion_time > o.completion_time;
        return id > o.id; 
    }
};

long long multiprocessorScheduling(vector<int>& jobs, int m) {
    // 工作依耗時由大到小排序 (Longest Processing Time first)
    sort(jobs.begin(), jobs.end(), greater<int>());

    priority_queue<Machine, vector<Machine>, greater<Machine>> pq;
    for (int i = 0; i < m; ++i) pq.push({i, 0});

    // 依序把工作派給最快結束的機器
    for (int job_time : jobs) {
        Machine earliest = pq.top();
        pq.pop();

        earliest.completion_time += job_time;
        pq.push(earliest);
    }

    // 找出所有機器中最晚完工的時間
    long long max_time = 0;
    while (!pq.empty()) {
        max_time = max(max_time, pq.top().completion_time);
        pq.pop();
    }

    return max_time;
}