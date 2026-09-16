int n; // 數值上界，BIT的範圍從1~n
vector<long long> tree; // 使用 ll 避免區間總和溢位

void init(int sz){
    n = sz;
    tree.assign(sz+1, 0);
}

inline int lowbit(int x) { // 取得二進位中最右邊的 1
    return x & (-x);
}

void add(int x, long long val) { // 在位置 x 加上了 val
    while(x <= n) {
        tree[x] += val;
        x += lowbit(x);
    }
}

long long query(int x) { // 計算 [1, x] 的總和
    long long sum = 0;
    while(x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

long long query(int l, int r) { // 計算 [l, r] 的總和 (前綴和相減)
    return query(r) - query(l - 1);
}
