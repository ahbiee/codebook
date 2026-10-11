// <algorithm>
sort(a, a + n); sort(v.begin(), v.end(), greater<int>());  // 自訂: [](auto &x, auto &y){ return ...; }
stable_sort(...);                                          // 相等元素保持原順序
reverse(b, e); unique(b, e);  // unique 前要先 sort，回傳新結尾: v.erase(unique(...), v.end())
lower_bound(b, e, x);  // 第一個 >= x；upper_bound: 第一個 > x (都要已排序)
*min_element(b, e); *max_element(b, e); accumulate(b, e, 0LL); // 注意 0LL 才是 long long
next_permutation(b, e); // 下一個字典序排列，沒有了回傳 false
nth_element(b, b + k, e); // O(N) 把第 k 小放到位置 k
iota(b, e, 0); fill(b, e, x); count(b, e, x); find(b, e, x);
__gcd(a, b); gcd(a, b); lcm(a, b);  // C++17 <numeric>
// <string>
s.substr(pos, len); s.find(t) (找不到 == string::npos); stoi(s); stoll(s); to_string(x);
// stringstream ss(line); while (ss >> word) — 一行內數量不固定時
// string(k, c) = k 個 c (Python 的 c * k)；s += c / s += t 均攤 O(1)；reverse(s.begin(), s.end())
// TLE: s = c + s (插在前面) 和 s = s + c 每次都複製整個字串 O(|s|)，放迴圈裡 = O(N^2)
//   → 只往後 +=，最後再 reverse；或先開 string t(n, ' ')，兩個指標從兩端往中間填
// 迴文重排: 奇數次的字母 <= 1 個 → 左半 + (中間那個) + 反轉左半 (CSES 1755)
// 尾端: s.push_back(c) / s += c 加一個；s.pop_back() 拿掉最後一個 (空字串不可)；s.back() 看最後一個
// s.append(c) 編譯錯誤 → s.append(1, c) 或 s.append(t)；s.erase(pos) 刪 pos 到結尾，s.erase(pos, len)
// 'a' + i 是 int！ s + ('a' + i) 編譯錯誤 → s + char('a' + i)；cout << 'a' + i 會印出數字
// for (const auto &x : v) 不複製；for (string x : v) 每一圈都複製一次
// 容器
// set/map: insert, erase(x), count, find, lower_bound(x), upper_bound(x)，全部 O(log N)
// multiset 只刪一個: ms.erase(ms.find(x))；ms.erase(x) 會刪掉全部的 x
// map 走訪: for (auto &[k, v] : mp)；prev(s.end()) = 最大元素；*s.begin() = 最小
// priority_queue: 預設 max-heap；min-heap: priority_queue<T, vector<T>, greater<T>>
// deque: push_front/back, pop_front/back, 也能 [i]
// bitset<N> b: b.count(), b.set(i), b[i], b << k, b | c — 布林 DP 加速 64 倍
// vector<vector<int>> v(n, vector<int>(m, 0)); v.assign(n, x); v.resize(n);
// tuple: auto [a, b, c] = t; tie(a, b) = p;
