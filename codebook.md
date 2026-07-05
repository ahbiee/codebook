FJCU – UltraGrammer

Page 1 of 15

Codebook of UltraGrammer

Contents

1 你是否有...
1.1 嘗試...
1.2 檢查...

2 資料結構

. . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . .

2.1 BIT (Fenwick Tree) . . . . . . . . . . . . . . . . . . . . . .
2.2 Segment Tree 線段樹 . . . . . . . . . . . . . . . . . . . . .

3 數論

3.1 快速冪 . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
3.2 模逆元與費馬小定理 . . . . . . . . . . . . . . . . . . . . . .
3.3 組合數 C(n,k) . . . . . . . . . . . . . . . . . . . . . . . . .
3.4 質數檢查 . . . . . . . . . . . . . . . . . . . . . . . . . . . .
3.5 大數乘法 . . . . . . . . . . . . . . . . . . . . . . . . . . . .
3.6 排容原理 . . . . . . . . . . . . . . . . . . . . . . . . . . . .
3.7 擴展歐幾里得 (Extended GCD) . . . . . . . . . . . . . . . .
3.8 尤拉函數 . . . . . . . . . . . . . . . . . . . . . . . . . . . .

4 字串

4.1 KMP 字串匹配 . . . . . . . . . . . . . . . . . . . . . . . . .
4.2 Z-Algorithm 字串匹配 . . . . . . . . . . . . . . . . . . . . .
4.3 Manacher 迴文判斷 . . . . . . . . . . . . . . . . . . . . . .
4.4 Trie 字典樹 . . . . . . . . . . . . . . . . . . . . . . . . . . .
4.5 AC 自動機 . . . . . . . . . . . . . . . . . . . . . . . . . . .

5 圖論

5.1 BFS 與拓樸排序 . . . . . . . . . . . . . . . . . . . . . . . .
5.2 DFS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
5.3 Dijkstra 單源最短路徑 . . . . . . . . . . . . . . . . . . . . .
5.4 SPFA 單源最短路徑 . . . . . . . . . . . . . . . . . . . . . .
5.5 Floyd-Warshall 多源最短路徑 . . . . . . . . . . . . . . . . .
5.6 二分圖判定 (著色問題) . . . . . . . . . . . . . . . . . . . . .
5.7 割點與雙連通分量 . . . . . . . . . . . . . . . . . . . . . . .
5.8 匈牙利演算法 . . . . . . . . . . . . . . . . . . . . . . . . . .
5.9 KM 演算法 . . . . . . . . . . . . . . . . . . . . . . . . . . .
5.10 Dinic 最大流 . . . . . . . . . . . . . . . . . . . . . . . . . .

6 幾何

6.1 點與向量基礎 (Point & Vector) . . . . . . . . . . . . . . . .
6.2 判斷線段、矩形相交 (Segment Intersection) . . . . . . . . .
6.3 點與線段關係 (Point & Line) . . . . . . . . . . . . . . . . .
6.4 任意多邊形面積 . . . . . . . . . . . . . . . . . . . . . . . .
6.5 凸包 Convex Hull
. . . . . . . . . . . . . . . . . . . . . . .

1
1
1

1
1
2

2
2
2
2
2
2
3
3
3

3
3
3
4
4
4

5
5
5
5
6
6
6
6
7
7
8

8
8
8
9
9
9

7 樹論

9
9
7.1 Disjoint Set
7.2 Kruskal 最小生成樹 . . . . . . . . . . . . . . . . . . . . . . 10
7.3 次小生成樹 . . . . . . . . . . . . . . . . . . . . . . . . . . . 10

. . . . . . . . . . . . . . . . . . . . . . . . . .

8 DP

10
8.1 01 Knapsack 背包 . . . . . . . . . . . . . . . . . . . . . . . 10
8.2 LCS 最長共同子序列 (Sequence) . . . . . . . . . . . . . . . 11
8.3 區間 DP 概念 (最長迴文子序列)
. . . . . . . . . . . . . . . 11
8.4 跳格子 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12
8.5 LIS / LDS 最長遞增/遞減子序列 . . . . . . . . . . . . . . . 12
8.6 分錢幣問題 . . . . . . . . . . . . . . . . . . . . . . . . . . . 12
8.7 Kadane’s Algorithm (最大子陣列和) . . . . . . . . . . . . . 13

9 Greedy

13
9.1 一維區間全覆蓋 . . . . . . . . . . . . . . . . . . . . . . . . 13
9.2 間格跳躍 . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13
9.3 最大不重疊區間 . . . . . . . . . . . . . . . . . . . . . . . . 13
9.4 最小覆蓋區間 . . . . . . . . . . . . . . . . . . . . . . . . . . 13
9.5 區間選點問題 . . . . . . . . . . . . . . . . . . . . . . . . . . 13
9.6 最小化最大延遲問題 . . . . . . . . . . . . . . . . . . . . . . 14
9.7 Huffman 樹 . . . . . . . . . . . . . . . . . . . . . . . . . . 14
9.8 任務調度問題 . . . . . . . . . . . . . . . . . . . . . . . . . . 14
9.9 多機調度問題 . . . . . . . . . . . . . . . . . . . . . . . . . . 14
9.10 最大區間重疊數 Sweep Line . . . . . . . . . . . . . . . . . . 14
9.11 三分搜 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14

10 MISC

15
10.1 模板 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
10.2 一些概念 . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
10.3 C++ 函式庫 . . . . . . . . . . . . . . . . . . . . . . . . . . 15

1 你是否有...

1.1 嘗試...

• 再讀一遍題目
• 懷疑你認為「理所當然」的直覺?
• 試著寫下直覺的規律? (有助於觀察)
• 換個方向思考?
• 暴力解?
• 貪心解?
• 對答案二分搜?
• 動態規劃 (DP)?
• 狀態建模, 把問題轉化成圖論?
• 只在奇數 index 反轉狀態?
• 用乘法取代除法? (/2 = ∗2−1，模逆元)

1.2 檢查...

• 確定沒漏看敘述?
• 確認數值範圍? (溢位, 精度位數, 陣列大小...)
• 不同的陣列/字串使用同個 index 導致超出範圍?
• 模板抄錯?
• 多筆資料之間初始化?
• 題目額外的敘述, 暗示?
• 未定義行為? (陣列越界, 未初始化)
• overflow? (int -> long long)
• 非 void function 忘記 return?
• 浮點數誤差? (極小的 eps, 是否需要 long double)
• 隱轉換? (int*int 爆了後才存到 long long)
• signed 與 unsigned int 之間的 compare?

2 資料結構

2.1 BIT (Fenwick Tree)

}

}

return x & (-x);

void init(int sz){

n = sz;
tree.assign(sz+1, 0);

inline int lowbit(int x) { // 取得二進位中最右邊的 1

int n;
vector<long long> tree; // 使用 ll 避免區間總和溢位

用法: 支援單點修改與區間求和。必須是 1-based index。
時間複雜度: O(log n)
1 struct BIT {
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31 };

long long sum = 0;
for (; x > 0; x -= lowbit(x)) {

void add(int x, long long val) { // 在位置 x 加上了 val

long long query(int x) { // 計算 [1, x] 的總和

for (; x <= n; x += lowbit(x)) {

return query(r) - query(l - 1);

}
return sum;

tree[x] += val;

sum += tree[x];

}

}

}

}

long long query(int l, int r) { // 計算 [l, r] 的總和 (前綴和相減)

FJCU – UltraGrammer

Page 2 of 15

2.2 Segment Tree 線段樹

3.2 模逆元與費馬小定理

用法: 給定 n 筆資料查詢與 m 次範圍更新，解決多次範圍更新的問題，

找區間和或最大/小值。必須是 1-based index。
時間複雜度: 建樹 O(N ) 查詢/更新 O(log N )
1 using ll = long long;
2
3 vector<ll> arr, sum, add; //宣告成全域，arr 是原始數據，sum 是範圍累加和，add

是 lazy tag 儲存的值

sum[i] = sum[i*2] + sum[i*2+1];

4
5 void up(int i){ // 往上加回去
6
7 }
8
9 void lazy(int i, ll v, int n){ // 懶標記 (lazy tag)，暫存當前覆蓋範圍

}

if(add[i] != 0){

sum[i] += v*n;
add[i] += v;

lazy(i*2, add[i], ln);
lazy(i*2+1, add[i], rn);
add[i] = 0;

10
11
12 }
13
14 void down(int i, int ln, int rn){ // 往下分發 lazy tag
15
16
17
18
19
20 }
21
22 void build(int l, int r, int i){ // 遞迴式初始化 (init)
23
24
25
26
27
28
29
30
31 }
32
33 void update(int jobl, int jobr, ll jobv, int l, int r, int i){ // 更新區間數

int mid = l + (r-l)/2; // 找中點
build(l, mid, i*2); // 左半邊 build
build(mid+1, r, i*2+1); // 右半邊 build
up(i); // 自己 = 左 + 右 區間和

if(l == r) sum[i] = arr[l]; // 如果區間只剩一個數值，就直接賦值
else{

}
add[i] = 0; // 初始化所有 add[i] = 0

值 (jobl ~ jobr 加上 jobv)，用 l, r, i 判斷範圍

if(jobl <= l && r <= jobr) lazy(i, jobv, r-l+1); // 如果範圍被包的話就直接
lazy
else{

int mid = l + (r-l)/2;
down(i, mid-l+1, r-mid); // 記得往下分發 lazy tag
if(jobl <= mid) update(jobl, jobr, jobv, l, mid, i*2); // 判斷左右區
段是否需要更新
if(jobr > mid) update(jobl, jobr, jobv, mid+1, r, i*2+1);
up(i); // 最後往上加總回去更新 sum

34

35
36
37
38

if(jobl <= l && r <= jobr) return sum[i]; // 如果包範圍就直接 return 回去

int mid = l + (r-l)/2;
down(i, mid-l+1, r-mid); // 記得往下分發 lazy tag
ll total = 0;
if(jobl <= mid) total += query(jobl, jobr, l, mid, i*2);
if(jobr > mid) total += query(jobl, jobr, mid+1, r, i*2+1);
return total; // 因為只是 query，沒有修改，所以不用 up 更新回去

}

39
40
41
42 }
43
44 ll query(int jobl, int jobr, int l, int r, int i){
45
46
47
48
49
50
51
52
53 }
54
55 int main() {
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78 }

for(int i=1; i<=n; ++i) cin >> arr[i];
build(1, n, 1);
int op;
ll x, y, k;
while(m--){

int n, m;
cin >> n >> m;
arr.assign(n+1, 0);
sum.assign(4*(n+1), 0); // 大小必須開到 4 倍 n+1
add.assign(4*(n+1), 0);

cin >> x >> y;
cout << query(x, y, 1, n, 1) << '\n';

cin >> x >> y >> k;
update(x, y, k, 1, n, 1);

cin >> op;
if(op == 1){

}
return 0;

}
else{

}

用法: p 必須是質數，且整數 a 與 p 互質，則 ap−1 ≡ 1 (mod p)。
兩邊同除以 a 可得 ap−2 ≡ a−1 (mod p)。即計算 (x/a) (mod p) 等同於
計算 (x · ap−2) (mod p)。
時間複雜度: O(log p)
1 long long inv(long long a, long long mod) {
return fast_pow(a, mod - 2, mod);
2
3 }
4
5 // 應用範例：計算 (a / b) % mod
6 long long mod_div(long long a, long long b, long long mod) {
7
8 }

return (a % mod) * inv(b, mod) % mod;

3.3 組合數 C(n,k)

用法: N ≤ 2000 用帕斯卡三角形。N ≤ 106 且模數為質數時，用預處理

階乘與模逆元

時間複雜度: O(N 2) 或 O(N )
1 const long long MOD = 1e9 + 7; // 依照題目給的質數修改
2
3 // 一、帕斯卡三角形 (N <= 2000)，全加法無除法，不怕 MOD 非質數，O(N^2)
4 const int MAXN = 2005;
5 long long C[MAXN][MAXN];
6
7 void build_pascal() {
8
9
10

C[i][0] = 1; // 從 n 個取 0 個的方法數永遠是 1
for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i -
1][j]) % MOD;

for (int i = 0; i < MAXN; ++i) {

}

11
12 }
13
14 // 二、階乘與模逆元 (N <= 10^6)，MOD 必須是質數，O(N)
15 long long fact[MAXN], invFact[MAXN];
16
17 void build_fact() { // 建表
18
19
20
21
22 }
23
24 long long nCr(int n, int k) { // 查詢
25
26
27 }

if (k < 0 || k > n) return 0;
return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;

fact[0] = invFact[0] = 1;
for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
invFact[MAXN - 1] = fast_pow(fact[MAXN - 1], MOD - 2); // 使用快速冪
for(int i=MAXN-2;i >= 1; --i)invFact[i]=invFact[i + 1] * (i + 1) % MOD;

3.4 質數檢查

用法: 單次詢問大數用 isPrime；若有大量詢問則建質數表。
時間複雜度: O(
1 bool isPrime(long long n) { // 一、直接查，只問極少次，且數字可能很大 (n<=

N )

√

1e14)

for (long long i = 5; i * i <= n; i += 6) {

if (n % i == 0 || n % (i + 2) == 0) return false;

if (n < 2) return false;
if (n == 2 || n == 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;

}
return true;

2
3
4
5
6
7
8
9
10 }
11
12 // 二、質數表，大量查詢 1 ~ 10^7 內的質數
13 const int MAXN = 1e7 + 10;
14 vector<int> primes;
15 bool is_prime[MAXN];
16
17 void build(int n) {
18
19
20
21
22
23
24
25
26
27
28 }

for (int i = 2; i <= n; ++i) {

if (is_prime[i]) {

}

}

fill(is_prime, is_prime + n + 1, true); // 初始化全設為 true
is_prime[0] = is_prime[1] = false;

primes.push_back(i); // 放到 primes vector 中記錄

for (ll j = (ll)i * i; j <= n; j += i) is_prime[j] = false;

3 數論

3.1 快速冪

long long res = 1;
a %= mod; // 預防初始底數 a 大於等於 mod
while (b > 0) {

用法: 計算 ab (mod m)。
時間複雜度: O(log b)
1 // 計算 (a^b) % mod，值常為 1e9+7 或 998244353
2 long long fast_pow(long long a, long long b, long long mod) {
3
4
5
6
7
8
9
10
11
12 }

// 如果當前次方數是奇數，把當前的 a 乘進答案裡
if (b & 1) res = res * a % mod;
a = a * a % mod; // 底數平方 % mod
b >>= 1;

}
return res;

