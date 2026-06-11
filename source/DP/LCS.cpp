// LCS (線性 DP)：dp[i][j] 代表的是 s1 的前 i 個字元，與 s2 的前 j 個字元。這是一個從索引 0 開始的前綴

struct LCS {
    // 求解 LCS 並回傳最長共同子序列的字串
    // 若只需長度，直接回傳 dp[n][m] 即可
    string solve(const string& s1, const string& s2) {
        int n = s1.length(), m = s2.length();
        
        // dp[i][j] 代表 s1 的前 i 個字元與 s2 的前 j 個字元的 LCS 長度
        // 宣告 n+1 與 m+1 是為了讓 index 0 作為「空字串」的邊界條件 (全為 0)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // 1. 狀態轉移 (填表)
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    // 若字元相同，繼承左上角的答案 + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 若字元不同，取上方或左方的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 2. 回溯 (Backtracking) 找回原本的字串
        string res = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                // 如果字元相同，這一定是 LCS 的一部分
                res += s1[i - 1];
                i--; j--; // 往左上角回退
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // 如果不同，往數值比較大的方向走 (此處為上方)
                i--;
            } else {
                // 否則往左方走
                j--;
            }
        }
        
        // 因為是從尾巴推回去的，最後要把字串反轉
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
變化: 給定兩個字串，可以任意進行插入、刪除、取代三種操作
請問最少需要幾次操作可以使得兩字串完全一模一樣，並輸出過程?
與LCS大致相同，(相同、選左、選上)，但是多了一個取代的操作
所以轉移方程式會變成
dp[i][j] = min{
1. if(x[i] == y[j]) dp[i-1][j-1] 字元相同的情況
2. if(x[i] != y[j]) dp[i-1][j-1]+1 選擇"取代"
3. dp[i-1][j]+1 選擇"左邊"
4. dp[i][j-1]+1 選擇"右邊"
}

補充: 
Longest Palindrome Sequence 最長迴文子序列
給定一個字串，問你該字串的最長迴文子序列 "長度" 為多少
做法就是對 s1 與 s2=reverse(s1) 做一次LCS，即可得到 "最長長度"

變化: 求最少插入/刪除次數以形成迴文
如果只求長度 -> strlen - LPS(s)
否則就要使用到區間DP的內容了
*/