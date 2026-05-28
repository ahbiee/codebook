using ll = long long;

vector<ll> arr, sum, add; //宣告成全域，arr是原始數據，sum是範圍累加和，add是lazy tag儲存的值

void up(int i){ // 往上加回去
    sum[i] = sum[i*2] + sum[i*2+1];
}

void lazy(int i, ll v, int n){ // 懶標記(lazy tag)，暫存當前覆蓋範圍
    sum[i] += v*n;
    add[i] += v;
}

void down(int i, int ln, int rn){ // 往下分發lazy tag
    if(add[i] != 0){
        lazy(i*2, add[i], ln);
        lazy(i*2+1, add[i], rn);
        add[i] = 0;
    }
}

void build(int l, int r, int i){ // 遞迴式初始化 (init)
    if(l == r) sum[i] = arr[l]; // 如果區間只剩一個數值，就直接賦值
    else{
        int mid = l + (r-l)/2; // 找中點 
        build(l, mid, i*2); // 左半邊build
        build(mid+1, r, i*2+1); // 右半邊build
        up(i); // 自己 = 左+右 區間和
    }
    add[i] = 0; // 初始化所有add[i] = 0
}

void update(int jobl, int jobr, ll jobv, int l, int r, int i){ // 更新區間數值(jobl ~ jobr 加上 jobv)，用l, r, i判斷範圍
    if(jobl <= l && r <= jobr) lazy(i, jobv, r-l+1); // 如果範圍被包的話就直接lazy
    else{
        int mid = l + (r-l)/2;
        down(i, mid-l+1, r-mid); // 記得往下分發lazy tag
        if(jobl <= mid) update(jobl, jobr, jobv, l, mid, i*2); // 判斷左右區段是否需要更新
        if(jobr > mid) update(jobl, jobr, jobv, mid+1, r, i*2+1);
        up(i); // 最後往上加總回去更新sum
    }
}

ll query(int jobl, int jobr, int l, int r, int i){
    if(jobl <= l && r <= jobr) return sum[i]; // 如果包範圍就直接return回去
    
    int mid = l + (r-l)/2;
    down(i, mid-l+1, r-mid); // 記得往下分發lazy tag
    ll total = 0;
    if(jobl <= mid) total += query(jobl, jobr, l, mid, i*2);
    if(jobr > mid) total += query(jobl, jobr, mid+1, r, i*2+1);
    return total; // 因為只是query，沒有修改，所以不用up更新回去
}

int main() {
    int n, m;
    cin >> n >> m;
    arr.assign(n+1, 0);
    sum.assign(4*(n+1), 0); // 大小必須開到4倍n+1
    add.assign(4*(n+1), 0);
    
    for(int i=1; i<=n; ++i) cin >> arr[i];
    build(1, n, 1);
    int op;
    ll x, y, k;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x >> y >> k;
            update(x, y, k, 1, n, 1);
        }
        else{
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << '\n';
        }
    }
    return 0;
}