// 次方數除以 2

3.5 大數乘法

if (b == 0 || (a.size() == 1 && a[0] == 0)) return {0};
vector<int> c;
long long carry = 0; // 要用 ll 才不會溢位
for (size_t i = 0; i < a.size() || carry > 0; i++) {

用法: 未知長度的大數相乘
時間複雜度: O(N × M )
1 // 一、BigInt * Int，算階乘、連續乘上範圍在 int 內的數值，O(N)
2 vector<int> multiply_small(const vector<int>& a, int b) {
3
4
5
6
7
8
9
10
11
12 }
13
14 // 二、BigInt * BigInt，兩個長度未知的超大整數相乘，O(N * M)
15 vector<int> multiply_big(const vector<int>& a, const vector<int>& b) {
16
17

if (i < a.size()) carry += 1LL * a[i] * b;
c.push_back(carry % 10);
carry /= 10;

}
return c;

if (a.empty() || b.empty()) return {0};
if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) return
{0};

FJCU – UltraGrammer

Page 3 of 15

18
19
20
21
22
23
24

vector<int> c(a.size() + b.size(), 0); // 結果的最大可能長度為兩者長度相加

for (size_t i = 0; i < a.size(); i++) {

long long carry = 0;
for (size_t j = 0; j < b.size() || carry > 0; j++) {

long long cur = c[i + j] + 1LL * a[i] * (j < b.size() ? b[j] : 0)
+ carry;
c[i + j] = cur % 10;
carry = cur / 10;

// 移除多餘的前導零 (例如 00 變成 0)
while (c.size() > 1 && c.back() == 0) c.pop_back();

}

}

return c;

25
26
27
28
29
30
31
32
33
34 }
35
36 // 輔助函式：將字串轉換為大數陣列 (反向存入)
37 vector<int> string_to_bigint(const string& s) {
38
39
40
41 }
42
43 // 輔助函式：印出大數 (反向印出)
44 void print_bigint(const vector<int>& a) {
45
46
47 }

for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
cout << "\n";

vector<int> res;
for (int i = s.length() - 1; i >= 0; i--) res.push_back(s[i] - '0');
return res;

3.6 排容原理

for (int i = 0; i < m; ++i) {

// 紀錄這個子集選了幾個質數 (奇/偶數)

int m = primes.size();
long long ans = 0;

long long lcm_val = 1; // 該子集的最小公倍數 (lcm)
int bits = 0;

// 檢查 mask 的第 i 位是否為 1 (代表選了第 i 個質數)
if ((mask >> i) & 1) {

// 利用 Bitmask 枚舉所有可能的子集組合 (1 到 2^m - 1)
// 例如 m=3，mask 從 001 數到 111
for (int mask = 1; mask < (1 << m); ++mask) {

用法: 解決「至少符合一項條件」的計數問題。遵守奇加偶減原則。
時間複雜度: O(2M · M )
1 // 題型：計算 1 ~ N 中，有幾個數字能被 primes 陣列中的「至少一個」質數整除
2 long long inclusion_exclusion(long long n, const vector<long long>& primes) {
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29 }
30
31 /* 變體應用：若題目問「1 ~ N 中與 K 互質的數有幾個？」
32 解法：先把 K 質因數分解，得到質數陣列 primes。
33 然後用 n 減去 inclusion_exclusion(n, primes) 即為答案。 */

bits++;
lcm_val *= primes[i]; // 質數的 LCM 直接相乘即可
if (lcm_val > n) break; // 防溢位與無效計算優化

if (bits % 2 == 1) ans += count; // 奇加
else ans -= count; // 偶減

if (lcm_val > n) continue; // 組合出來的條件比 N 還大，裡面絕對沒有倍數

long long count = n / lcm_val; // 滿足此條件的數字個數

}
return ans;

}

}

3.7 擴展歐幾里得 (Extended GCD)

if (b == 0) {

x = 1; y = 0;
return a;

用法: 求解 ax + by = gcd(a, b)，以及當模數 m 非質數時的萬能模逆元。
時間複雜度: O(log(min(a, b)))
1 /*
2 應用場景:
3 1. 題目要求解 ax + by = gcd(a, b)
4 2. 題目要求你算「模逆元 (Modular Inverse)」，但是模數 p 不是質數。
5 */
6 long long extgcd(long long a, long long b, long long &x, long long &y) {
7
8
9
10
11
12
13
14
15
16 }
17
18 // 萬能模逆元：求 a 在 mod m 之下的逆元 (無論 m 是否為質數皆可)，-1 表示不存在
19 long long inverse(long long a, long long m) {
20
21
22
23
24 }

}
long long x1, y1;
long long d = extgcd(b, a % b, x1, y1);
x = y1;
y = x1 - y1 * (a / b);
return d;

long long x, y;
long long g = extgcd(a, m, x, y);
if (g != 1) return -1; // 不互質，無解
return (x % m + m) % m; // 確保回傳正數

3.8 尤拉函數

用法: 求 1 ∼ N 中與 N 互質的整數個數。
時間複雜度: O(

N )

√

if (n % i == 0) {

1 // 應用場景：題目問你「在 1 ~ N 裡面，有幾個數字跟 N 互質？」。
2 long long phi(long long n) {
long long res = n;
3
for (long long i = 2; i * i <= n; i++) {
4
5
6
7
8
9
10
11
12
13
14 }

}
// 如果 n 本身最後剩下一個大於 sqrt(n) 的質數
if (n > 1) res -= res / n;
return res;

// 發現質因數 i，套用公式 res = res * (1 - 1/i)
while (n % i == 0) n /= i;
res -= res / i;

}

4 字串

4.1 KMP 字串匹配

用法: 尋找 pattern 出現位置。pi 陣列可求最小循環節。回傳 0-based

起始位置，未匹配為 −1。
時間複雜度: O(N + M )
1 // pi 陣列 (Longest Prefix Suffix): pi[i] 代表 pattern[0..i] 的最長相同前後綴

長度

}
return pi;

// 計算可能的最小循環節長度
int period = n - maxPrefixLength;

// 取得整個字串的最長相同前後綴長度
int maxPrefixLength = pi[n - 1];

int n = s.length();
if (n == 0) return 0;
vector<int> pi = build_pi(s);

int m = s.length();
vector<int> pi(m, -1);
for (int i = 1, j = -1; i < m; ++i) {
// 如果不匹配，就利用 pi 陣列往回跳
while (j >= 0 && s[i] != s[j+1]) j = pi[j];
if (s[i] == s[j+1]) j++;
pi[i] = j;

2 vector<int> build_pi(const string& s) {
3
4
5
6
7
8
9
10
11
12 }
13
14 // 可用 pi 陣列尋找一個字串的最小循環節
15 int getMinimumPeriod(const string& s) {
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33 }
34 // 最終，最小循環節長度即為回傳的 period -> s.substr(0, period);
35
36 // 執行字串匹配
37 vector<int> kmp(const string& text, const string& pattern) {
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52 }

// 若無法整除，代表沒有更小的週期，最小循環節為字串本身
return n;

while (j >= 0 && text[i] != pattern[j+1]) j = pi[j];
if (text[i] == pattern[j+1]) j++;

vector<int> pi = build_pi(pattern);
for (int i = 0, j = =1; i < text.length(); ++i) {

// 檢查總長度是否能被 period 整除
if (maxPrefixLength > 0 && n % period == 0) {

vector<int> res;
if (pattern.empty()) return res;

// 紀錄起始 index
// 繼續尋找下一個可能的匹配

if (j == pattern.length() - 1) { // 完全匹配

res.push_back(i - j);
j = pi[j];

}
return res; // 回傳的這個 vector 包含所有完全匹配的 index 位置

return period;

}

}

4.2 Z-Algorithm 字串匹配

用法: z[i] 代表 S 與 S[i . . . N − 1] 的最長共同前綴。必須是 0-based

index。

// 如果 i 在區間內，可以直接利用對稱性 (i - l) 抄答案
if (i <= r) z[i] = min(r - i + 1, z[i - l]);

int n = s.length();
vector<int> z(n, 0);
// l, r 記錄目前「最靠右」的匹配區間 [l, r]
for (int i = 1, l = 0, r = 0; i < n; ++i) {

時間複雜度: O(N )
1 // z[i] 代表 s[0..n-1] 與 s[i..n-1] 的最長共同前綴 (LCP) 長度
2 // 若要找 pattern 在 text 中的位置，可傳入 s = pattern + "$" + text
3 vector<int> z_function(const string& s) {
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23 }
24
25 string pattern = "aba";

// 暴力往後擴展 (因為有前面的加速，這裡實際上只會做很少次)
while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {

// 如果新匹配的區間超過了原有的 r，更新 [l, r] 視窗
if (i + z[i] - 1 > r) {

l = i;
r = i + z[i] - 1;

}
return z;

z[i]++;

}

}

FJCU – UltraGrammer

Page 4 of 15

26 string text = "abacaba";
27
28 string s = pattern + "$" + text;
29
30 vector<int> z = z_function(s);
31
32 for(int i = 0; i < s.size(); i++) {
33
34
35
36
37
38
39
40 }

}
/*
found at 0
found at 4
*/

if(z[i] == pattern.size()) {

cout << "found at " << i - pattern.size() - 1 << '\n';

4.3 Manacher 迴文判斷

}

}

p[i]++;

// 轉換後的字串

Manacher(const string& s) {

c = i;
r = i + p[i];

for (int i = 1; i < n - 1; i++) {

int mirror = 2 * c - i; // i 關於 c 的對稱點

// 如果這個新迴文的右界超過了 r，更新 c 和 r
if (i + p[i] > r) {

// 暴力往外擴展半徑
while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {

// 如果 i 在迴文右界 r 內，可以直接抄對稱點的答案
if (r > i) p[i] = min(r - i, p[mirror]);

vector<int> p; // p[i] 記錄以 i 為中心的最長迴文半徑
string t;

int n = t.length();
p.assign(n, 0);
int c = 0, r = 0; // c: 目前最靠右的迴文中心, r: 該迴文的右界

// 預處理：將 "abc" 變成 "$#a#b#c#^" 來統一奇偶長度
// 頭尾放不同的字元 ($ 和 ^) 可省去邊界判斷
t = "$#";
for (char c : s) { t += c; t += '#'; }
t += '^';

用法: 求最長迴文子字串。預處理字串塞入 # 將所有迴文轉為奇數長度。
時間複雜度: O(N )
1 // 求最長迴文
2 struct Manacher {
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69 };

vector<string> result;
// 遍歷所有可能的迴文中心
for (int i = 1; i < t.length() - 1; i++) {
// p[i] 是以 i 為中心的最大迴文長度
// 每次往內縮 2 (砍掉頭尾字元)，即可得到以此為中心的所有較短迴文
for (int len = p[i]; len > 0; len -= 2) {

// 神奇的公式：(i - len) / 2 可以精準對應到原字串 s 的起點索引
int start_idx = (i - len) / 2;
result.push_back(s.substr(start_idx, len));

// 回傳所有出現的迴文，包含位置不同的重複字串
// 如果要不重複就把 vector 改成 set 進行去重，再 for 輸出就好
vector<string> get_all_palindromes(const string& s) {

int max_len = 0;
for (int len : p) max_len = max(max_len, len);
return max_len;

// 對於中心 i，包含的迴文數量恰好是 ceil(p[i] / 2)
total += (p[i] + 1) / 2;

long long total = 0;
for (int i = 1; i < t.length() - 1; i++) {

// 僅計算所有迴文子字串的「總數量」
long long count_all_palindromes() {

// 回傳原字串中的最長迴文長度
int get_max_len() {

}
return result;

}
return total;

}

}

}

}

}

}

4.4 Trie 字典樹

// 如果是字元 size=26, 如果是二進制 XOR size=2
int tree[MAXN][size] = {};
int passed[MAXN] = {};
int stop[MAXN] = {};
// 以上陣列的都跳過 index 0
int cnt = 1;

用法: 字串前綴統計或最大 XOR 問題。必須是 0-based index。
時間複雜度: O(|S|)
1 struct Trie {
2
3
4
5
6
7
8
9
10
11
12
13
14

for(int j=0; j<size; ++j) tree[i][j] = 0;
passed[i] = 0;
stop[i] = 0;

for(int i=1; i<=cnt; ++i){

void init(){

}

15
16
17
18
19
20
21
22
23

24
25
26
27
28
29
30
31
32
33
34

35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56

57

58
59
60

cnt = 1;

}

void insert(string word){

int curr = 1;
++passed[curr]; // 經過點，++passed
for(int i=0, path; i<word.length(); ++i){

path = word.at(i) - 'a'; // 求出下一個位置的 index
if(tree[curr][path] == 0) tree[curr][path] = ++cnt; // 如果當前位置走
到目標位置不存在，就用 ++cnt 的值
curr = tree[curr][path]; // 繼續往下走
++passed[curr]; // 記得經過就要 ++passed

}
++stop[curr]; // 最後停住的地方要 ++stop

}

int search(string word){

int curr = 1;
for(int i=0, path; i<word.length(); ++i){

path = word.at(i) - 'a';
if(tree[curr][path] == 0) return 0; // 如果從 curr 往 path 的路徑不存
在，代表搜尋的 word 不存在
curr = tree[curr][path]; // 否則繼續往下走

}
return stop[curr]; // 最後回傳在 curr 位置停下 (stop) 的次數

}

int prefixNumber(string word){

int curr = 1;
for(int i=0, path; i<word.length(); ++i){

path = word.at(i) - 'a';
if(tree[curr][path] == 0) return 0;
curr = tree[curr][path];

}
return passed[curr]; // 和 search 方法一模一樣，只是回傳的對象變成 passed

}

void erase(string word){

if(search(word) == 0) return; // 如果找不到字就不管他
int curr = 1;
--passed[curr];
for(int i=0, path; i<word.length(); ++i){

path = word.at(i) - 'a';
if(--passed[tree[curr][path]] == 0){ // 如果 curr 往 path 的路徑上，p
值為 1，代表後面的東西都不需要了

tree[curr][path] = 0; // 將 curr 不再連通 path，直接捨棄後面所有的東
西 (因為都會被減成 p==0)
return;

}
curr = tree[curr][path]; // 否則繼續往下走，注意後面不需要
再--passed[curr]，因為在 if 區塊我們已經操作完了

}
--stop[curr]; // 最後--stop[curr]

61
62
63
64 };

}

4.5 AC 自動機

}

}

