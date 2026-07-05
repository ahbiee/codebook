__builtin_popcount(x): 回傳整數 x 轉為二進位後 1 的數量(若處理 long long 需使用
__builtin_popcountll(x)).
__builtin_clz(x): 回傳二進位前導 0 的個數 (Count Leading Zeros).
gcd(a, b), lcm(a, b): 求最大公因數 (C++17 引入,需引入 <numeric>,舊版編譯器可使用內建的 __gcd(a, b)).
string 相關: stoi(s) 將字串轉為 int;
to_string(num) 將數字轉為字串;
s.substr(pos, len) 擷取子字串.

#include <algorithm>

sort(bg, ed) sort(bg, ed, cmp):預設由小到大排序

min(a, b) min(list):取最小值
max(a, b) max(list):取最大值

min_element(first, last):找尋連續資料中最小元素
max_element(first, last):找尋連續資料中最大元素

find(first, last, val):尋找元素.
lower_bound(first, last, val):尋找第一個 ">=" x 的元素"位置"如果不存在, 則回傳 last
upper_bound(first, last, val):尋找第一個 ">" x 的元素"位置", 如果不存在, 則回傳 last 

next_permutation(first, last):將序列順序轉換成下一個字典序, 如果存在回傳 true , 反之回傳 false 
prev_permutation(first, last):將序列順序轉換成上一個字典序, 如果存在回傳 true , 反之回傳 false 

unique(bg, ed):將相鄰重複元素移至尾端, 回傳新陣列無重複部分尾端的 iterator (或指標)
reverse(bg, ed):反轉區間內的元素順序

#include <cctype>

isalnum(int c): 判斷是否為數字或英文
isalpha(int c): 判斷是否為英文
isdigit(int c): 判斷是否為數字

islower(int c): 判斷是否為小寫字母
isupper(int c): 判斷是否為大寫字母

tolower(int c): 將字母轉成小寫字母
toupper(int c): 將字母轉成大寫字母

#include <stack>

s.push(T a) :插入頂端元素, 複雜度 O(1)
s.pop() :刪除頂端元素, 複雜度 O(1)
s.top() :回傳頂端元素, 複雜度 O(1)
s.size() :回傳元素個數, 複雜度 O(1)
s.empty() :回傳是否為空, 複雜度 O(1)

#include <queue>

q.push(T a) :插入尾端元素, 複雜度 O(1)
q.pop() :刪除頂端元素, 複雜度 O(1)
q.front() :回傳頂端元素, 複雜度 O(1)
q.size() :回傳元素個數, 複雜度 O(1)
q.empty() :回傳是否為空, 複雜度 O(1)

pq.push(T a) :插入元素 a, 複雜度 O(logsize)
pq.pop() :刪除頂端元素, 複雜度 O(logsize)
pq.top() :回傳頂端元素, 複雜度 O(1)
pq.size() :回傳元素個數, 複雜度 O(1)
pq.empty() :回傳是否為空, 複雜度 O(1)

#include <deque>

dq.push_front(T a), dq.push_back(T a) :插入頂端/尾端元素, 複雜度 O(1)
dq.pop_front(), dq.pop_back() :刪除頂端/尾端元素, 複雜度 O(1)
dq.front(), dq.back() :回傳頂端/尾端元素, 複雜度 O(1)
dq.size() :回傳元素個數, 複雜度 O(1)
dq.empty() :回傳是否為空, 複雜度 O(1)

#include <set>

s.size() :回傳元素個數, 複雜度 O(1)
s.empty() :回傳是否為空, 複雜度 O(1)
s.clear() :清除元素, 複雜度 O(size)
s.insert(T1 a) :加入元素 a, 複雜度 O(logsize)
s.erase(iterator first,iterator last) :刪除 [first,last), 若沒有指定 last 則只刪除 first
s.erase(T1 a) :刪除鍵值 a, 複雜度 O(logsize)
s.find(T1 a) :回傳指向鍵值 a 的迭代器, 若不存在則回傳 s.end (), 複雜度 O(logsize)
s.count(T a) :計算有幾個元素 a 
s.lower_bound(T1 a) :回傳指向第一個鍵值大於等於 a 的迭代器.複雜度 O(logsize)
s.upper_bound(T1 a) :回傳指向第一個鍵值大於 a 的迭代器.複雜度 O(logsize)

#include <map>

m.size()
m.empty()
m.clear()
m.count()
m.erase(iterator first, iterator last)
m.erase(T1 a)
m.find(T1 a)
m.lower_bound(T1 a)
m.upper_bound(T1 a)