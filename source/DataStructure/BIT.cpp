struct BIT {
    int n;
    vector<long long> tree; // 使用 long long 避免區間總和溢位

    void init(int sz){
        n = sz;
        tree.assign(sz+1, 0);
    }

    // lowbit：取得二進位中最右邊的 1
    inline int lowbit(int x) {
        return x & (-x);
    }

    // 單點修改：在位置 x 加上了 val
    void add(int x, long long val) {
        for (; x <= n; x += lowbit(x)) {
            tree[x] += val;
        }
    }

    // 前綴查詢：計算 [1, x] 的總和
    long long query(int x) {
        long long sum = 0;
        for (; x > 0; x -= lowbit(x)) {
            sum += tree[x];
        }
        return sum;
    }

    // 區間查詢：計算 [l, r] 的總和 (前綴和相減概念)
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};