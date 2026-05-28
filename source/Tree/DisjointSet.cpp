struct DSU {
    vector<int> f, sz; // 避免使用 size 撞名
    
    void init(n){
        f.resize(n);
        sz.assign(n, 1); // 將每個獨立集合的大小初始化為 1
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int find(int x) { // 路徑壓縮
        return f[x] == x ? x : ( f[x] = find(f[x]) );
    }
    
    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }
    
    // 回傳 bool 有助於在 Kruskal 演算法中判斷是否成功加上一條邊，否則void即可
    bool unite(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        
        // 小掛大優化：永遠讓 fa 是比較大的集合
        if (sz[fa] < sz[fb]) swap(fa, fb); 
        sz[fa] += sz[fb];
        f[fb] = fa;
        return true;
    }
};