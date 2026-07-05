// 使用當下時間作為亂數種子，確保每次執行生成的測資都不同
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/*
或 random_device rd; mt19937 rng(rd());
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
*/

// 生成 [L, R] 範圍內的隨機整數
long long rnd(long long L, long long R) {
    return uniform_int_distribution<long long>(L, R)(rng);
}

// 1. 陣列與字串 (Array & String)

// 生成排列 (Permutation: 1 到 n 不重複)
void gen_permutation(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    for (int i = 0; i < n; ++i) cout << p[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
}

// 生成重複值很多的陣列 (distinct_count 控制相異數字的數量)
void gen_array_few_distinct(int n, long long L, long long R, int distinct_count) {
    vector<long long> pool;
    for (int i = 0; i < distinct_count; ++i) pool.push_back(rnd(L, R));
    for (int i = 0; i < n; ++i) {
        cout << pool[rnd(0, distinct_count - 1)] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

// 生成已排序或完全反序的陣列
void gen_sorted_array(int n, long long L, long long R, bool reverse_sort = false) {
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd(L, R);
    if (reverse_sort) sort(a.rbegin(), a.rend());
    else sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
}

// 生成隨機字串
void gen_string(int n, string charset = "abcdefghijklmnopqrstuvwxyz") {
    for (int i = 0; i < n; ++i) {
        cout << charset[rnd(0, charset.size() - 1)];
    }
    cout << "\n";
}

// 2. 樹論結構生成器 (Trees)

// 輔助函式：打亂邊的順序與節點編號，避免特殊的編號順序讓錯誤的 Code 賽中
void print_tree(int n, vector<pair<int, int>>& edges, bool weighted = false, long long max_w = 100) {
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin() + 1, p.end(), rng); // 打亂 1~n 的編號
    shuffle(edges.begin(), edges.end(), rng); // 打亂邊的順序

    for (auto& e : edges) {
        int u = p[e.first], v = p[e.second];
        if (rnd(0, 1)) swap(u, v); // 隨機交換 u, v 順序
        cout << u << " " << v;
        if (weighted) cout << " " << rnd(1, max_w);
        cout << "\n";
    }
}

// 鏈狀樹 (Chain / Bamboo)：一條線到底 (常卡遞迴深度)
void gen_chain(int n, bool weighted = false) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) edges.push_back({i - 1, i});
    print_tree(n, edges, weighted);
}

// 星狀樹 (Star)：一個中心點連向所有其他點 (常卡度數度為 O(N) 的暴力解)
void gen_star(int n, bool weighted = false) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) edges.push_back({1, i});
    print_tree(n, edges, weighted);
}

// 完全二元樹 (Complete Binary Tree)：樹高最低的平衡樹
void gen_complete_binary_tree(int n, bool weighted = false) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) edges.push_back({i / 2, i});
    print_tree(n, edges, weighted);
}

// 毛毛蟲樹 (Caterpillar)：一條主幹，其餘點全部直接連在主幹上
void gen_caterpillar(int n, bool weighted = false) {
    vector<pair<int, int>> edges;
    int chain_len = max(2LL, rnd(2, n - 1)); // 隨機決定主幹長度
    for (int i = 2; i <= chain_len; ++i) edges.push_back({i - 1, i});
    for (int i = chain_len + 1; i <= n; ++i) {
        int attach_to = rnd(1, chain_len); // 剩下的點隨機接在主幹上
        edges.push_back({attach_to, i});
    }
    print_tree(n, edges, weighted);
}

// 3. 圖論結構生成器 (Graphs)

// 有向無環圖 (DAG)
void gen_dag(int n, int m, bool weighted = false, long long max_w = 100) {
    // DAG 的特性：只要所有邊都由編號小的連向編號大的，就絕對無環
    set<pair<int, int>> edges;
    while (edges.size() < m) {
        int u = rnd(1, n - 1);
        int v = rnd(u + 1, n);
        edges.insert({u, v});
    }
    
    // 一樣打亂編號輸出
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin() + 1, p.end(), rng);
    
    vector<pair<int, int>> edge_list(edges.begin(), edges.end());
    shuffle(edge_list.begin(), edge_list.end(), rng);
    
    for (auto& e : edge_list) {
        cout << p[e.first] << " " << p[e.second];
        if (weighted) cout << " " << rnd(1, max_w);
        cout << "\n";
    }
}

