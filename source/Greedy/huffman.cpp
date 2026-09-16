/*
題意：有一個array，你需要用最小的cost將所有的數值加起來，並輸出和的最低cost
題解：使用Min Heap，每次挑選最小的兩堆做合併，直到全部合併成一堆
*/

long long huffmanCost(const vector<int>& weights) {
    priority_queue<long long, vector<long long>, greater<long long>> pq; // Min-Heap
    for (int w : weights) pq.push(w); // 把所有已有資料推到pq中
    long long total_cost = 0; // 最後要return的最小cost
    
    while (pq.size() > 1) { // 只要還能合併，就一直重複到合併為一堆
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        long long merged = first + second;
        total_cost += merged;
        pq.push(merged); // 將合併後的新重量塞回 Heap
    }

    return total_cost;
}

/*
題意：給定一個字串，請用 Huffman Coding 的方式將字串編碼為 只包含0, 1的字串
題解：最小(或最少見)放右邊(1)，大(或最常見)的放左邊(0)
*/
const int MAXN = 515; // ASCII = 256, MAXN 開的比 256*2多一點

struct Node {
    char ch; // 該節點的字元
    int freq; // 出現頻率(次數)
    int left, right; // 樹的左、右節點 (用index取代pointer)，-1 表示 nullptr
} pool[MAXN]; // 先開好大小 MAXN 的樹

int node_cnt = 0; // 一個全域變數，紀錄目前樹開到哪

// 建立新節點的函式，回傳該節點在 pool 中的 index
int newNode(char ch, int freq, int l = -1, int r = -1) {
    pool[node_cnt].ch = ch;
    pool[node_cnt].freq = freq;
    pool[node_cnt].left = l;
    pool[node_cnt].right = r;
    return node_cnt++;
}

// 用於排序 Heap 的 compare function
struct compare {
    bool operator()(int l, int r) { return pool[l].freq > pool[r].freq; }
};

// 輸出 Huffman Code 的 Recursion Function
void printCodes(int u, string str, unordered_map<char, string>& huffmanCode){
    if (u == -1) return;

    // 如果沒有子節點，那就紀錄目前字元所對應的string
    if (pool[u].left == -1 && pool[u].right == -1) {
        huffmanCode[pool[u].ch] = str;
        return;
    }

    printCodes(pool[u].left, str + "0", huffmanCode);
    printCodes(pool[u].right, str + "1", huffmanCode);
}

// build function
void buildHuffmanTree(string text)
{
    if(text.empty()) return;

    node_cnt = 0; // 每筆測資都要重置node_cnt
    
    unordered_map<char, int> freq; // 紀錄<字元, 出現次數>的map
    for (char ch : text) freq[ch]++; // 遍歷 text，新增freq

    // 建立 Huffman Tree 的 pq，使用自訂的Node跟compare function
    priority_queue<int, vector<int>, compare> pq;

    // 將每一個字元建立成獨立的子節點(pair=<字元, 出現次數>) 並放到樹中
    for (auto pair : freq) pq.push(newNode(pair.first, pair.second));
    
    if(pq.size() == 1) pq.push(newNode('\0', 0)); // 如果只有一個字元("AAAA")，需要給一個dummy node，否則無法產生路徑

    while (pq.size() > 1) { // 一直重複做到全部合併成一堆
        int left = pq.top(); pq.pop();
        int right = pq.top(); pq.pop(); // 拿出頂端(頻率最低)的兩個node做合併

        // 建立一個中間節點以取代這兩點，使用空字元表示這個字不在原始字串中
        int sum = pool[left].freq + pool[right].freq;
        pq.push(newNode('\0', sum, left, right));
    }

    int root = pq.top(); // 現在全部合併成一堆，用root來當樹根(最頂端)的index

    // 遍歷這棵樹，把對應的code存到另一個map中
    unordered_map<char, string> huffmanCode; // 如果想在輸出時對應到字元順序(A, B, C)，可以改為一般的map
    printCodes(root, "", huffmanCode); // 從root開始，對應的編碼是 "" (empty string)，用後面的map來記

    // --- 以下為輸出與測試驗證 ---
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        // 只印出有出現在原字串中的字元編碼 (排除 Dummy Node)
        if (freq.count(pair.first)) {
            cout << pair.first << " : " << pair.second << "\n";
        }
    }

    string encodedStr = "";
    for (char ch : text) encodedStr += huffmanCode[ch];
    cout << "\nOriginal string: " << text << "\n";
    cout << "Encoded string: " << encodedStr << "\n";

    // 解碼用的 Lambda Function
    auto decode = [&](string str) { // [&]表示把這個function內的(外部)變數拿來用
        string decoded = "";
        int curr = root;
        for (char bit : str) {
            if (bit == '0') curr = pool[curr].left;
            else curr = pool[curr].right;

            // 走到葉子節點
            if (pool[curr].left == -1 && pool[curr].right == -1) {
                decoded += pool[curr].ch;
                curr = root; // 回到樹根準備解下一個字
            }
        }
        return decoded;
    };

    cout << "Decoded string: " << decode(encodedStr) << "\n\n";
}

int main()
{
    // 測試一般測資
    cout << "=== Test 1: Normal Case ===\n";
    buildHuffmanTree("HUFFMAN");

    // 測試 Edge Case (只有單一字元)
    cout << "=== Test 2: Edge Case (Single Character) ===\n";
    buildHuffmanTree("AAAAAAA");
    return 0;
}
