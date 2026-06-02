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
                    // 當 j == i+1 時，dp[i+1][j-1] 即 dp[i+1][i] 會是 0 (因為預設值)
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    // 頭尾不同，取三種操作的最小值 + 1
                    // 1. dp[i+1][j]   -> 插入/刪除對應 s[i]
                    // 2. dp[i][j-1]   -> 插入/刪除對應 s[j]
                    // 3. dp[i+1][j-1] -> 直接把 s[i] 替換成 s[j] 或反之
                    dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1; // 如果有定義cost要記得改
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
                // 若頭尾不同，檢查是哪條最佳路徑轉移過來的
                bool can_sub   = (dp[i + 1][j - 1] + 1 == dp[i][j]); // 選擇用替代的
                bool can_del_i = (dp[i + 1][j] + 1 == dp[i][j]); // 選擇刪除i的
                bool can_del_j = (dp[i][j - 1] + 1 == dp[i][j]); // 選擇刪除j的

                char best_c = 127; // 用來尋找字典序最小的字元 (ASCII 上限)
                int choice = -1;   // 1: 替換, 2: 處理左側, 3: 處理右側

                // 評估替換策略 (選擇兩者中較小的字元)
                if (can_sub) {
                    char c = min(s[i], s[j]);
                    if (c < best_c) { best_c = c; choice = 1; }
                }
                // 評估處理左側策略 (對應 s[i])
                if (can_del_i) {
                    char c = s[i];
                    if (c < best_c) { best_c = c; choice = 2; }
                }
                // 評估處理右側策略 (對應 s[j])
                if (can_del_j) {
                    char c = s[j];
                    if (c < best_c) { best_c = c; choice = 3; }
                }

                // 寫入最佳字元
                left_part += best_c;
                right_part += best_c;

                // 根據最佳策略移動指標
                if (choice == 1) { i++; j--; }
                else if (choice == 2) { i++; }
                else if (choice == 3) { j--; }
            }
        }

        // 若最後指標交會於同一個字元，該字元放正中間
        if (i == j) {
            left_part += s[i];
        }
        
        // 組合最終字串 (右半部需要反轉)
        reverse(right_part.begin(), right_part.end());
        
        return {dp[0][n-1], left_part + right_part};
    }
};

/*
有關迴文的其他題目補充
變化1: 計算迴文子序列的「總數」 (排容原理)
if(s[i] != s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
if(s[i] == s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1

變化2: 跨字串(左A右B)的迴文
令 dp[i][j] 表示「A 從索引 i 開始的後綴」與「B 從索引 j 開始的前綴」所能構成的最長條件迴文長度。
if(A[i] == B[j]) dp[i][j] = dp[i+1][j-1] + 2
if(A[i] != B[j]) dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