// 完全圖 (Complete Graph)：N 個點有 N*(N-1)/2 條邊 (常卡 O(E^2) 演算法)
void gen_complete_graph(int n, bool weighted = false, long long max_w = 100) {
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            edges.push_back({i, j});
        }
    }
    // 不需打亂節點，因為大家互相都有連線，只要打亂邊的順序即可
    shuffle(edges.begin(), edges.end(), rng);
    for (auto& e : edges) {
        if (rnd(0, 1)) cout << e.first << " " << e.second;
        else cout << e.second << " " << e.first;
        if (weighted) cout << " " << rnd(1, max_w);
        cout << "\n";
    }
}

// 4. 生成隨機區間 [l, r] (Sweep Line, 區間 DP 題型)
void gen_intervals(int n, long long max_val) {
    for (int i = 0; i < n; ++i) {
        long long l = rnd(1, max_val);
        long long r = rnd(1, max_val);
        if (l > r) swap(l, r);
        cout << l << " " << r << "\n";
    }
}

// 主程式呼叫範例
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    // ======== 在這裡調整你的測資 ========
    // 例如：題目要求輸出 T 筆測資，每筆有 N 個長度為 M 的陣列
    int T = 1; 
    // cout << T << "\n"; // 如果題目有多筆測資取消註解

    while(T--){
        int N = 10, M = 15;
        cout << N << " " << M << "\n";

        // 根據你的需求，取消註解對應的測資生成器
    
        // [陣列 Edge Cases]
        // gen_array_few_distinct(N, 1, 100, 2); // 只有 2 種不同數字的陣列
        // gen_sorted_array(N, 1, 100, true); // 完全反序的陣列
        // gen_permutation(N); // 1~N 的排列
        
        // [樹論 Edge Cases]
        // gen_chain(N, false); // 產生長度為 10 的鏈狀樹 (無權重)
        // gen_star(N, true); // 產生 10 個點的星狀樹 (帶隨機權重)
        // gen_caterpillar(N, false); // 產生毛毛蟲樹
        
        // [圖論 Edge Cases]
        gen_dag(N, M, true); // 產生 10點 15邊的帶權 DAG
        // gen_complete_graph(N, false); // 產生完全圖
    }
    
    return 0;
}

---

//!/bin/bash

// 1. 編譯所有相關程式 (加上 -O2 模擬正式評測環境)
g++ gen.cpp -o gen -O2
g++ sol.cpp -o sol -O2
g++ brute.cpp -o brute -O2

echo "編譯完成，開始對拍..."
echo "-------------------"

// 2. 進入無限迴圈進行對拍
for ((i=1; ; ++i)); do
    // 生成測資並存入 in.txt
    ./gen > in.txt
    
    // 將測資餵給正確的暴力解，輸出到 ans.txt
    ./brute < in.txt > ans.txt
    
    // 將測資餵給你寫的待測程式，輸出到 out.txt
    ./sol < in.txt > out.txt
    
    // 使用 diff 比對兩個輸出檔 (-w 忽略行尾與空白差異，也可不寫)
    if diff -w out.txt ans.txt > /dev/null; then //
        // 如果沒有差異，印出 AC
        echo "Test Case $i: AC"
    else
        // 如果有差異，停止腳本並報錯
        echo "Test Case $i: WA! 發現錯誤測資！"
        break
    fi
done

echo "對拍結束。"


