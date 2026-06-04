struct Job {
    int time, deadline;
    // 依到期時間由早到晚排序
    bool operator<(const Job& o) const {
        return deadline < o.deadline;
    }
};

int minimizeLateness(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end());

    int current_time = 0;
    int max_lateness = 0;

    for (const auto& job : jobs) {
        current_time += job.time;
        // 延遲時間 = 完成時間 - 到期時間。若提早完成則延遲為 0
        int lateness = max(0, current_time - job.deadline);
        max_lateness = max(max_lateness, lateness);
    }
    return max_lateness;
}