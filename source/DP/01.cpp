/*
題目敘述：給定N個物品的重量Wi和價值Vi，和個容量為W的背包。選取若干件物品放入背包，在不超過背包容量的情況下，背包內物品價值總和最大為何?

定義 dp[i][j] 表示: 在考慮前i個物品，且考慮重量 <=j 的情況下，所能得到的最大價值是多少 (假設index 0不放東西)
初始: 對於所有的i=0, dp[i][j] = 0 (不考慮任何物品的情況下，最大價值是0)，也可以直接預設所有位置都是0
轉移函式: dp[i][j] = max(dp[i-1][j], dp[i-1][j-Wi] + Vi);
-> 兩種情況:
1. 不放第i件物品，最大價值與前一項相同ㄊ
2. 放入第i件物品，最大價值為 扣除目標重量後的最大價值 加上當前物品的價值之總和
*/

/*
===== 原始 01 背包 =====
適用情況: 需要backtrack
-> 從 dp[MAXN][MAXW] 開始檢查:
如果 dp[i][j] == dp[i-1][j] 表示沒有拿第i個，接著讓i = i-1繼續跑
否則我們有拿第i個，接著跳到dp[i-1][j-w[i]]
重複直到 i=0 (沒東西了) 或 j=0 (重量用完了)
*/
int dp[MAXN + 1][MAXW + 1];
memset(dp, 0, sizeof(dp)); // 初始化為0
for (int i = 1; i <= MAXN; ++i) // 從考慮第一個物品到第N個物品
{
    for (int j = 0; j < w[i]; ++j) // 如果當前考慮重量小於Wi，代表沒辦法裝下第i個物品，直接繼承前一項
        dp[i][j] = dp[i - 1][j];
    for (int j = w[i]; j <= MAXW; ++j) // 否則就用transition function找max
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
}
cout << dp[MAXN][MAXW] << '\n'; // 最終答案在最右下那格

/*
===== 滾動陣列優化 =====
概念: 在計算考慮第i個物品時，我們只會用到第i-1行的資料，可以看成陣列中的上一筆舊資料
透過想法上的極致壓縮，覆寫無用資料空間，可將空間複雜度降至 O(W)
限制是 j 必須由大往小跑，如果由小至大會重複使用到陣列資料導致答案錯誤
*/

int dp[MAXW + 1];
memset(dp, 0, sizeof(dp));
for(int i = 1; i <= MAXN; ++i) // 注意一樣是要跑MAXN次，我們只是把陣列大小減少了
    for(int j = MAXW; j >= w[i]; --j) // dp[j]在等號左邊表示當前，等號右邊表示上一筆資料
        dp[j] = max(dp[j], dp[j-w[i]] + v[i]); // 不需要考慮j < w[i] 的情況，因為它會繼承上一個結果
cout << dp[MAXW] << '\n';

/*
===== 完全背包 (無限背包) =====
已知: 第 i 個物品重量為 wi，價值 vi；背包總容量 W，且每一個物品都可以重複(無限次)取用
*/
int W;
int w[maxn], v[maxn];
int dp[maxw];

memset(dp, 0, sizeof(dp));
for(int i=1; i<=n; i++)
    for(int j=w[i]; j<=W; j++)
        dp[j] = max(dp[j], dp[j-w[i]]+v[i]);

/*
===== 分組背包 =====
第 i 組第 j 個物品重量為 wij，價值 vij；背包總容量 W；但每組只能取一個
*/
int W;
int dp[maxw];
vector<vector<int>> w, v;

memset(dp, 0, sizeof(dp));
for(int i=0; i<n; i++)
    for(int j=W; j>=0; j--)
        for(int k=0; k<w[i].size(); k++)
            if(j >= w[i][k])
                dp[j] = max(dp[j], dp[j-w[i][k]] + v[i][k]);

/*
===== 多背包共用商品 =====
題目：N個物品(同一項商品可被多個人同時取用)，G個人各自有容量為 Wi 的背包，求所有人能拿的最大價值總和。

題解：每個人挑選互相獨立，不需重複計算。(查表)
1. 以所有商品跑一次標準一維 0/1 背包，每次讀入Wi與Vi時就run一次，建立 dp 陣列。
2. 結束後跑一遍 dp[i] = max(dp[i], dp[i-1]) 確保單調性。
3. 讀入每個人的容量 W，總答案 ans += dp[W]。
*/

// N 個物品，G 個人
// 假設最大可能的背包容量為 MAX_W
const int MAX_W = 100000;

int main() {
    int N, G;
    // 讀入物品數量與人數
    if (!(cin >> N >> G)) return 0;

    // dp[i] 代表容量為 i 的背包能裝的最大價值
    vector<long long> dp(MAX_W + 1, 0);

    // 1. 標準一維 0/1 背包
    for (int i = 0; i < N; ++i) {
        int w, v; // w: 重量, v: 價值
        cin >> w >> v;
        // 【注意】0/1 背包必須從大到小遍歷，避免重複拿取
        for (int j = MAX_W; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    // 2. 確保單調遞增 (這步很關鍵，確保容量較大的人至少能拿到容量較小時的最大價值)
    for (int j = 1; j <= MAX_W; ++j) {
        dp[j] = max(dp[j], dp[j - 1]);
    }

    // 3. 每個人各自查表，累加總價值
    long long ans = 0;
    for (int i = 0; i < G; ++i) {
        int W; // 第 i 個人的背包容量
        cin >> W;
        ans += dp[W];
    }

    cout << ans << "\n";

    return 0;
}

/*
=== 恰好裝滿問題 / 子集合和 ===
題目敘述： 給定N樣物品，每件物品的重量分別為Wi，問可不可以將物品分成等重的兩堆。

題解：首先判斷總重是否為二的倍數，如果不是就直接輸出NO然後下一個case
如果可以的話就使用一維DP解，總重/2當作MAXW (dp大小)，每件行李的重量是價值，看是否存在 dp[MAXW] = MAXW (在裝入一半行李的情況下，總重剛好也是一半)
*/