void init() {

int new_node() {

int curr = 0;
for (char c : s) {

cnt = 0;
new_node(); // root is 0

// 1. 將所有關鍵字插入 Trie
void insert(const string& s) {

fill(tree[cnt], tree[cnt] + 26, 0);
fail[cnt] = stop[cnt] = 0;
return cnt++;

static const int MAXN = 1e5 + 10;
int tree[MAXN][size]; // size 是字元 26, 二進制 2
int fail[MAXN];
int stop[MAXN]; // 記錄有幾個字串在此結束
int cnt;

用法: 多字串匹配 (Trie + KMP)，必須是 0-based index。
時間複雜度: O(N + M )
1 struct AC_Automaton {
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49

queue<int> q;
// 將 root (0) 的所有實際存在的第一層子節點推入 queue
for (int i = 0; i < 26; ++i) {

// 2. 建立 Fail 指標與字典圖優化 (使用 BFS)
void build() {

int path = c - 'a';
if (!tree[curr][path]) {

}
curr = tree[curr][path];

fail[tree[0][i]] = 0;
q.push(tree[0][i]);

int u = q.front();
q.pop();

for (int i = 0; i < 26; ++i) {

tree[curr][path] = new_node();

}
stop[curr]++;

while (!q.empty()) {

if (tree[u][i]) {

if (tree[0][i]) {

}

}

}

// 若子節點存在，它的 fail 指向父節點 fail 的對應子節點

FJCU – UltraGrammer

Page 5 of 15

50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68

69
70
71
72
73
74
75
76
77
78 };

fail[tree[u][i]] = tree[fail[u]][i];
q.push(tree[u][i]);

} else {

// 優化: 若子節點不存在，直接把這條路連向 fail 的對應節點
// 這樣搜尋時就絕對不會遇到死胡同，也不用往回跳
tree[u][i] = tree[fail[u]][i];

}

}

}

}

// 3. 搜尋文章，回傳所有關鍵字出現的總次數
int query(const string& text) {

int curr = 0;
int res = 0;
for (char c : text) {

curr = tree[curr][c - 'a']; // 感謝字典圖優化，無腦往下走即可

// 順著 fail 指標往上收集沿途所有匹配成功的字串 (例如配對到 "she"，
同時也配對到 "he")
int temp = curr;
while (temp != 0 && stop[temp] != -1) {

res += stop[temp];
stop[temp] = -1; // -1 是優化：已經算過的關鍵字不要重複算
temp = fail[temp];

}

}
return res;

}

5 圖論

需注意:

是否為全連通圖（connected，只有一個 component），對於連通圖要找
region 可以用 Euler’s theorem V-E+R=2
undirected 無自環
directed
weighted 有權重（點或邊）
multigraph 兩點之間有多條直接的路徑
有向圖的 outdegree, indegree，無向圖的 degree

表示圖的方式: Adjacency matrix, adjacency list

5.1 BFS 與拓樸排序

用法: 無權圖最短路徑 / 拓樸排序計算 In-degree 尋找相關順序，可判斷

是否有環。

// 1. 拓樸排序 (Kahn's Algorithm)
// 回傳拓樸排序的結果。若回傳的 vector 大小小於 n，代表圖中有環
vector<int> topo_sort() {

// 步驟一：將所有入度為 0 (沒有前置條件) 的點加入 queue
for (int i = 1; i <= n; ++i) {

}

}

void init(int _n) {

queue<int> q;
vector<int> res;

n = _n;
adj.assign(n + 1, vector<int>());
in_degree.assign(n + 1, 0);

// 有向圖，u 指向 v (u 必須在 v 之前完成)
void add_edge(int u, int v) {
adj[u].push_back(v);
in_degree[v]++; // v 被 u 指到，入度 +1

時間複雜度: O(V + E)
1 struct BFS_Topo {
int n;
2
vector<vector<int>> adj; // adjacency list，避免爆空間
3
vector<int> in_degree; // 紀錄入度，用於拓樸排序
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54

// 2. 基礎 BFS：無權圖的單源最短路徑
vector<int> get_dist(int start) {

vector<int> dist(n + 1, -1);
queue<int> q;

int u = q.front();
q.pop();
res.push_back(u);

// 拔掉 u 連出去的所有邊
for (int v : adj[u]) {

// 步驟二：開始 BFS
while (!q.empty()) {

dist[start] = 0;
q.push(start);

if (in_degree[i] == 0) q.push(i);

while (!q.empty()) {

q.push(v);

}

}

}

}

}
return res; // 若 res.size() < n，說明有環，無法完成拓樸排序

in_degree[v]--; // v 的前置條件少了一個
if (in_degree[v] == 0) { // 如果前置條件都滿足了，就推入 queue

55
56
57
58
59
60
61
62
63
64
65
66 };

int u = q.front();
q.pop();
for (int v : adj[u]) {

if (dist[v] == -1) { // 沒走過
dist[v] = dist[u] + 1;
q.push(v);

}

}

}
return dist;

}

5.2 DFS

}

}

