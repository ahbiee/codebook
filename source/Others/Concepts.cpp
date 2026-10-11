/* 位元技巧
   x & -x: 最低位的 1；x & (x-1): 去掉最低位的 1；__builtin_popcountll(x): 1 的個數
   __builtin_ctzll(x): 結尾 0 的個數；63 - __builtin_clzll(x) (= __lg(x)): 最高位的位置
   a ^ b ^ b = a；a + b = (a ^ b) + 2 * (a & b)
   只差一個 bit: x = a ^ b; x && !(x & (x - 1)) 或 __builtin_popcount(a ^ b) == 1 (「XOR 是偶數」不對)
   優先順序: & ^ | 比 == 還低！ a ^ b == 0 會變成 a ^ (b == 0)；% 比 ^ 高。位元運算一律加括號
   Gray code (2^n 個、相鄰只差 1 bit): 第 i 個 = i ^ (i >> 1)；印 n 位: bitset<16>(g).to_string().substr(16 - n)
     建構: G(n) = 「0 + G(n-1)」接「1 + G(n-1) 整串順序倒過來」(是倒序，不是每個 bit 翻轉)
   數學小技巧
   ceil(a / b) (a,b > 0) = (a + b - 1) / b；負數取模: ((a % m) + m) % m
   排序比較 a/b < c/d → a*d < c*b (b,d > 0，注意溢位)
   long double 精度約 18 位；sqrt 整數: ll r = sqrtl(x); while (r*r > x) r--; while ((r+1)*(r+1) <= x) r++;
   隨機: mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); shuffle(v.begin(), v.end(), rng);
*/
