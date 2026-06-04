long long huffmanCost(const vector<int>& weights) {
    // 宣告 Min-Heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int w : weights) pq.push(w);

    long long total_cost = 0;

    // 每次挑選最小的兩堆合併，直到只剩一堆
    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        long long merged = first + second;
        total_cost += merged;
        pq.push(merged); // 將合併後的新重量塞回 Heap
    }

    return total_cost;
}