void init(int _n) {

void add_edge(int u, int v) {
adj[u].push_back(v);
adj[v].push_back(u); // 無向圖就兩個都加

n = _n;
adj.assign(n + 1, vector<int>());
vis.assign(n + 1, false);
subtree_size.assign(n + 1, 0);

用法: 用遞迴走訪。
時間複雜度: O(V + E)
1 struct DFS{
int n;
2
vector<vector<int>> adj;
3
vector<bool> vis;
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29 };
30
31 /*
32 補充 1:
33 當題目節點數量 N <= 10，需要找一條 " 最短路徑"，且每個邊的最大 degree 只有 2
34 可以使用 DFS 進行枚舉，從各個節點開始跑，對所有可能的路徑跑 DFS
35 邊跑邊更新最長路徑答案，跑完是 O(N!) -> N=10 -> 小於 400 萬，能跑
36
37 補充 2:
38 如果發現題目要找樹的直徑時，可以使用兩次 dfs 求解 (前提是樹邊權不能是負的)
39 如: 樹上最遠兩點距離? 從一個人開始通知，每秒傳到相鄰節點，最短多久可以全收到? 路

vis[u] = true;
// 如有需要，處理抵達 u 時的邏輯 (Pre/In/Post-order)

for (int v : adj[u]) {
if (!vis[v]) {
dfs(v);

// 基礎 DFS：走訪與找連通塊
void dfs(int u) {

}

}

}

徑唯一最長鏈?

if(next != parent) dfs(cur->next, cur, dist+1);

}

}
for(int &next : adj[cur]){

if(dist > max_dist){
max_dist = dist;
farthest_node = cur;

40 */
41 vector<int> adj[MAXN];
42 int max_dist;
43 int farthest_node;
44
45 void dfs(int cur, int parent, int dist){
46
47
48
49
50
51
52
53 }
54
55 void solve(){
int n, e;
56
cin >> n >> e;
57
for(int i=0; i<e; ++i){ // 讀入圖
58
59
60
61
62
63
64
65
66
67
68
69
70
71 }

int a, b;
cin >> a >> b;
adj[a].push_back(b);
adj[b].push_back(a);

}
max_dist = -1;
dist(1, -1, 0); // 一開始從任意點第一次 DFS

int first_farthest = farthest_node;
max_dist = -1;
dist(first_farthest, -1, 0);
// 最長距離為 max_dist, 點:first_farthest, farthest_node

5.3 Dijkstra 單源最短路徑

用法: 找單個起點的最短路徑，不支援負權邊，支援自環，支援有/無向

圖。

時間複雜度: O((V + E) log V )
1 struct Dijkstra {
2
3
4
5
6
7
8
9
10
11
12

// 初始化：傳入節點數，清空圖
void init(int _n) {

// 定義 pii 為 pair< 距離, 節點 >，預設由小到大排序 (pq 用)
using pii = pair<long long, int>;
const int MAXN = 2e5 + 10;
const long long INF = 1e18; // 使用 1e18 避免相加時 long long 溢位

vector<pair<int, long long>> adj[MAXN]; // adj[u] = {v, weight}
long long dist[MAXN]; // dist[i] 為起點到 i 的距離
int n;

FJCU – UltraGrammer

Page 6 of 15

13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37

38
39
40
41
42
43
44
45
46
47
48
49
50
51
52 };

n = _n;
for (int i = 0; i <= n; ++i) {

adj[i].clear();

}

}

void add_edge(int u, int v, long long w) {

adj[u].push_back({v, w});
// 若為無向圖，須加上 adj[v].push_back({u, w});

}

void solve(int start) {

fill(dist, dist + n + 1, INF); // 將距離陣列初始化為無限大
// pq 存起點到某一點的距離，用距離的 Min-Heap
priority_queue<pii, vector<pii>, greater<pii>> pq;

dist[start] = 0;
pq.push({0, start});

while (!pq.empty()) {

long long d = pq.top().first;
int u = pq.top().second;
pq.pop();

// 懶惰刪除 (Lazy Deletion)：如果取出時發現已經有更好的距離，直接丟
棄
if (d > dist[u]) continue;

for (auto& edge : adj[u]) {
int v = edge.first;
long long w = edge.second;

// 鬆弛 (Relax)
if (dist[u] + w < dist[v]) {

dist[v] = dist[u] + w;
pq.push({dist[v], v});

}

}

}

}

5.4 SPFA 單源最短路徑

用法: 也是找單個起點的最短路徑，但支援負權邊。只在” 可能有負邊”

或” 必須檢查負環” 時才用

時間複雜度: 預期 O(V + E)，最差 O(V E)
1 #include <bits/stdc++.h>
2 using namespace std;
3
4 const int MAXN = 1005;
5 const long long INF = 1e18;
6
7 struct Edge {
8
9

int v;
long long w;

10 };
11
12 vector<Edge> G[MAXN]; // adjacency list 存圖
13 long long dist[MAXN]; // 起點到任意點的距離
14 int n, m; // n 個點, m 個邊
15
16 bool SPFA(int start) { // 回傳 false 代表圖中存在負環；回傳 true 代表最短路徑計

17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49

算成功

bool inq[MAXN]; // inq[i] 記錄點 i 目前是否在 queue 裡面
int cnt[MAXN]; // cnt[i] 記錄點 i 進入 queue 的總次數
queue<int> q;

fill(dist, dist + n + 1, INF);
memset(inq, false ,sizeof(inq));
memset(cnt, 0, sizeof(cnt));

dist[start] = 0; // 從 start 節點開始
q.push(start);
inq[start] = true;
cnt[start] = 1;

while (!q.empty()) {

int u = q.front();
q.pop();
inq[u] = false; // 拿出來後就不在 queue 裡了

for (auto& edge : G[u]) {

int v = edge.v;
long long w = edge.w;

// 鬆弛操作 (relax)
if (dist[u] + w < dist[v]) {

dist[v] = dist[u] + w;

// 如果被鬆弛的點不在 queue 裡面，就把它加進去
if (!inq[v]) {
q.push(v);
inq[v] = true;
cnt[v]++;

if (cnt[v] >= n) return false; // 【關鍵】一個點入隊次數
>= n (點總數)，必定有負環

50
51
52
53
54
55 }

}

}

}

}
return true;

5.5 Floyd-Warshall 多源最短路徑

用法: 求任意兩點之間距離。利用滾動陣列降維，k 必須在最外層迴圈。

注意避開 INF 加上負權邊的陷阱。

時間複雜度: 時間 O(V 3)，空間 O(V 2)
1 #include <bits/stdc++.h>
2 using namespace std;
3
4 const int MAXN = 505;
5 const long long INF = 1e18;
6 long long dist[MAXN][MAXN];
7 int n, m;
8
9 void init() {

for (int i = 1; i <= n; ++i) {

for (int j = 1; j <= n; ++j) {

dist[i][j] = (i == j) ? 0 : INF;

10
11
12
13
14
15 }
16
17 // 注意：讀邊時若為多重邊 (Multigraph, 即 A->B 不只一條 direct path)，需寫成

}

}

dist[u][v] = min(dist[u][v], w);

// 中繼點 k 必須在最外層！
for (int k = 1; k <= n; ++k) {

for (int i = 1; i <= n; ++i) {

for (int j = 1; j <= n; ++j) {

// 必須確認 i->k 和 k->j 都是通的
if (dist[i][k] < INF && dist[k][j] < INF) {

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}

18
19 void floyd() {
20
21
22
23
24
25
26
27
28
29
30
31 }

}

}

}

5.6 二分圖判定 (著色問題)

}

void init(int _n) {

n = _n;
adj.assign(n + 1, vector<int>());
color.assign(n + 1, 0); // 初始化全為未著色

void add_edge(int u, int v) {
adj[u].push_back(v);
adj[v].push_back(u); // 二分圖判斷通常針對無向圖

int n;
vector<vector<int>> adj;
vector<int> color; // 0: 未著色, 1: 顏色 A, -1: 顏色 B

用法: 規定相鄰節點必須塗上不同顏色，如果在著色過程中，發現相鄰節
點已經被塗上相同的顏色，則代表此圖包含奇數環 Odd Cycle，不是二分
圖。已考量到不連通圖的情況
時間複雜度: O(V + E)
1 struct BipartiteCheck {
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33

// 圖可能有多個連通分量 (Components)，必須確保每個節點都被檢查到
for (int i = 1; i <= n; ++i) {

queue<int> q;
q.push(i);
color[i] = 1; // 塗上第一種顏色

if (color[i] == 0) { // 遇到未著色的節點，當作新 Component 的起點

int u = q.front();
q.pop();

bool is_bipartite = true;

for (int v : adj[u]) {

if (color[v] == 0) {

while (!q.empty()) {

bool solve() {

}

// 相鄰節點未著色，塗上相反的顏色 (-color[u]) 並加
入 queue
color[v] = -color[u];
q.push(v);

} else if (color[v] == color[u]) {

// 相鄰節點已著色，且與自己同色 -> 產生奇數環，非二
分圖
is_bipartite = false;
return false; // 提早結束，不需繼續檢查

}

}

}

}

}
return is_bipartite;

34
35
36
37

38
39
40
41
42
43
44
45
46
47 };

}

5.7 割點與雙連通分量

用法: 處理網路穩定性、單點故障分析。透過 DFS 一次遍歷找出所有的
割點以及 v-BCC。由於一個割點可能同時屬於多個 BCC，我們利用 stack
記錄 DFS 走過的點，當發現割點條件成立時，再把點從 stack 彈出形成
BCC。

時間複雜度: O(V + E)
1 /*
2 dfn[u]： DFS 時，節點 u 被拜訪到的「時間戳記」或「順序」。一旦給定就不會再改變。
3
4 low[u]：從節點 u 的子樹出發，在不經過 走到 u 的那條父節點邊 的前提下，透過

back-edge 能到達的所有節點中，最小的 dfn 值。

5 */
6
7 /*
8 割點 (Articulation Point)：

FJCU – UltraGrammer

Page 7 of 15

}

}

18 */
19
20 struct BCC {
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75

9 定義：在無向連通圖中，如果移除某個節點及其所有相連的邊後，圖被切斷成兩個或多個不

相連的部分，該點就是割點。

10 用途：尋找網路、電路或交通系統中的「單點故障」瓶頸。只要這個點壞了，整個系統就會癱

瘓。
11 判斷條件：
12 若 u 是 DFS 的根節點 (Root)，且它有 2 個以上的子樹，則 u 是割點。
13 若 u 不是根節點，且存在至少一個子節點 v 滿足 low[v] >= dfn[u]。這代表 v 及其子孫
「最多只能爬回 u 自己」，無法繞過 u 抵達更上層的祖先。如果把 u 拔掉，v 就會跟上面斷

聯，因此 u 是割點。

14
15 點雙連通分量 (Vertex Biconnected Component)：
16 定義：一個不包含任何割點的「極大連通子圖」。在 v-BCC 中，任意兩點之間至少有兩條點

不重複的路徑。

17 用途：用來縮點。把一個個 v-BCC 視為一個大節點，可以將複雜的圖形轉化為「樹」的結

構，進而利用 LCA 或樹上 DP 來處理複雜的圖上路徑詢問。

int n, timer;
vector<vector<int>> adj;
vector<int> dfn, low;
vector<bool> is_cut;
vector<vector<int>> bcc_nodes; // 儲存每個 BCC 內的點集
stack<int> st;

// 紀錄是否為割點

void init(int _n) {

n = _n;
timer = 0;
adj.assign(n + 1, vector<int>());
dfn.assign(n + 1, 0);
low.assign(n + 1, 0);
is_cut.assign(n + 1, false);
bcc_nodes.clear();
while (!st.empty()) st.pop();

void add_edge(int u, int v) {
adj[u].push_back(v);
adj[v].push_back(u);

void dfs(int u, int p = -1) {

dfn[u] = low[u] = ++timer;
st.push(u);
int children = 0; // 紀錄 DFS 樹上的子節點數量

for (int v : adj[u]) {

int ans = 0;
memset(left, -1, sizeof(left)); // 依照需求假設點編號為 0-based 或 1-based

4 const int MAXN = 30005; // 依題目需求調整右側/左側最大點數
5 int n, m, e;
6 vector<int> G[MAXN];
7 int lef[MAXN];
8 bool T[MAXN];
9

// n: 左側點數, m: 右側點數
// G[u] 存左側點 u 連向右側的哪些點
// lef[v] 記錄右側點 v 配對到的左側點
// T[v] 記錄右側點 v 在單次 DFS 中是否已拜訪

// 假設左側點編號為 1 ~ n (若為 0 ~ n-1 請自行改迴圈範圍)
for (int i = 1; i <= n; ++i) {

}

for (int v : G[u]) {

}
return false;

if (T[v]) continue;
T[v] = true;

lef[v] = u; // 配對成功
return true;

// 若右側點 v 還沒選對象，或其原本對象可以讓出位子
if (lef[v] == -1 || match(lef[v])) {

10 bool match(int u) { // 核心 DFS：幫左側點 u 尋找增廣路徑
11
12
13
14
15
16
17
18
19
20
21
22 }
23
24 int solve() { // 執行最大匹配
25
26
27
28
29
30
31
32
33
34
35
36 }
37
38 int main() {
39
40
41
42
43
44
45
46
47
48
49
50

int u, v; // 讀取每個邊，存到 adjacency list 中
for (int i = 0; i < e; ++i) {

memset(T, false, sizeof(T));
if (match(i)) {
ans++;

cin >> u >> v;
G[u].push_back(v);

for (int i = 0; i <= n; ++i) {

}
return ans;

while (cin >> n >> m){

G[i].clear();

}

}

}

if (v == p) continue; // 不走回頭路 (父節點)

if (dfn[v]) {

// v 已經拜訪過，代表這是一條 Back-edge (回邊)
low[u] = min(low[u], dfn[v]);

} else {

// v 沒拜訪過，代表這是一條 Tree-edge (樹邊)
children++;
dfs(v, u);

// 子節點回來後，用子節點的 low 更新自己的 low
low[u] = min(low[u], low[v]);

// 判斷割點與收集 BCC 的核心條件
if (low[v] >= dfn[u]) {

is_cut[u] = true;
vector<int> comp;

// 從 stack 把屬於這個 BCC 的點全部彈出
while (true) {

int w = st.top();
st.pop();
comp.push_back(w);
if (w == v) break; // 注意：退到 v 就停下

}
// 割點 u 會同時屬於多個 BCC，把它加進去但【不要】從 stack
彈出它
comp.push_back(u);
bcc_nodes.push_back(comp);

// 依照需求做更改，這裡的範例是: 找到的最大匹配數等於邊的數量，即完成最
大匹配
if(solve() == e) cout << "YES\n";
else cout << "NO\n";

51
52
53
54
55 }

}
return 0;

5.9 KM 演算法

用法: 適用於左右節點數皆為 N 的帶權完全二分圖
時間複雜度: O(N 3)
1 /*
2 前提：完美匹配與虛擬節點
3 KM 演算法要求左右兩側的節點數必須相等（形成完全二分圖）
4 如果在題目中左右節點數不同，或者某些點之間沒有連線，我們必須加入「虛擬節點」與「權

重為 0（或極小值）的虛擬邊」來補齊，才能讓 KM 演算法順利運作。

5 */
6
7 struct KM {
int n;
8
vector<vector<long long>> weight; // weight[u][v] 表示左 u 到右 v 的權重
9
// lx, ly 為左右點的「期望值 (頂標)」，
vector<long long> lx, ly, slack;
10
slack 為鬆弛量
vector<int> match_y;
u
vector<int> pre;
溯
vector<bool> vis_y;
const long long INF = 1e18;

// 紀錄右側節點是否在當前交替樹中

// match_y[v] = u 代表右側 v 匹配給左側

// 紀錄右側節點的交替樹路徑，用於 BFS 回

12

11

76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99

}

}

}

// 根節點特判：DFS 起點如果有小於 2 個子樹，則不是割點
if (p == -1 && children < 2) {

is_cut[u] = false;

}

}

void solve() {

for (int i = 1; i <= n; ++i) {

if (!dfn[i]) {
dfs(i);

// 處理極端情況：圖中若存在孤立的單個點，將其視為一個 BCC
if (bcc_nodes.empty() && n == 1) {
bcc_nodes.push_back({1});

}

}

}

}

100 };

5.8 匈牙利演算法

用法: 無權二分圖最大匹配，透過回溯尋找增廣路徑，以達到最大匹配。

分為左 (S)、右 (T) 兩側，以及 left 陣列紀錄右側所選的對象

時間複雜度: O(V · E)
1 #include <bits/stdc++.h>
2 using namespace std;
3

13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47

void init(int _n) {

n = _n;
// 為了方便，採用 1-based index，0 作為虛擬的空節點
weight.assign(n + 1, vector<long long>(n + 1, 0));
lx.assign(n + 1, 0);
ly.assign(n + 1, 0);
match_y.assign(n + 1, 0);

}

void add_edge(int u, int v, long long w) {

weight[u][v] = max(weight[u][v], w); // 若有多重邊，保留權重最大的

}

// BFS 尋找增廣路徑並更新頂標
void bfs(int root) {

slack.assign(n + 1, INF);
vis_y.assign(n + 1, false);
pre.assign(n + 1, 0);

int y = 0;
match_y[0] = root; // 將起始點放在虛擬節點 match_y[0]

while (true) {

int x = match_y[y]; // 當前考慮的左側節點
long long delta = INF;
int next_y = 0;
vis_y[y] = true;

// 遍歷所有右側節點，計算 slack 量
for (int i = 1; i <= n; ++i) {

if (!vis_y[i]) {

long long diff = lx[x] + ly[i] - weight[x][i];

FJCU – UltraGrammer

Page 8 of 15

48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103 };

if (diff < slack[i]) {

slack[i] = diff;
pre[i] = y; // 紀錄從哪個右側節點轉移過來

}
if (slack[i] < delta) {

delta = slack[i];
next_y = i;

}

}

}

// 更新交替樹中所有點的頂標 (期望值)
for (int i = 0; i <= n; ++i) {

if (vis_y[i]) {

lx[match_y[i]] -= delta;
ly[i] += delta;

} else {

slack[i] -= delta;

}

}

y = next_y; // 走到下一個右側節點
if (match_y[y] == 0) break; // 找到未匹配的右側節點，增廣路徑結束

}

// 回溯並更新匹配狀態
while (y != 0) {

match_y[y] = match_y[pre[y]];
y = pre[y];

}

}

long long solve() {

// 初始化左側頂標為連接邊的最大權重
for (int i = 1; i <= n; ++i) {

lx[i] = -INF;
for (int j = 1; j <= n; ++j) {

lx[i] = max(lx[i], weight[i][j]);

}

}

// 對每一個左側節點進行匹配
for (int i = 1; i <= n; ++i) {

bfs(i);

}

// 計算最大權重總和
long long max_weight = 0;
for (int i = 1; i <= n; ++i) {
if (match_y[i] != 0) {

max_weight += weight[match_y[i]][i];

}

}
return max_weight;

}

5.10 Dinic 最大流

√

用法: 建圖時需加入反向邊做為退流機制。多筆測資要記得清空 adj。
時間複雜度: O(V 2E)，二分圖匹配 O(E
1 #include <vector>
2 #include <queue>
3 #include <algorithm>
4 using namespace std;
5
6 const int MAXV = 1005; // 依據題目點數調整
7 const long long INF = 1e18;
8
9 // 儲存邊的結構

V )

int to;
long long cap, flow;
int rev; // 紀錄這條邊的「反向邊」在對方 adj 陣列裡的位置 (index)

10 struct Edge {
11
12
13
14 };
15
16 vector<Edge> adj[MAXV];
17 int level[MAXV]; // BFS 分層圖，紀錄起點到該點的距離
18 int ptr[MAXV];
19 int n, s, t;
20
21 // 加入一條有向邊 (若是無向邊，請再呼叫一次反方向，或直接把反向邊的 cap 也設為

// 【當前弧優化】紀錄 DFS 目前探索到哪條邊，避免走廢邊
// 總點數, 源點 (Source), 匯點 (Sink)

w)

adj[from].push_back({to, w, 0, (int)adj[to].size()});
adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});

while (!q.empty()) {

fill(level, level + n + 1, -1);
level[s] = 0;
queue<int> q;
q.push(s);

22 void add_edge(int from, int to, long long w) {
23
24
25 }
26
27 // 1. BFS 建立分層圖
28 bool bfs() {
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46 }
47
48 // 2. DFS 尋找增廣路徑並推播流量

int v = q.front();
q.pop();
for (auto& edge : adj[v]) {

level[edge.to] = level[v] + 1;
q.push(edge.to);

}

}

}
return level[t] != -1; // 回傳是否還能走到匯點 T

// 如果這條邊還有剩餘容量，且終點還沒被分層
if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {

// 利用 ptr[v] 紀錄上次走到哪一條邊，這是 Dinic 不會 TLE 的關鍵！
// 注意 cid 必須宣告為 reference (&) 才能真正更新 ptr 陣列
for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {

// 條件：只能往下一層走，且邊要有剩餘容量
if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;

long long push = dfs(tr, min(pushed, edge.cap - edge.flow));
if (push == 0) continue;

auto& edge = adj[v][cid];
int tr = edge.to;

if (pushed == 0) return 0;
if (v == t) return pushed;

// 更新正向與反向邊的流量
edge.flow += push;
adj[tr][edge.rev].flow -= push;
return push;

49 long long dfs(int v, long long pushed) {
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71 }
72
73 // 主函式：計算最大流
74 long long dinic(int _n, int _s, int _t) {
75
76
77
78
79
80
81
82
83
84
85
86
87
88 }
89
90 // 若有多筆測資，請記得在 main 裡面先跑：
91 // for(int i = 0; i <= n; ++i) adj[i].clear();

// 只要還能走到匯點，就持續建分層圖
while (bfs()) {

n = _n; s = _s; t = _t;
long long flow = 0;

}
return flow;

}
return 0;

flow += pushed;

}

// 在同一層圖中，盡可能把所有增廣路徑榨乾
while (long long pushed = dfs(s, INF)) {

fill(ptr, ptr + n + 1, 0); // 每次重新分層後，DFS 指標要歸零

6 幾何

6.1 點與向量基礎 (Point & Vector)

用法: 幾何基礎，定義 struct 與 operator。包含浮點數誤差處理 sign，

以及核心工具 dot (內積) 與 cross (外積)。

if (fabs(x) < EPS) return 0;
return x < 0 ? -1 : 1;

// 判斷兩點是否相等 (利用 sign 來避免浮點數誤差)
bool operator==(const Point& p) const {

double x, y; //通用 double
Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

// 向量加減法與常數乘除
Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
Point operator*(double d) const { return Point(x * d, y * d); }
Point operator/(double d) const { return Point(x / d, y / d); }

時間複雜度: O(1)
1 #include <bits/stdc++.h>
2 using namespace std;
3
4 const double EPS = 1e-9; // 用來處理浮點數誤差的極小值
5
6 // 符號判斷函數 (極度重要！)
7 // 判斷一個浮點數是 正數 (1)、負數 (-1) 還是 0(0)
8 int sign(double x) {
9
10
11 }
12
13 struct Point {
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32 };
33
34 using Vector = Point; // 在幾何中，向量和點的表示法一樣，給它一個別名增加可讀性
35
36 // 1. 內積 (Dot Product)，計算方式：x1*x2 + y1*y2
37 // 實戰意義：用來判斷兩向量夾角。大於 0 為銳角，小於 0 為鈍角，等於 0 為垂直。
38 double dot(Vector a, Vector b) {
39
40 }
41
42 // 2. 外積 (Cross Product)，計算方式：x1*y2 - x2*y1
43 // 實戰意義：用來判斷方向與面積。
44 // 若 cross(a, b) > 0，代表 b 在 a 的逆時針方向 (偏左)
45 // 若 cross(a, b) < 0，代表 b 在 a 的順時針方向 (偏右)
46 // 若 cross(a, b) == 0，代表 a 和 b 平行或共線
47 double cross(Vector a, Vector b) {
48
49 }

bool operator<(const Point &p) const{
if(x != p.x) return x < p.x;
return y < p.y;

return sign(x - p.x) == 0 && sign(y - p.y) == 0;

return a.x * b.y - a.y * b.x;

return a.x * b.x + a.y * b.y;

}

}

6.2 判斷線段、矩形相交 (Segment Intersection)

用法: 利用外積進行跨立實驗。避開斜率除以零的問題，可處理端點相切

與共線重疊。

時間複雜度: O(1)

FJCU – UltraGrammer

Page 9 of 15

p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);

