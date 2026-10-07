# Codebook 審查與改版說明

基準版本：GitHub `ahbiee/codebook` main @ `8b06774`（2026-10-05，與本機「Codebook 25 pages」內容一致）。
舊版完整保留在 git 歷史中，可用 `git diff` 逐檔比對。

新版 PDF：**17 頁**（上限 25 頁，保留約 5 頁給你自己加東西）。

---

## 一、改寫原則

1. **全部改成「全域陣列 + 一般函式」**：拿掉所有 `struct`、建構子、成員函式、`init` 方法。
   - 圖的邊改成 `to[] / cap[]` 平行陣列，反向邊 = `e ^ 1`（Dinic、MCMF）。
   - 幾何的點改成 `pair<ld, ld>`，搭配 `dot / cross / len` 等自由函式。
   - 需要排序的資料改用 `pair` / `tuple` + lambda 比較函式。
2. **`// [改]` 標記**：題目變形時通常要改的那一行都有這個標記，檔案最後還有一段 `[變形]` 清單。
3. **每份檔案都能直接接在 Template 後面編譯**。需要其他檔案時，註解會寫「需要 XXX.cpp」。
4. **全部測試過**：每份檔案都用 g++ -std=c++17 編譯過，核心演算法都和暴力解隨機對拍過（約 60 組測試，數千到數萬筆隨機資料）。

---

## 二、原版會編譯錯誤或答案錯誤的地方（都已修正）

| 檔案 | 問題 |
|---|---|
| SegmentTree.cpp | `vector<ll> arr, sum/tree, add;` 語法錯誤 |
| MonotonicQueue.cpp | min 版本的 `while` 沒有迴圈本體，會把下一行 `dq.push_back(i)` 當成迴圈內容 |
| MonotonicStack.cpp | 中文說明沒有加註解符號 |
| Binary.cpp | 第 1 行中文沒有註解；基本找值寫成 `mid == target`，應為 `a[mid] == target` |
| Dijkstra.cpp | struct 內的非 static `const int MAXN` 被拿來當陣列大小，會編譯錯誤 |
| AC.cpp / Trie.cpp | `size`、`MAXN` 未定義 |
| AC.cpp | `query` 把 `stop` 改成 -1，只能查一次，且每個 pattern 只算一次（說明裡沒寫） |
| DFS.cpp | `subtree_size` 未宣告 |
| Diameter.cpp | `cur->next`、呼叫 `dist(...)` 而不是 `dfs(...)` |
| DisjointSet.cpp | `void init(n)` 少了型別 |
| Combinatorics.cpp | `fast_pow` 只傳 2 個參數，但 FastPower.cpp 的版本需要 3 個 |
| invModulo.cpp | 函式 `inv` 與陣列 `inv[]` 撞名；`MAXN`、`MOD` 未定義 |
| Prime.cpp | `MAXN` 同時是 const 和 #define；`isPrime` 同時是函式和陣列；`ll` 未定義；歐拉篩 `i*p[j] <= MAXN` 會越界 |
| Hungarian.cpp | `e` 從來沒有讀入，結果一條邊都沒讀 |
| Intersection.cpp / PointLine.cpp | 兩個檔案都定義了 `on_segment`，而且語意不同，一起貼會重複定義 |
| Circle.cpp | 依賴 PointLine.cpp 的 `length()`，而且 main.tex 根本沒有引用這個檔案 |
| 01.cpp | `w[MAXW+1]` 的大小應該是物品數；MAXN / maxn / MAXW / maxw 混用 |
| MatrixFastPower.cpp | `int` 相乘會溢位，而且沒有取模 |
| LIS_LDS.cpp | 註解說「非嚴格遞減改用 `less_equal`」是錯的，應為 `upper_bound` + `greater<int>()` |
| BCC.cpp | 只有在 n == 1 時才處理孤立點，n > 1 的孤立點不會成為 BCC；也沒有求橋 |
| SecondMST.cpp | O(VE) 暴力，n、m 到 1e5 會 TLE；求的也不是「嚴格」次小生成樹 |
| teamnote.sty | `\topsep=... minus 4pt` 會讓程式碼區塊往上壓到「時間複雜度」那一行 |

## 三、main.tex 和程式碼對不上的地方（都已修正）

