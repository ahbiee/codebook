// LPS (區間 DP)：dp[i][j] 代表的是同一個字串 s 裡面，從索引 i 到 j 的這段閉區間（也就是子字串 s[i...j]）

struct IntervalDP {
    // 求解最長迴文子序列 (LPS) 長度
    int solveLPS(const string& s) {
        int n = s.length();
        if (n == 0) return 0;

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
                    // 因為 i 是倒著掃，j 是正著掃，所以 dp[i+1][j-1] 絕對已經算過了
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // 若頭尾不同，看是捨棄左邊(s[i])還是捨棄右邊(s[j])比較長
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // 最終答案就是涵蓋整個字串的區間 [0, n-1]
        return dp[0][n - 1];
    }
};

/*
有關迴文題目的補充
變化1: 計算迴文子序列的「總數」 (排容原理)
if(s[i] != s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
if(s[i] == s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1

變化2: 最少插入次數成為新迴文 ＆ 輸出字典序最小的新迴文 (如果只求長度，請用strlen - LPS(s))
if(s[i] != s[j]) dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1
if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1]
回溯過程 (可使用deque):
if(s[i] == s[j])：兩端直接放 s[i]，然後 $i++, j--$
if(dp[i+1][j] < dp[i][j-1])：代表是選擇在右邊插入與 s[i] 相同的字元。兩端放 s[i]，然後 i++
if(dp[i+1][j] > dp[i][j-1])：代表是選擇在左邊插入與 s[j] 相同的字元。兩端放 s[j]，然後 j--
if(dp[i+1][j] == dp[i][j-1])：代表補 s[i] 或補 s[j] 都能達到最少次數。這時為了字典序最小，我們直接比較 min(s[i], s[j])，誰小就補誰！
注意: 當i==j，記得把s[i]放到答案正中間

變化3: 跨字串(左A右B)的迴文
令 dp[i][j] 表示「A 從索引 i 開始的後綴」與「B 從索引 j 開始的前綴」所能構成的最長條件迴文長度。
if(A[i] == B[j]) dp[i][j] = dp[i+1][j-1] + 2
if(A[i] != B[j]) dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/