return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&

// 1. 計算四個外積值 (跨立實驗)
// 意義：判斷 C 點和 D 點分別在直線 AB 的哪一側
double c1 = cross(b - a, c - a);
double c2 = cross(b - a, d - a);

1 #include <algorithm>
2 using namespace std;
3
4 // 依賴上一節的 Point 結構與 sign, cross 函數
5
6 // 輔助函數：判斷點 P 是否在線段 AB 的「邊界框 (Bounding Box)」內
7 // 實戰意義：當三點共線時，單靠外積無法確認 P 是否在線段上 (可能在延長線上)
8 bool on_segment(Point p, Point a, Point b) {
9
10
11 }
12
13 // 核心函數：判斷線段 AB 與線段 CD 是否相交
14 bool segment_intersect(Point a, Point b, Point c, Point d) {
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40 }

// 3. 特殊情況處理 (端點相交 或 共線重疊)
// 如果外積為 0，代表該點在另一條直線上。
// 接著必須用 on_segment 確保它真的落在「線段區間」內，而不是在延長線上。
if (sign(c1) == 0 && on_segment(c, a, b)) return true;
if (sign(c2) == 0 && on_segment(d, a, b)) return true;
if (sign(c3) == 0 && on_segment(a, c, d)) return true;
if (sign(c4) == 0 && on_segment(b, c, d)) return true;

// 2. 規範相交 (Strictly Intersect)
// 如果 C, D 在 AB 兩側 (外積正負號相反，相乘 < 0)
// 且 A, B 在 CD 兩側，則保證兩線段相交
if (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) {

// 意義：判斷 A 點和 B 點分別在直線 CD 的哪一側
double c3 = cross(d - c, a - c);
double c4 = cross(d - c, b - c);

return false; // 以上皆非，則不相交

return true;

}

6.3 點與線段關係 (Point & Line)

用法: 判斷 1. 點是否在線段上 2. 求點到直線/線段最短距離。利用內外

積避免解方程式與浮點數除以零。

return sqrt(dot(a, a));

return sign(cross(p - a, b - a)) == 0 && sign(dot(a - p, b - p)) <= 0;

時間複雜度: O(1)
1 #include <cmath>
2 using namespace std;
3
4 // 依賴前面的 Point, Vector, sign, cross, dot
5
6 // 輔助函數：求向量長度
7 // 原理：向量自己跟自己做內積，等於長度的平方
8 double length(Vector a) {
9
10 }
11
12 // 1. 判斷點 P 是否在線段 AB 上
13 // 原理：
14 // (1) cross(p-a, b-a) == 0 代表三點共線
15 // (2) dot(a-p, b-p) <= 0 代表 PA 向量與 PB 向量方向相反 (即 P 夾在 A, B 中間)
16 bool on_segment(Point p, Point a, Point b) {
17
18 }
19
20 // 2. 點 P 到「直線」AB 的距離
21 // 原理：平行四邊形面積 = 底 * 高 => 高 = 面積 / 底
22 double dist_to_line(Point p, Point a, Point b) {
23
24
25 }
26
27 // 3. 點 P 到「線段」AB 的最短距離 (賽場極易錯考點)
28 // 原理：用內積判斷 P 點的「投影」是否掉出線段外
29 double dist_to_segment(Point p, Point a, Point b) {
30
31
32
33
34
35
36
37
38
39
40 }

// 如果都不是鈍角，代表 P 的投影乖乖落在線段 AB 上，距離就是點到直線距離
return dist_to_line(p, a, b);

// 鈍角測試 2：角 PBA 是鈍角，代表 P 在 B 的外側，離 B 最近
if (sign(dot(a - b, p - b)) < 0) return length(p - b);

// 鈍角測試 1：角 PAB 是鈍角，代表 P 在 A 的外側，離 A 最近
if (sign(dot(b - a, p - a)) < 0) return length(p - a);

// 面積剛好是外積的絕對值，底邊長是 AB 的長度
return fabs(cross(b - a, p - a)) / length(b - a);

if (a == b) return length(p - a); // A, B 根本是同一個點

6.4 任意多邊形面積

用法: 利用外積求多邊形面積 (鞋帶公式)。頂點必須依順時針或逆時針順

序給定。支援凹凸多邊形。

時間複雜度: O(N )
1 #include <cmath>
2 using namespace std;
3
4 // 依賴前面的 Point 結構與 cross 函數
5
6 const int MAXV = 1005;
7 Point poly[MAXV]; // 儲存多邊形的頂點 (必須依照順時針或逆時針順序排列)
8 int n;
9

// 頂點數量

10 // 求任意多邊形面積 (Shoelace Formula)
11 double polygon_area() {
12
13
14
15

double area = 0;
for (int i = 0; i < n; ++i) {

// 讓最後一個點與第 0 個點連線，形成封閉圖形
int next = (i + 1) % n;

area += cross(poly[i], poly[next]);

}
// 外積和有可能是負的 (取決於順逆時針)，所以取絕對值並除以 2
return fabs(area) / 2.0;

16
17
18
19
20 }
21
22 /*
23 補充: 假設兩個矩形的左下角與右上角座標分別為
24 矩形 A：左下 (x1, y1)，右上 (x2, y2)
25 矩形 B：左下 (x3, y3)，右上 (x4, y4)
26
27 把矩形投影到 X 軸上，就變成了兩個線段 [x1, x2] 與 [x3, x4]
28 它們重疊的長度，等於「兩個右邊界的較小值」減去「兩個左邊界的較大值」
29 如果算出來是負數，代表它們根本沒碰到，直接跟 0 取最大值即可
30
31 因此計算矩形交集面積即為
32 int W = max(0, min(x2, x4) - max(x1, x3));
33 int H = max(0, min(y2, y4) - max(y1, y3));
34 int intersect_area = W * H;
35 */

6.5 凸包 Convex Hull

用法: 求包圍所有點的最小凸多邊形。先排 X 再排 Y 。由左至右建下半

部，由右至左建上半部。利用外積判斷並踢除右轉點。

時間複雜度: O(N log N )
1 #include <algorithm>
2 using namespace std;
3
4 // 依賴前面的 Point 結構與 cross 函數
5
6 const int MAXN = 100005;
7 Point pts[MAXN]; // 存放所有輸入的點
8 Point hull[MAXN]; // 存放最終構成凸包的點
9 int n;

// 輸入點的數量

// 點太少直接就是凸包
if (n <= 2) {

}

10
11 // 回傳凸包上的頂點數量
12 int convex_hull() {
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28

for (int i = 0; i < n; ++i) hull[i] = pts[i];
return n;

// 1. 將所有點由左至右、下至上排序
sort(pts, pts + n);

int m = 0; // m 代表目前凸包 (hull) 裡面有幾個點

// 2. 蓋下半部凸包 (Lower Hull) - 從左走到右
for (int i = 0; i < n; ++i) {

// 【核心邏輯】
// cross <= 0 代表「往右轉」或是「直走」。
// 凸包的邊緣必須一直「往左轉」，如果發現往右轉（凹進去了），就把最後一個點
踢掉！
// (若想保留共線的點，把 <= 改成 < 即可)
while (m >= 2 && cross(hull[m - 1] - hull[m - 2], pts[i] - hull[m -
2]) <= 0) {

m--; // 踢掉最後一個點

}
hull[m++] = pts[i]; // 把新點加進來

}

// 3. 蓋上半部凸包 (Upper Hull) - 從右走回左
// 注意：下半部已經蓋了 m 個點，為了不踢掉下半部的點，我們設定底線為 t
int t = m + 1;
for (int i = n - 2; i >= 0; --i) {

// 邏輯跟上面一模一樣，只是倒著走
while (m >= t && cross(hull[m - 1] - hull[m - 2], pts[i] - hull[m -
2]) <= 0) {
m--;

}
hull[m++] = pts[i];

}

// 4. 起點 (最左下的點) 會在頭尾被重複加入一次，所以總數量要減 1
return m - 1;
// 如果需要知道所有選擇的點，就是 hull[0]~hull[m-1]
// 然後有了這些點又可以用面積公式直接得到整個的面積

29
30

31
32
33
34
35
36
37
38
39
40
41

42
43
44
45
46
47
48
49
50
51 }

7 樹論

7.1 Disjoint Set

}

void init(n){

vector<int> f, sz; // 避免使用 size 撞名

f.resize(n);
sz.assign(n, 1); // 將每個獨立集合的大小初始化為 1
for (int i = 0; i < n; ++i) f[i] = i;

用法: 解決集合、快速合併的問題。優化必須路徑壓縮，可選小掛大
時間複雜度: O(1)
1 struct DSU {
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19

bool isSameSet(int a, int b) {
return find(a) == find(b);

return f[x] == x ? x : ( f[x] = find(f[x]) );

int find(int x) { // 路徑壓縮

// 回傳 bool 有助於在 Kruskal 演算法中判斷是否成功加上一條邊，否則 void 即可
bool unite(int a, int b) {

}

}

FJCU – UltraGrammer

Page 10 of 15

int fa = find(a), fb = find(b);
if (fa == fb) return false;

20
21
22
23
24
25
26
27
28
29 };
30
31 // 概念: successor DSU，這個 disjoint set 將會是用可以來記錄 " 下一個位置" 的

// 小掛大優化：永遠讓 fa 是比較大的集合
if (sz[fa] < sz[fb]) swap(fa, fb);
sz[fa] += sz[fb];
f[fb] = fa;
return true;

}

set (f[i] 指向 find(i+1))

7.2 Kruskal 最小生成樹

用法: 需搭配並查集使用。將所有邊排序後，利用併查集檢查是否形成

環。

時間複雜度: O(E log E)
1 // 讓 Edge 支援比較大小，排序時會自動依據權重 w 由小到大排
2 struct Edge {
int u, v;
3
long long w;
4
bool operator<(const Edge& o) const {
5
6
7
8 };
9

return w < o.w;

}

10 struct Kruskal {
int n;
11
vector<Edge> edges;
12
vector<vector<pair<int, long long>>> tree_adj; // 用來存 MST 的樹狀圖，解
13
DFS MST 用

14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53

54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71 };

void init(int _n) {

n = _n;
edges.clear();
tree_adj.assign(n + 1, vector<pair<int, long long>>());

}

void add_edge(int u, int v, long long w) {

edges.push_back({u, v, w});

}

// 回傳最小生成樹的總權重。若圖不連通則回傳 -1
long long solve() {

sort(edges.begin(), edges.end());
// 如果需要找 MaxST，請 sort(edges.rbegin(), edges.rend())， r!!

DSU dsu;
dsu.init(n + 1);

long long total_weight = 0;
int edge_cnt = 0; // 連接邊個數

for (auto& e : edges) {

// unite 若回傳 true，代表 u 和 v 原本不相連，合併成功 (無環)
if (dsu.unite(e.u, e.v)) {

total_weight += e.w;
edge_cnt++;

// 成為 MST 的一部分，所以加入樹狀圖中
tree_adj[e.u].push_back({e.v, e.w});
tree_adj[e.v].push_back({e.u, e.w});

if (edge_cnt == n - 1) break; // V 個點只要 V-1 條邊即完全連通

}

}

return (edge_cnt == n - 1) ? total_weight : -1;

}

// u: 當前點，target: 目標點，p: 父節點，cur_max: 目前最大邊權，呼叫:
dfs_mst(st, ed, 0, 0)
long long dfs_mst(int u, int target, int p, long long cur_max) {

if (u == target) return cur_max; // 找到終點，回傳整條路的瓶頸值

for (auto& edge : tree_adj[u]) {

int v = edge.first;
long long w = edge.second;

if (v != p) { // 不走回頭路，完美省去 vis 陣列

// 帶著「目前遇過的最大邊權」繼續往下深搜
long long res = dfs_mst(v, target, u, max(cur_max, w));

// 如果 res 不是 -1，代表在 v 的這條分支深處成功找到了 target
if (res != -1) return res;

}

}
return -1; // 這條死胡同找不到終點

}

7.3 次小生成樹

用法: 基於 Kruskal。會先求出最小生成樹，再暴力枚舉拔除 MST 上的

每一條邊，找剩下的最小生成樹，取最小值即為次小生成樹。

時間複雜度: O(V × E)
1 #include <vector>
2 #include <algorithm>
3 using namespace std;
4
5 const long long INF = 1e18;
6
7 // 1. 定義邊與 DSU
8 struct Edge {
int u, v;
9

sort(edges.begin(), edges.end()); // 權重由小到大排序

DSU dsu;
dsu.init(n);
long long mst_weight = 0;
int edge_cnt = 0;
vector<int> mst_edges; // 紀錄第一次 MST 用到的「邊的 index」

}

}

return w < rhs.w;

if (dsu.unite(edges[i].u, edges[i].v)) {

long long w;
bool operator<(const Edge& rhs) const {

mst_weight += edges[i].w;
mst_edges.push_back(i);
edge_cnt++;

// Step 1: 求標準 MST 並記錄使用的邊
for (int i = 0; i < edges.size(); ++i) {

10
11
12
13
14 };
15
16 // struct DSU {}; 跟上面的一樣
17
18 int n, m; // 點數, 邊數
19 vector<Edge> edges;
20
21 // 2. 尋找次小生成樹
22 // 回傳值：pair< 最小生成樹權重, 次小生成樹權重 >
23 // 若圖不連通或不存在次小生成樹，對應的權重會回傳 -1
24 pair<long long, long long> second_mst() {
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70 }

dsu.init(n); // 每次都要重置並查集
long long cur_weight = 0;
int cur_cnt = 0;

// 如果連第一次 MST 都構建不出來 (圖不連通)
if (edge_cnt != n - 1) return {-1, -1};

cur_weight += edges[i].w;
cur_cnt++;

for (int i = 0; i < edges.size(); ++i) {

long long sec_mst_weight = INF;

}

}

}

}

}