/*
在同一個資料夾下，準備好四個檔案：
sol.cpp：你寫的，會吃 WA 但跑很快的最佳化程式碼。
brute.cpp：你寫的，保證絕對正確，但肯定會 TLE 的暴力解程式碼（例如 O(N!) 枚舉、O(N^3) 暴力轉移等）。
gen.cpp：上述的測資生成器。
checker.sh：上述的 Bash 腳本。

打開 gen.cpp，修改 main 函式裡面的變數。
測資規模（如 N 或數值範圍）一定要調小。如果 N 設到 10^5，找到錯誤測資也無法用手算推導。
通常設 N <= 10，數值 <= 100 就足夠觸發大部分的 Edge case。

打開 terminal 執行
```
// 賦予腳本執行權限 (只需要做一次)
chmod +x checker.sh

// 執行對拍
./checker.sh
```

當螢幕印出 Test Case X: WA! 發現錯誤測資！ 時，腳本會自動停止。此時你該資料夾下會擁有：
in.txt：引發錯誤的極小測資。（打開它，這就是你一直找不到的 Counter Example）。
ans.txt：暴力解跑出來的正確答案。
out.txt：你寫的程式跑出來的錯誤答案。
*/

/*
文字找碴版:
一、資料規模與全域陷阱整數溢位（Integer Overflow）：
這是最致命也最常見的失誤。兩個 int 相乘或相加是否會超過 32-bit 的上限？
在 C++ 中計算時，記得提早轉型，例如寫成 1LL * a * b。
多筆測資未清空： 在 Codeforces 或 LeetCode 刷題時，如果題目有多筆測試資料，全域變數、vector、map 或 set 是否在每一輪開始前都有確實執行 clear()？
未清空會直接污染下一筆測資。

二、陣列與字串處理極小規模： 
陣列長度 N=0 或 N=1。很多迴圈邏輯或雙指標在這種長度下會直接崩潰或發生越界。
元素全同： 陣列內所有數字都一樣（例如 [2, 2, 2, 2]）。貪心演算法或雙指標有沒有可能因此陷入無窮迴圈？
找不到目標： 字串或陣列中完全沒有符合條件的元素。程式是否能正確回傳題目要求的值（例如 -1 或 0），而不是噴出例外錯誤。
索引越界（Out of Bounds）： 只要程式碼裡出現 i-1、i+1 或是二維陣列的八方位搜尋，務必檢查邊界條件。

三、圖論與樹圖不連通（Disconnected Graph）： 
題目如果沒有保證圖是連通的，你的 DFS 或 BFS 是否能走訪到所有節點？
執行 Kruskal's 演算法找最小生成樹後，選取的邊數是否確實為 V-1？
自環與重邊（Self-loops & Multiple edges）： 節點自己連向自己，或是節點 A 到節點 B 之間有兩條權重不同的邊。建圖時是否正確處理了這些冗餘資訊？
退化結構： 樹退化成一條直線（Linked list），這會導致遞迴深度達到 $O(N)$，容易引發 Stack Overflow；或是退化成一個中心連向所有點的星狀圖（Star graph），考驗時間複雜度。
孤島節點： 節點數 V=1 但邊數 E=0 的情況。

四、進階資料結構與演算法線段樹（Segment Tree）與 BIT： 
在處理區間查詢 [L, R] 時，是否有考慮到 L > R 的非法情況？或是 L = R 時單點更新是否正確？
掃描線（Sweep Line）： 遇到 X 座標完全相同的多個點時，事件的處理順序是否正確？（通常必須先處理「加入區間」的事件，再處理「移除區間」的事件，才不會造成重疊區間斷裂）。
DP 初始狀態（Base Cases）： 動態規劃的狀態轉移前，dp 陣列的初始值設定是否合理？求極小值時有沒有確實初始化為 INF？

五、數值與數學運算除以零與模運算（Modulo）： 
任何除法或取餘數操作，除數有沒有可能是 0？
另外，C++ 的負數取模結果會是負的，遇到減法取模時，必須寫成 (x % M + M) % M 來保證正數。
質數與因數邊界： 判斷質數時，有沒有正確處理 0 和 1 既不是質數也不是合數的特例？
浮點數誤差： 比較兩個浮點數是否相等時，絕對不能直接使用 ==，請使用 abs(A - B) < 1e-9 （或自定義的 epsilon 容差值）來判斷。
*/