- 「Traversal 遍歷」引用的是 `DisjointSet.cpp`，所以 `Traversal.cpp` 從來沒被印出來。
- Sparse Table 建表寫 O(log n)，實際是 O(n log n)；LOG 的註解寫 ln，應為 log2。
- KMP 說明寫「pi[i] 是長度」，程式存的卻是「長度 − 1」(−1-based)。新版統一改成長度。
- Trie 說明寫「必須 0-based」，程式的 root 卻是 1。
- 複雜度寫錯：Legendre（應為 O(log_p n)）、01 背包（應為 O(NW)）、LCA（應為預處理 O(N log N)、查詢 O(log N)）、Traversal（應為 O(N)）、任務調度（應為 O(N log N)）。
- 直徑說明寫「邊權不可為負」（暗示帶權），程式卻是無權版。
- 分錢幣說明提到「最少硬幣數取 min」和「main 開頭建表」，程式都沒有。
- 組合數說明寫 N ≤ 1e6，程式的 MAXN 是 2005，而且和帕斯卡三角形共用。
- 任務調度說明寫了 heap 解法，但沒有對應的程式碼；`$le 10^6$` 少了反斜線。
- 「判斷線段、矩形相交」的矩形部分其實寫在 PolygonArea.cpp 的註解裡。
- 對拍器 checklist 說「掃描線同座標先加入再移除」，SweepLineOverlap 卻說「−1 優先」，兩者矛盾。新版說明：要看是開區間還是閉區間。
- DFS.cpp 的註解前一行寫「找最短路徑」，下一行寫「更新最長路徑」。
- MonotonicQueue 的註解寫「最長遞減序列」，實際是 sliding window max。
- `Math/math.cpp`、`Others/FastIO.cpp`、`Search/SlidingWindow.cpp` 是空檔案（後兩個已補上內容）。

## 四、新增內容

**保留在 PDF 裡的：**
- **解題流程**（第 1 章）：N 範圍對應的複雜度表、題目關鍵字對應的演算法表、題目變形時的 8 種處理方式，以及合併後的檢查清單。
- **分層圖 / 狀態圖**（`Graph/LayeredGraph.cpp`）：最短路加上額外條件時用，附「題目條件 → 狀態」對照表。
- **二維費用背包**（`DP/01.cpp` 的 2b）：同時限制兩種資源（例: NCPC 2026 初賽第六題的時間 + 雞蛋），用滾動陣列。
- 小型補充：網格 BFS、多源 BFS、0-1 BFS、最短路條數與路徑還原、BIT 區間加區間和、座標壓縮、多重背包、編輯距離、輸出 LIS、折半枚舉、滑動視窗、常用公式。

**先註解掉、還沒學的（檔案都留在 source/ 裡）：**
在 `main.tex` 搜尋 `[未學`，把那一行最前面的 `%` 刪掉，重新編譯就會出現在 PDF 裡。

| 主題 | 檔案 |
|---|---|
| SCC 強連通分量 / 2-SAT / 歐拉路徑 / MCMF | Graph/SCC.cpp、TwoSAT.cpp、Euler.cpp、MCMF.cpp |
| 樹 DP・換根 DP・樹壓平 / HLD | Tree/TreeDP.cpp、HLD.cpp |
| 字串 Hash / Suffix Array | String/Hash.cpp、SuffixArray.cpp |
| Miller-Rabin / CRT / NTT | Math/MillerRabin.cpp、CRT.cpp、NTT.cpp |
| 莫隊 | DataStructure/Mo.cpp |
| 位元 DP / 數位 DP / 李超線段樹 | DP/Bitmask.cpp、Digit.cpp、LiChao.cpp |
| 最近點對 / 矩形面積聯集 | Geometry/ClosestPair.cpp、RectUnion.cpp |
| Möbius、Burnside 公式 | main.tex「常用公式」裡被 % 掉的兩行 |

另外，橋（BCC.cpp）和 Möbius（線性篩）的程式碼已直接拿掉，CRT 搬到獨立的 `Math/CRT.cpp`。

## 五、刪減或改寫的內容（舊版都在 git 歷史中）

- `huffman.cpp` 的測試 main 與輸出部分（保留合併成本與編碼）。
- `gen.cpp` 重新整理：保留所有產生器（陣列/排列/字串/區間、各種形狀的樹、一般圖、DAG、完全圖），另外新增「保證連通的圖」與「網格」，以及 Windows `.bat` 版對拍腳本。
- `Binary.cpp` 裡「+0++- 構造題」的完整 check 程式碼改成兩行說明（這題太特定）。
- `TwoPointer.cpp` 的 linked-list 快慢指針（用到指標）改成 Floyd 判圈的一行說明。
- `Traversal.cpp` 的 `TreeNode*` 指標版改成陣列版（`lc[] / rc[]`）。
- `functions.cpp` 的 STL 說明壓縮成速查表。

## 六、使用注意

- 需要 **C++17**（使用了 structured binding `auto [a, b]`）。
- `Math/math.cpp` 是空檔案、沒有被引用，可以刪除。
- 幾份檔案的陣列很大，使用前先確認題目的記憶體限制：LCS 的 3005² int 約 36MB、TSP 2^18×18 ll 約 38MB、線性篩 1e7 約 50MB、Li Chao 的 XR 開到 1e6 時約 64MB。
- 本機編譯方式不變（VS Code LaTeX Workshop 或 GitHub Actions）。只新增了 `array` 套件（TeX Live 內建）。