// Step 2: 依序拔除 MST 上的每一條邊，嘗試構造新的生成樹
for (int removed_idx : mst_edges) {

if (i == removed_idx) continue; // 【關鍵】禁用這條邊

if (dsu.unite(edges[i].u, edges[i].v)) {

// 如果拔掉該邊後，剩下的邊還是能連通所有點 (形成生成樹)
if (cur_cnt == n - 1) {

sec_mst_weight = min(sec_mst_weight, cur_weight);

if (sec_mst_weight == INF) sec_mst_weight = -1; // 不存在次小生成樹
return {mst_weight, sec_mst_weight};

8 DP

DP 通用解題四步驟:

1. 定義陣列意義：明確寫出 dp[i] (或 dp[i][j]) 代表什麼。
2. 找出遞迴關係式：推導出當前狀態如何由過去狀態轉移而來。
3. 設定邊界條件：初始化起點或基礎 dp 值（如：dp[0] = 0 ）。
4. 確 認 遍 歷 順 序： 決 定 迴 圈 是 從 前 到 後 （Bottom-Up） 還 是 後 到 前
(Top-Down) 計算。(通常是 Bottom-Up，思考” 我是如何到這一步的” 去
推)

8.1 01 Knapsack 背包

用法: 解決物品不可拆分的情況，若可拆分用 Greedy 拿比例最佳的部分
時間複雜度: O(N )
1 /*
2 題目敘述：給定 N 個物品的重量 Wi 和價值 Vi，和個容量為 W 的背包。選取若干件物品

放入背包，在不超過背包容量的情況下，背包內物品價值總和最大為何?

3
4 定義 dp[i][j] 表示: 在考慮前 i 個物品，且考慮重量 <=j 的情況下，所能得到的最大價

值是多少 (假設 index 0 不放東西)

5 初始: 對於所有的 i=0, dp[i][j] = 0 (不考慮任何物品的情況下，最大價值是 0)，也可

以直接預設所有位置都是 0

6 轉移函式: dp[i][j] = max(dp[i-1][j], dp[i-1][j-Wi] + Vi);
7 -> 兩種情況:
8 1. 不放第 i 件物品，最大價值與前一項相同
9 2. 放入第 i 件物品，最大價值為 扣除目標重量後的最大價值 加上當前物品的價值之總和

10
11 適用情況: 需要 backtrack
12 -> 從 dp[MAXN][MAXW] 開始檢查:
13 如果 dp[i][j] == dp[i-1][j] 表示沒有拿第 i 個，接著讓 i = i-1 繼續跑
14 否則我們有拿第 i 個，接著跳到 dp[i-1][j-w[i]]
15 重複直到 i=0 (沒東西了) 或 j=0 (重量用完了)
16 */
17
18 int dp[MAXN + 1][MAXW + 1];
19 memset(dp, 0, sizeof(dp)); // 初始化為 0
20 for (int i = 1; i <= MAXN; ++i) // 從考慮第一個物品到第 N 個物品
21 {
22

for (int j = 0; j < w[i]; ++j) // 如果當前考慮重量小於 Wi，代表沒辦法裝下第
i 個物品，直接繼承前一項

23

dp[i][j] = dp[i - 1][j];

FJCU – UltraGrammer

Page 11 of 15

dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

for (int j = w[i]; j <= MAXW; ++j) // 否則就用 transition function 找 max

24
25
26 }
27 cout << dp[MAXN][MAXW] << '\n'; // 最終答案在最右下那格
28
29 /*
30 ===== 滾動陣列優化 =====
31 概念: 在計算考慮第 i 個物品時，我們只會用到第 i-1 行的資料，可以看成陣列中的上一

筆舊資料

32 透過想法上的極致壓縮，覆寫無用資料空間，可將空間複雜度降至 O(W)
33 限制是 j 必須由大往小跑，如果由小至大會重複使用到陣列資料導致答案錯誤
34 */
35
36 int dp[MAXW + 1];
37 memset(dp, 0, sizeof(dp));
38 for(int i = 1; i <= MAXN; ++i) // 注意一樣是要跑 MAXN 次，我們只是把陣列大小減

少了

39 {
40

41

for(int j = MAXW; j >= w[i]; --j) // dp[j] 在等號左邊表示當前，等號右邊表
示上一筆資料

dp[j] = max(dp[j], dp[j-w[i]] + v[i]); // 不需要考慮 j < w[i] 的情況，
因為它會繼承上一個結果

42 }
43 cout << dp[MAXW] << '\n';
44
45 /*
46 === 恰好裝滿問題 / 子集合和 ===
47 題目敘述：給定 N 樣物品，每件物品的重量分別為 Wi，問可不可以將物品分成等重的兩堆。

48
49 題解：首先判斷總重是否為二的倍數，如果不是就直接輸出 NO 然後下一個 case
50 如果可以的話就使用一維 DP 解，總重/2 當作 MAXW (dp 大小)，每件行李的重量是價值，

看是否存在 dp[MAXW] = MAXW (在裝入一半行李的情況下，總重剛好也是一半)

51
52 === 多背包共用商品 ===
53 題目：N 個物品 (同一項商品可被多個人同時取用)，G 個人各自有容量為 Wi 的背包，求所

有人能拿的最大價值總和。

54
55 題解：每個人挑選互相獨立，不需重複計算。(查表)
56 1. 以所有商品跑一次標準一維 0/1 背包，每次讀入 Wi 與 Vi 時就 run 一次，建立 dp

陣列。

57 2. 結束後跑一遍 dp[i] = max(dp[i], dp[i-1]) 確保單調性。
58 3. 讀入每個人的容量 W，總答案 ans += dp[W]。
59 */

8.2 LCS 最長共同子序列 (Sequence)

用法: 二維 DP 與 Backtrack 找原始子序列
時間複雜度: O(N M )
1 // LCS (線性 DP)：dp[i][j] 代表的是 s1 的前 i 個字元，與 s2 的前 j 個字元。這是

一個從索引 0 開始的前綴

// dp[i][j] 代表 s1 的前 i 個字元與 s2 的前 j 個字元的 LCS 長度
// 宣告 n+1 與 m+1 是為了讓 index 0 作為「空字串」的邊界條件 (全為 0)
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

// 若字元不同，取上方或左方的最大值
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

}

}

}

} else {

if (s1[i - 1] == s2[j - 1]) {

for (int j = 1; j <= m; ++j) {

int n = s1.length(), m = s2.length();

// 1. 狀態轉移 (填表)
for (int i = 1; i <= n; ++i) {

// 若字元相同，繼承左上角的答案 + 1
dp[i][j] = dp[i - 1][j - 1] + 1;

// 求解 LCS 並回傳最長共同子序列的字串
// 若只需長度，直接回傳 dp[n][m] 即可
string solve(const string& s1, const string& s2) {

// 2. 回溯 (Backtracking) 找回原本的字串
string res = "";
int i = n, j = m;
while (i > 0 && j > 0) {

2
3 struct LCS {
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47 };
48
49 /*
50 變化: 給定兩個字串，可以任意進行插入、刪除、取代三種操作
51 請問最少需要幾次操作可以使得兩字串完全一模一樣，並輸出過程?
52 與 LCS 大致相同，(相同、選左、選上)，但是多了一個取代的操作
53 所以轉移方程式會變成
54 dp[i][j] = min{
55 1. if(x[i] == y[j]) dp[i-1][j-1] 字元相同的情況
56 2. if(x[i] != y[j]) dp[i-1][j-1]+1 選擇" 取代"
57 3. dp[i-1][j]+1 選擇" 左邊"

// 因為是從尾巴推回去的，最後要把字串反轉
reverse(res.begin(), res.end());
return res;

// 如果字元相同，這一定是 LCS 的一部分
res += s1[i - 1];
i--; j--; // 往左上角回退

} else if (dp[i - 1][j] > dp[i][j - 1]) {

// 否則往左方走
j--;

if (s1[i - 1] == s2[j - 1]) {

}

}

}

// 如果不同，往數值比較大的方向走 (此處為上方)
i--;
} else {

58 4. dp[i][j-1]+1 選擇" 右邊"
59 }
60
61 補充:
62 Longest Palindrome Sequence 最長迴文子序列
63 給定一個字串，問你該字串的最長迴文子序列 " 長度" 為多少
64 做法就是對 s1 與 s2=reverse(s1) 做一次 LCS，即可得到 " 最長長度"
65
66 變化: 求最少插入/刪除次數以形成迴文
67 如果只求長度 -> strlen - LPS(s)
68 否則就要使用到區間 DP 的內容了
69 */

8.3 區間 DP 概念 (最長迴文子序列)

用法: 區間 DP 是由字串的內部向外擴張，利用已經算好的較短子字串，

來推導出較長子字串的答案。

時間複雜度: O(N 2)
1 // LPS (區間 DP)：dp[i][j] 代表的是同一個字串 s 裡面，從索引 i 到 j 的這段閉區

間（也就是子字串 s[i...j]）

// 求解最長迴文子序列 (LPS) 長度
int solveLPS(const string& s) {

int n = s.length();
if (n == 0) return 0;

2
3 struct IntervalDP {
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22

// dp[i][j] 代表字串 s 區間 [i, j] 內的最長迴文子序列長度
vector<vector<int>> dp(n, vector<int>(n, 0));

// 1. 狀態轉移 (填表)
// 注意 i 是從字串的「尾巴」往「頭」掃
for (int i = n - 1; i >= 0; --i) {

// Base case: 單一字元本身就是長度為 1 的迴文
dp[i][i] = 1;

// j 從 i 的下一個位置開始向右擴展
for (int j = i + 1; j < n; ++j) {

if (s[i] == s[j]) {

// 若頭尾字元相同，長度為內部區間的迴文長度 + 2
// 因為 i 是倒著掃，j 是正著掃，所以 dp[i+1][j-1] 絕對已經
算過了
dp[i][j] = dp[i + 1][j - 1] + 2;

} else {

// 若頭尾不同，看是捨棄左邊 (s[i]) 還是捨棄右邊 (s[j]) 比較
長
dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

}

}

}

// 最終答案就是涵蓋整個字串的區間 [0, n-1]
return dp[0][n - 1];

}

// 求解變成迴文的最少編輯距離 (包含插入、刪除、替換)
// 如果求最少 插入/刪除 字元，才能讓字串變成迴文的題目，請用 strlen - LPS(s)
pair<int, string> solvePalindromicDistance(const string& s) {

// 1. 找最少編輯次數
int n = s.length();
if (n == 0) return {0, ""};

// dp[i][j] 代表將字串 s 區間 [i, j] 變成迴文的最少編輯次數
vector<vector<int>> dp(n, vector<int>(n, 0));

// i 從字串的「尾巴」往「頭」掃
for (int i = n - 1; i >= 0; --i) {

dp[i][i] = 0; // 單一字元本身就是迴文，編輯距離為 0

// j 從 i 的下一個位置開始向右擴展
for (int j = i + 1; j < n; ++j) {

if (s[i] == s[j]) {

// 頭尾相同，不需要編輯
// 當 j == i+1 時，dp[i+1][j-1] 即 dp[i+1][i] 會是 0 (因
為預設值)
dp[i][j] = dp[i + 1][j - 1];

} else {

// 頭尾不同，取三種操作的最小值 + 1
// 1. dp[i+1][j]
// 2. dp[i][j-1]
// 3. dp[i+1][j-1] -> 直接把 s[i] 替換成 s[j] 或反之
dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j
- 1]}) + 1; // 如果有定義 cost 要記得改

-> 插入/刪除對應 s[i]
-> 插入/刪除對應 s[j]

}

}

}

// 2. 狀態回溯 (Backtracking)
string left_part = "", right_part = "";
int i = 0, j = n - 1;

while (i < j) {

if (s[i] == s[j]) { // 若頭尾相同，直接加入答案

left_part += s[i];
right_part += s[i];
i++; j--;

} else {

= (dp[i + 1][j - 1] + 1 == dp[i][j]); // 選擇

// 若頭尾不同，檢查是哪條最佳路徑轉移過來的
bool can_sub
用替代的
bool can_del_i = (dp[i + 1][j] + 1 == dp[i][j]); // 選擇刪除
i 的
bool can_del_j = (dp[i][j - 1] + 1 == dp[i][j]); // 選擇刪除
j 的

char best_c = 127; // 用來尋找字典序最小的字元 (ASCII 上限)
int choice = -1;

// 1: 替換, 2: 處理左側, 3: 處理右側

23
24
25

26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53

54
55
56
57
58
59
60

61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76

77

78

79
80
81

FJCU – UltraGrammer

Page 12 of 15

}

// 寫入最佳字元
left_part += best_c;
right_part += best_c;

// 評估替換策略 (選擇兩者中較小的字元)
if (can_sub) {

char c = s[i];
if (c < best_c) { best_c = c; choice = 2; }

char c = s[j];
if (c < best_c) { best_c = c; choice = 3; }

char c = min(s[i], s[j]);
if (c < best_c) { best_c = c; choice = 1; }

}
// 評估處理左側策略 (對應 s[i])
if (can_del_i) {

}
// 評估處理右側策略 (對應 s[j])
if (can_del_j) {

82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120 };
121
122 /*
123 有關迴文的其他題目補充
124 變化 1: 計算迴文子序列的「總數」 (排容原理)
125 if(s[i] != s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
126 if(s[i] == s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1
127
128 變化 2: 跨字串 (左 A 右 B) 的迴文
129 令 dp[i][j] 表示「A 從索引 i 開始的後綴」與「B 從索引 j 開始的前綴」所能構成的最

// 根據最佳策略移動指標
if (choice == 1) { i++; j--; }
else if (choice == 2) { i++; }
else if (choice == 3) { j--; }

// 組合最終字串 (右半部需要反轉)
reverse(right_part.begin(), right_part.end());

// 若最後指標交會於同一個字元，該字元放正中間
if (i == j) {

return {dp[0][n-1], left_part + right_part};

left_part += s[i];

}

}

}

}

長條件迴文長度。

130 if(A[i] == B[j]) dp[i][j] = dp[i+1][j-1] + 2
131 if(A[i] != B[j]) dp[i][j] = max(dp[i+1][j], dp[i][j-1])
132 */

8.4 跳格子

用 法: 給 定 一 組 陣 列， 固 定 跳 躍 距 離， 問 你 最 少 需 要 跳 幾 次， 以 及
所 跳 過 的 格 子 index。 如 果 數 值 達 到 long long，INF 需 設 為 1e18 或
0x3f3f3f3f3f3f3f3f

時間複雜度: O(N × K)
1 /*
2 題目出處: PUPC 2025 PC River Crossing
3 題目敘述: 給定一組陣列，1 表示可達，0 表示不可達，問你最少需要跳幾次可以跳到終點，

以及跳時經過的路徑

4 如果不需要輸出路徑，可以直接用 greedy，但要輸出路徑就需要用 DP
5 */
6
7 #include <bits/stdc++.h>
8 using namespace std;
9

10 int main(){
int kase;
11
cin >> kase;
12
while(kase--){
13
14
15
16
17 // v 存原始陣列, ans 存抵達該格的最短步數, pre 存 在最短步數的情況下，我上一格走

int n;
cin >> n;
vector<int> v(n), ans(n, 0x3f3f3f3f), pre(n, -1);

的位置

for(int i=0; i<n; ++i) cin >> v[i]; // 讀入陣列
ans[0] = 0; // 初始化: 跳到第 0 格的距離是 0
for(int i=1; i<n; ++i){ // 接下來每次遍例我的前三格

18
19
20
21
22
23
24 // 判斷: 1. 在邊界內， 2. 該格可走， 3. 重複確認該格可走 (如不可走，ans[i-j] 會

if(v[i] == 0) continue; // 如果該格不可達，
for(int j=1; j<=3; ++j){ // 這裡的 3 是題目設定的，請改成該題目設置的數值

if(i-j >= 0 && v[i-j] == 1 && ans[i-j] != 0x3f3f3f3f){

直接 skip，保留 INF)

if(ans[i] >= ans[i-j] + 1){ // 注意題目要求: 相同距離的情況下，格子要
選哪一個，在這題中紀錄的格子要越小越好

ans[i] = ans[i-j]+1;
pre[i] = i-j;

}

}

}

}
if(ans[n-1] == 0x3f3f3f3f) cout << -1 << '\n';
else{

cout << ans[n-1] << '\n';

int i = n-1;
stack<int> st;
st.push(n-1);
while(i > 0){

st.push(pre[i]);
i = pre[i];

}

bool first = true;

while(!st.empty()){

25

26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45

if(!first) cout << ' ';
first = false;
cout << st.top();
st.pop();

}
cout << '\n';

}

}
return 0;

46
47
48
49
50
51
52
53
54
55 }

8.5 LIS / LDS 最長遞增/遞減子序列

用法: 嚴格遞增用 lower_bound，非嚴格改用 upper_bound。替換策略下

的 dp 陣列長度正確，但內容不一定是真實子序列。

時間複雜度: O(N log N )
1 /*
2 二維套疊問題 (Russian Doll Envelopes / 箱子堆疊)
3 題意：給你一堆信封，每個有寬度和高度，問你最多可以把幾個信封像俄羅斯娃娃一樣套在

一起

4 解法：將寬度由小到大排序；當寬度相同時，高度必須由大到小排。接著，直接對高度的陣

列求 LIS

5
6 橋樑/連線不交叉問題 (Building Bridges)
7 題意：南岸和北岸各有 N 座城市，題目給定連線配對。要求建最多座橋，且橋與橋之間不能

交叉

8 解法：把南岸的城市編號由小到大排序，然後對它們對應的北岸城市編號求 LIS
9

10 最少覆蓋路徑 / 導彈攔截系統 (Dilworth 定理)
11 題意：系統每次只能攔截「高度遞減」的飛彈。給你一連串飛彈的高度，問你「最少」需要裝

備幾套攔截系統？

12 解法：「最少需要的遞減子序列數量」等價於 「最長遞增子序列 (LIS) 的長度」。求出 LIS

長度就直接是答案！

13
14 最長雙坡子序列 (Bitonic Subsequence)
15 題意：求一個數列，先嚴格遞增再嚴格遞減的最長長度。
16 解法：從左到右跑一次 LIS，記錄每個位置結尾的 LIS 長度；再從右到左跑一次 LIS（相當

於 LDS），記錄每個位置開頭的 LDS 長度。兩者相加減 1 的最大值即為所求。

17 */
18
19 // 1. 最長遞增子序列 (LIS) - (嚴格) 遞增
20 int get_lis(const vector<int>& arr) {
21
22
23

vector<int> dp;
for (int x : arr) {

24
25
26
27
28
29
30
31

// lower_bound: 找第一個 >= x 的位置 (若要求非嚴格遞增，改用
upper_bound)
auto it = lower_bound(dp.begin(), dp.end(), x);
if (it == dp.end()) {

dp.push_back(x); // 比所有數字都大，序列長度 + 1

} else {

*it = x; // 貪心策略：替換成較小的結尾，增加後續串接的潛力

}

}
return dp.size(); // dp 陣列的長度就是 LIS 的長度 (注意：dp 內容不一定是真
實 LIS)

vector<int> dp;
for (int x : arr) {

32 }
33
34 // 2. 最長遞減子序列 (LDS) - (嚴格) 遞減
35 int get_lds(const vector<int>& arr) {
36
37
38
39
40
41
42
43
44
45
46
47
48 }

}
return dp.size();

dp.push_back(x);

*it = x;

} else {

}

// LDS 只需要搭配 greater<int>() 來找第一個 <= x 的位置
// 若要求非嚴格遞減，改用 less_equal<int>() 等自訂比較
auto it = lower_bound(dp.begin(), dp.end(), x, greater<int>());
if (it == dp.end()) {

8.6 分錢幣問題

用法: 完全背包變體。求「方法數」需外層枚舉硬幣、內層枚舉金額 (求

組合數)。求「最少硬幣數」轉移取 min。於 main 開頭先建表。

時間複雜度: O(硬幣數 × 最大金額)
1 #include <iostream>
2 #include <vector>
3 using namespace std;
4
5 // 題型：給定數種硬幣，求「湊出金額 N 有幾種方法？」 (例如 UVa 357)
6 // 注意：方法數通常成長得非常快，必定會超過 int，請一律使用 long long！
7
8 const int MAX_AMOUNT = 30005; // 依據題目給定的最大金額修改
9 long long dp[MAX_AMOUNT];

// Base case: 湊出金額 0 的方法只有 1 種 (就是所有硬幣都不拿)
dp[0] = 1;

// 【核心陷阱：必須先枚舉硬幣，再枚舉金額】
// 這樣求出來的才是「組合數」(1+5 和 5+1 視為同一種方法)
for (int coin : coins) {

10 int coins[] = {1, 5, 10, 25, 50}; // 依據題目給定的硬幣種類修改
11
12 // 預處理建表：在 main() 迴圈開始前呼叫一次即可
13 void build_coin_change() {
14
15
16
17
18
19
20
21
22
23
24
25 }
26
27 /* * 延伸變體：如果題目是求「湊出金額 N 最少需要幾枚硬幣？」
28
29
30

* 1. 將 dp 陣列初始化為 INF，dp[0] = 0。
* 2. 轉移方程式改為：dp[j] = min(dp[j], dp[j - coin] + 1);
*/

dp[j] += dp[j - coin];

}

}

// 從該硬幣的面額開始往上推，因為金額小於硬幣面額時根本用不到這枚硬幣
for (int j = coin; j < MAX_AMOUNT; ++j) {

FJCU – UltraGrammer

Page 13 of 15

8.7 Kadane’s Algorithm (最大子陣列和)

用法: 尋找陣列中連續元素相加的最大值。若全為負數會正確回傳最大的

負數。

long long max_so_far = -1e18; // 紀錄歷史最大值 (預設極小值以防全負數)
long long curr_max = 0;

時間複雜度: O(N )
1 // 應用場景：題目要求在一個陣列中，找出一小段「連續」的數字，使得它們的總和最大。
2 long long kadane(const vector<long long>& arr) {
3
4
5
6
7
8
9
10
11
12 }

// 核心精神：如果加上自己，比自己單獨一個還要小，那不如「從自己重新開始」
curr_max = max(x, curr_max + x);
max_so_far = max(max_so_far, curr_max);

}
return max_so_far;

// 紀錄加上當前數字後的局部最大值

for (long long x : arr) {

9 Greedy

9.1 一維區間全覆蓋

用法: 需要先把輸入轉化成一個包含 l, r 的 struct，自訂 operator<，起

始位置由小到大排序

時間複雜度: O(N log N )
1 /*
2 題目敘述: 給定 N 個灑水器，每個灑水器包含座標 P 與半徑 R，已知草坪長度為 L，寬度

為 W，請問最少需要開啟幾個灑水器就能覆蓋整個區間 (或指定哪些灑水器)

3
4 題解: 先將灑水器圍轉化為 一個 struct point，用 l, r 區間表示能覆蓋的左右範圍，然

後自訂 operator<
5 1. 用開始位置排序
6 2. 每次都在 小於當前右界的區間中，選擇能往右最多的那個
7 3. 重複直到右區間 <L，得到最少數量；或者是在當前右邊界內找不到可選擇的表示不存在

解
8 */
9 const double eps = 1e-8;

}

return L < o.L;

double L, R;
bool operator<(const point&o) const{

10 struct point{
11
12
13
14
15 };
16
17 vector<point> v;
18 double pos, rad;
19 for(int i=0; i<n; ++i){
cin >> pos >> rad;
20
double real;
21
if(rad - w/2.0 < eps) continue; // 判斷如果半徑小於寬度就不可能被選，直接
22
不加入
real = sqrt(rad*rad - (w/2.0)*(w/2.0)); // real 表示實際可覆蓋距離
v.push_back({pos-real, pos+real});

23
24
25 }
26 sort(v.begin(), v.end());
27
28 int cnt = 0; // 總計數，如果要指定哪些灑水器就用 vector 存每次加入的
29 int i = 0;
30 double furthest = 0.0;
31 bool noAns = false;
32
33 while(L - furthest > eps){ // L > furthest
34
35
36
37
38
39
40
41
42
43
44
45 }
46 if(noAns) cout << -1 << '\n';
47 else cout << cnt << '\n';

double cur = furthest;
while(i < v.size() && v[i].L - furthest < eps){

}
if(cur - furthest < eps){

cur = max(cur, v[i].R);
++i;

}
furthest = cur;
++cnt;

noAns = true;
break;

9.2 間格跳躍

用法: 給定一組陣列，距離為 index 的值，問你最少需要跳多少次才能到

終點

// 總跳躍次數
// 「當前這一步」能到達的最遠邊界
// 探索過程中，發現「下一步」能到達的最遠距離

int jumps = 0;
int current_end = 0;
int farthest = 0;
bool noAns = false;

時間複雜度: O(N )
1 int jump(vector<int>& nums) {
2
3
4
5
6
7
8
9
10
11
12
13
14
15

// 注意：迴圈只走到 nums.size() - 2
// 因為如果已經站在最後一個位置，就不需要再起跳了
for (int i = 0; i < nums.size() - 1; ++i) {

// 邊走邊看，更新下一跳的最遠潛力
farthest = max(farthest, i + nums[i]);

// 當走到了「當前這步」的極限邊界時，就必須結算，進行「下一跳」
if (i == current_end) {

if(current_end == farthest){ // 如果被迫跳但發現一步都沒跳就代表走
不到終點

16
17
18
19
20
21

noAns = true;
break;

}
jumps++;
current_end = farthest; // 將邊界擴展到剛才探索到的最遠距離

22
23
24
25
26
27 }

if(current_end >= nums.size()-1) break; // 提前結束的優化

}

}
if(noAns) return -1;
return jumps;

9.3 最大不重疊區間

用法: 對一組任務做排程，請問最多可以移除多少個任務 -> 最早結束的

先選。

時間複雜度: O(N log N )
1 int countRemoves(vector<pair<int, int>> &intervals) {
2
3
4
5

if(intervals.empty()) return 0; // 不需要移除任何東西

// 用結束時間做排序
sort(intervals.begin(), intervals.end(), [](const auto&a, const
auto&b){return a.second < b.second;});

6
7
8
9
10

11

12
13
14
15 }

int removed = 0;
int cur_end = intervals[0].second; // 一開始必定選第一個任務
for(int i=1; i<intervals.size(); ++i){ // 遍歷所有任務

if(cur_end > intervals[i].first) ++removed; // 如果我目前的 end 能覆蓋
到當前 i 的左邊界就移除 i
else cur_end = intervals[i].second; // 否則我就要選 i，並設為當前右邊
界

}

return removed;

9.4 最小覆蓋區間

用法: 給定一組陣列，包含開始時間與結束時間，求最少需要幾個房間就

能完成所有任務

int st, ed;
bool operator<(const Interval &o) const {
if (st != o.st) return st < o.st;
return ed < o.ed; // 開始時間相同，較早結束的排前面

時間複雜度: O(N log N )
1 struct Interval {
2
3
4
5
6
7 };
8
9 int minMeetingRooms(vector<Interval>& intervals) {

}

// 先以開始時間排序

10
11
12
13
14
15
16

17
18
19
20
21

22
23

24
25
26
27
28
29
30
31

if (intervals.empty()) return 0;

// 1. 依照開始時間排序
sort(intervals.begin(), intervals.end());

// 2. 建立一個 Min-Heap，專門用來儲存「使用中會議室的結束時間」
// !! 如果需要印出順序，只要把 int(結束時間) 改成 pair<int, int>(結束時間,
房間編號)!!
priority_queue<int, vector<int>, greater<int>> min_heap;

// 3. 掃描每一個會議
for (const auto& interval : intervals) {

// 如果 pq 不為空，且最早結束的會議已經可以使用了 (當前會議的開始時間 >=
最早空出來的房間時間)
if (!min_heap.empty() && interval.st >= min_heap.top()) {

min_heap.pop(); // 該會議室空出來了，把舊的結束時間 pop 掉 (準備重
複利用)

}

// 把當前會議的結束時間塞進去 (代表佔用了一間會議室)
// 不管是開了一間新房間，還是接續前一間，當前的結束時間都要記錄
min_heap.push(interval.ed);

}

