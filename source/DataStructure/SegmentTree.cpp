// 1-based。區間加值 + 區間和 (lazy)。改成 max/min 只要改有 [改] 的行
const int MAXN = 200005;
int n;
ll a[MAXN], t[4 * MAXN], lz[4 * MAXN]; // t: 節點答案, lz: 還沒往下傳的加值

void apply_tag(int id, int l, int r, ll v) {
    t[id] += v * (r - l + 1); // [改] max/min: t[id] += v;
    lz[id] += v;
}
void pull(int id) { t[id] = t[id * 2] + t[id * 2 + 1]; } // [改] max(..)/min(..)
void push(int id, int l, int r) {
    if (lz[id] == 0) return;
    int m = (l + r) / 2;
    apply_tag(id * 2, l, m, lz[id]);
    apply_tag(id * 2 + 1, m + 1, r, lz[id]);
    lz[id] = 0;
}
void build(int id = 1, int l = 1, int r = n) {
    lz[id] = 0;
    if (l == r) { t[id] = a[l]; return; }
    int m = (l + r) / 2;
    build(id * 2, l, m); build(id * 2 + 1, m + 1, r);
    pull(id);
}
void update(int ql, int qr, ll v, int id = 1, int l = 1, int r = n) { // [ql,qr] 加 v
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) { apply_tag(id, l, r, v); return; }
    push(id, l, r);
    int m = (l + r) / 2;
    update(ql, qr, v, id * 2, l, m); update(ql, qr, v, id * 2 + 1, m + 1, r);
    pull(id);
}
ll query(int ql, int qr, int id = 1, int l = 1, int r = n) {
    if (qr < l || r < ql) return 0; // [改] 單位元: sum 0, max -INF, min INF
    if (ql <= l && r <= qr) return t[id];
    push(id, l, r);
    int m = (l + r) / 2;
    return query(ql, qr, id * 2, l, m) + query(ql, qr, id * 2 + 1, m + 1, r); // [改]
}
// 用法: 讀 n, a[1..n] → build(); update(l,r,v); query(l,r)

/* [變形]
1. 區間「設值」: 另開 bool has[]、ll st[]
   apply_tag: t[id] = v*(r-l+1) (max: v); st[id] = v; has[id] = 1; lz[id] = 0;
   push: 先下傳 has/st，再下傳 lz。同時有設值+加值時，設值會清掉加值
2. 單點設值: update 走到葉子 (l==r) 直接 t[id] = v，免 lazy
3. 需要合併多個資訊 (例: 最大子段和): 開 sum/pre/suf/best 四個陣列,
   pull: sum=L.sum+R.sum, pre=max(L.pre,L.sum+R.pre), suf=max(R.suf,R.sum+L.suf),
         best=max({L.best,R.best,L.suf+R.pre})
4. 找第一個 >= x 的位置 (max 樹): 若 t[左] >= x 往左走，否則往右走
5. 值域線段樹: 下標當「值」(先座標壓縮)，t 存個數 → 可求第 k 小 / 區間內個數
*/