return min_heap.size(); // 最終 Heap 裡面剩下幾個元素，就代表我們同時需要幾
間會議室

32 }

9.5 區間選點問題

用法: 將區間依照右界由小到大排序。遍歷所有區段，如果當前區間的左

界大於目前選定點的右界，代表必須多選一個點

時間複雜度: O(N log N )
1 struct Interval {
2
3
4
5
6
7
8 };
9

}

int l, r;
// 依右界由小到大排序，右界相同時左界小的優先
bool operator<(const Interval& o) const {

if (r != o.r) return r < o.r;
return l < o.l;

int cnt = 1;
int current_r = intervals[0].r;

10 int minPoints(vector<Interval>& intervals) {
if (intervals.empty()) return 0;
11
sort(intervals.begin(), intervals.end());
12
13
14
15
16
17
18
19
20
21
22
23
24
25 }

}
return cnt;

}

for (int i = 1; i < intervals.size(); ++i) {

cnt++;
current_r = intervals[i].r; // 更新右界

// 若當前區間左界 > 目前紀錄的右界，代表無法共用同一個點
if (intervals[i].l > current_r) {

FJCU – UltraGrammer

Page 14 of 15

9.6 最小化最大延遲問題

9.9 多機調度問題

用法: 按照到期時間從早到晚處理。記錄當下累積的耗時，並與該任務的

死線相減，取最大的延遲時間
時間複雜度: O(N log N )
1 struct Job {
2
3
4
5
6
7 };
8
9 int minimizeLateness(vector<Job>& jobs) {
sort(jobs.begin(), jobs.end());

int time, deadline;
// 依到期時間由早到晚排序
bool operator<(const Job& o) const {
return deadline < o.deadline;

}

10
11
12
13
14
15
16
17
18
19
20
21
22 }

int current_time = 0;
int max_lateness = 0;

for (const auto& job : jobs) {
current_time += job.time;
// 延遲時間 = 完成時間 - 到期時間。若提早完成則延遲為 0
int lateness = max(0, current_time - job.deadline);
max_lateness = max(max_lateness, lateness);

}
return max_lateness;

9.7 Huffman 樹

// 宣告 Min-Heap
priority_queue<long long, vector<long long>, greater<long long>> pq;
for (int w : weights) pq.push(w);

long long total_cost = 0;

用法: 每次合併兩堆，成本是兩堆的重量和，求最小總成本
時間複雜度: O(N log N )
1 long long huffmanCost(const vector<int>& weights) {
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19 }

long long merged = first + second;
total_cost += merged;
pq.push(merged); // 將合併後的新重量塞回 Heap

// 每次挑選最小的兩堆合併，直到只剩一堆
while (pq.size() > 1) {

long long first = pq.top(); pq.pop();
long long second = pq.top(); pq.pop();

return total_cost;

}

9.8 任務調度問題

用 法: 依 照 懲 罰 由 大 到 小 排 序， 每 項 工 作 依 序 嘗 試 可 不 可 以 放 在

Di−Ti+1,Di−Ti,...,1,0，如果有空閒就放進去，否則延後執行。

時間複雜度: O(N )
1 struct Task {
2
3
4
5
6
7 };
8
9 // 利用並查集快速找尋「最晚可用的空閒天數」

int deadline, penalty;
// 依懲罰由大到小排序
bool operator<(const Task& o) const {
return penalty > o.penalty;

}

return parent[x] == x ? x : (parent[x] = find(parent[x]));

max_deadline = max(max_deadline, t.deadline);

parent.resize(n + 1);
for (int i = 0; i <= n; ++i) parent[i] = i;

}

sort(tasks.begin(), tasks.end());

}
int find(int x) {

vector<int> parent;
DSU(int n) {

int max_deadline = 0;
for (const auto& t : tasks) {

10 struct DSU {
11
12
13
14
15
16
17
18
19 };
20
21 long long taskScheduling(vector<Task>& tasks) {
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45 }

// 沒空位：只能放棄並承受懲罰
total_penalty += t.penalty;

DSU dsu(max_deadline);
long long total_penalty = 0;

}
return total_penalty;

for (const auto& t : tasks) {

if (available_slot > 0) {

} else {

}

}

// 尋找此任務到期日之前，最晚可用的空檔
int available_slot = dsu.find(t.deadline);

// 有空位：佔用這天，並將這天的 parent 指向前一天
dsu.parent[available_slot] = dsu.find(available_slot - 1);

用法: 將工作依耗時「由大到小」排序。每次將工作交給最快空閒出來的

機器。

時間複雜度: O(N log N )
1 struct Machine {
int id;
2
long long completion_time;
3
// Min-Heap：優先選擇最快空閒的機器。若時間相同，優先分給 ID 小的
4
bool operator>(const Machine& o) const {
5
6
7
8
9

return completion_time > o.completion_time;

if (completion_time != o.completion_time)

return id > o.id;

}

priority_queue<Machine, vector<Machine>, greater<Machine>> pq;
for (int i = 0; i < m; ++i) pq.push({i, 0});

Machine earliest = pq.top();
pq.pop();

// 依序把工作派給最快結束的機器
for (int job_time : jobs) {

// 工作依耗時由大到小排序 (Longest Processing Time first)
sort(jobs.begin(), jobs.end(), greater<int>());

10 };
11
12 long long multiprocessorScheduling(vector<int>& jobs, int m) {
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36 }

max_time = max(max_time, pq.top().completion_time);
pq.pop();

// 找出所有機器中最晚完工的時間
long long max_time = 0;
while (!pq.empty()) {

earliest.completion_time += job_time;
pq.push(earliest);

return max_time;

}

}

9.10 最大區間重疊數 Sweep Line

用法: 詢問在任意時刻可達到的最大重疊數量為何。將區間拆分為 +1 (開

始) 與 -1 (結束) 事件。時間相同時 -1 優先處理，避免多算重疊數。

}

for (auto& interval : intervals) {

// 開始時間，需求 +1
events.push_back({interval.first, 1});
events.push_back({interval.second, -1}); // 結束時間，需求 -1

// 儲存所有事件: pair< 時間點, 變化量 >
vector<pair<int, int>> events;

時間複雜度: O(N log N )
1 // 解決「最大區間重疊數」(簡易版 Sweep Line)
2 int sweep_line_overlap(const vector<pair<int, int>>& intervals) {
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25 }

// 排序規則：先按時間由小到大排；
// 若時間相同，變化量小的 (-1) 會自動排在 (+1) 前面！
// 這確保了「先退房間，再借房間」，不產生多餘的重疊。
sort(events.begin(), events.end());

current_overlap += event.second;
max_overlap = max(max_overlap, current_overlap);

int current_overlap = 0;
int max_overlap = 0;

for (auto& event : events) {

return max_overlap;

}

9.11 三分搜

用法: 求單峰/單谷函數極值。浮點數固定跑 100 次迴圈；整數在 R-L <

2 時改用 for 暴力找極值以避開死迴圈。

return x * x - 4 * x + 4; // x^2 - 4x + 4

double m1 = L + (R - L) / 3.0;
double m2 = R - (R - L) / 3.0;

// 浮點數一律固定跑 100~200 次 可以保證不會有無窮迴圈與精度問題
for (int i = 0; i < 100; ++i) {

時間複雜度: O(log3(值域))
1 // 目標函數：根據題目需求實作 (此處以尋找單谷函數 (U 型, 二次曲線) 的最小值為例)
2 double f(double x) {
3
4 }
5
6 // 浮點數三分搜
7 double ternary_search_double(double L, double R) {
8
9
10
11
12
13
14
15
16
17
18
19 }
20
21 // 整數三分搜 (尋找單谷函數的最小值)
22 long long ternary_search_int(long long L, long long R) {
23
24
25
26
27
28

// 若找最小值：如果 f(m1) > f(m2)，代表真正的底谷一定在 m1 的右邊
// (若題目為尋找單峰函數的【最大值】，將 > 改成 < 即可)
if (f(m1) > f(m2)) L = m1;
else R = m2;

long long m1 = L + (R - L) / 3;
long long m2 = R - (R - L) / 3;
if (f(m1) > f(m2)) L = m1;
else R = m2;

while (R - L > 2) { // 當區間大於 2 時才進行三分搜

}
return f(L);

}

FJCU – UltraGrammer

Page 15 of 15

53 q.front() : 回傳頂端元素，複雜度 O(1)
54 q.size() : 回傳元素個數，複雜度 O(1)
55 q.empty() : 回傳是否為空，複雜度 O(1)
56
57 pq.push(T a) : 插入元素 a，複雜度 O(logsize)
58 pq.pop() : 刪除頂端元素，複雜度 O(logsize)
59 pq.top() : 回傳頂端元素，複雜度 O(1)
60 pq.size() : 回傳元素個數，複雜度 O(1)
61 pq.empty() : 回傳是否為空，複雜度 O(1)
62
63 #include <deque>
64
65 dq.push_front(T a), dq.push_back(T a) : 插入頂端/尾端元素，複雜度 O(1)
66 dq.pop_front(), dq.pop_back() : 刪除頂端/尾端元素，複雜度 O(1)
67 dq.front(), dq.back() : 回傳頂端/尾端元素，複雜度 O(1)
68 dq.size() : 回傳元素個數，複雜度 O(1)
69 dq.empty() : 回傳是否為空，複雜度 O(1)
70
71 #include <set>
72
73 s.size() : 回傳元素個數，複雜度 O(1)
74 s.empty() : 回傳是否為空，複雜度 O(1)
75 s.clear() : 清除元素，複雜度 O(size)
76 s.insert(T1 a) : 加入元素 a, 複雜度 O(logsize)
77 s.erase(iterator first,iterator last) : 刪除 [first,last), 若沒有指定 last 則

只刪除 first

78 s.erase(T1 a) : 刪除鍵值 a, 複雜度 O(logsize)
79 s.find(T1 a) : 回傳指向鍵值 a 的迭代器，若不存在則回傳 s.end (), 複雜度

O(logsize)

80 s.count(T a) : 計算有幾個元素 a
81 s.lower_bound(T1 a) : 回傳指向第一個鍵值大於等於 a 的迭代器。複雜度 O(logsize)
82 s.upper_bound(T1 a) : 回傳指向第一個鍵值大於 a 的迭代器。複雜度 O(logsize)
83
84 #include <map>
85
86 m.size()
87 m.empty()
88 m.clear()
89 m.count()
90 m.erase(iterator first, iterator last)
91 m.erase(T1 a)
92 m.find(T1 a)
93 m.lower_bound(T1 a)
94 m.upper_bound(T1 a)

29
30
31
32
33
34
35 }

// 區間縮小到 2 以內時，直接暴力枚舉 L ~ R 找極值，完美避開死迴圈
long long ans = f(L);
for (long long i = L + 1; i <= R; ++i) {

ans = min(ans, f(i)); // 若找最大值，改用 max

}
return ans;

10 MISC

10.1 模板

用法: 競賽用基礎模板
時間複雜度: O(HowF astY ouT ype)
1 #include <bits/stdc++.h>
2 using namespace std;
3 using ll = long long;
4
5 int main(){
6
7
8 }

ios::sync_with_stdio(0); cin.tie(0); // 或使用 scanf
return 0;

10.2 一些概念

用法: 想不到怎麼解或優化的時候可以參考這些想法
時間複雜度: 咕咕嘎嘎
1 /*
2 前綴和
3 枚舉 (dfs、減少變數降低維度、集合拆半後枚舉、剪枝)
4 貪心 (每次都選局部最佳，但不能保證局部最佳解是全域最佳解)
5 雙指針
6 滑動窗口
7 Random Select(QuickSort)
8 對答案二分搜
9

10 Nim Game (賽局理論基礎): 桌上有 N 堆石頭， A1, A2 ... An，兩人輪流拿。
11 若 A1 ^ A2 ^ A3 ^ ... ^ An != 0，則先手必勝；若 XOR 總和為 0，則後手必勝。
12 */

10.3 C++ 函式庫

用法: 好用的東西可以參考
時間複雜度: N U LL
1 __builtin_popcount(x): 回傳整數 x 轉為二進位後 1 的數量 (若處理 long long 需使

用

2 __builtin_popcountll(x))。
3 __builtin_clz(x): 回傳二進位前導 0 的個數 (Count Leading Zeros)。
4 gcd(a, b), lcm(a, b): 求最大公因數 (C++17 引入, 需引入 <numeric>, 舊版編譯器可

使用內建的 __gcd(a, b))。

5 string 相關: stoi(s) 將字串轉為 int;
6 to_string(num) 將數字轉為字串;
7 s.substr(pos, len) 擷取子字串。
8
9 #include <algorithm>

10
11 sort(bg, ed) sort(bg, ed, cmp): 預設由小到大排序
12
13 min(a, b) min(list): 取最小值
14 max(a, b) max(list): 取最大值
15
16 min_element(first, last): 找尋連續資料中最小元素
17 max_element(first, last): 找尋連續資料中最大元素
18
19 find(first, last, val): 尋找元素。
20 lower_bound(first, last, val): 尋找第一個 ">=" x 的元素" 位置"，如果不存在，則

回傳 last

21 upper_bound(first, last, val): 尋找第一個 ">" x 的元素" 位置"，如果不存在，則回

傳 last

22
23 next_permutation(first, last): 將序列順序轉換成下一個字典序，如果存在回傳 true

，反之回傳 false

24 prev_permutation(first, last): 將序列順序轉換成上一個字典序，如果存在回傳 true

，反之回傳 false

25
26 unique(bg, ed): 將相鄰重複元素移至尾端，回傳新陣列無重複部分尾端的 iterator (或

指標)

27 reverse(bg, ed): 反轉區間內的元素順序
28
29 #include <cctype>
30
31 isalnum(int c): 判斷是否為數字或英文
32 isalpha(int c): 判斷是否為英文
33 isdigit(int c): 判斷是否為數字
34
35 islower(int c): 判斷是否為小寫字母
36 isupper(int c): 判斷是否為大寫字母
37
38 tolower(int c): 將字母轉成小寫字母
39 toupper(int c): 將字母轉成大寫字母
40
41 #include <stack>
42
43 s.push(T a) : 插入頂端元素，複雜度 O(1)
44 s.pop() : 刪除頂端元素，複雜度 O(1)
45 s.top() : 回傳頂端元素，複雜度 O(1)
46 s.size() : 回傳元素個數，複雜度 O(1)
47 s.empty() : 回傳是否為空，複雜度 O(1)
48
49 #include <queue>
50
51 q.push(T a) : 插入尾端元素，複雜度 O(1)
52 q.pop() : 刪除頂端元素，複雜度 O(1)

