// 點/向量用 pair 表示 (.first = x, .second = y)。座標全是整數時把 ld 改成 ll，完全沒有誤差
typedef long double ld;
typedef pair<ld, ld> P;
const ld EPS = 1e-9, PI = acosl(-1);
int sign(ld x) { return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1); } // 浮點數比較一律用 sign
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }
P operator*(P a, ld k) { return {a.first * k, a.second * k}; }
P operator/(P a, ld k) { return {a.first / k, a.second / k}; }
ld dot(P a, P b) { return a.first * b.first + a.second * b.second; }   // > 0 銳角, = 0 垂直, < 0 鈍角
ld cross(P a, P b) { return a.first * b.second - a.second * b.first; } // > 0: b 在 a 的逆時針側 (左邊)
ld cross(P o, P a, P b) { return cross(a - o, b - o); }                 // o→a→b: > 0 左轉, < 0 右轉, = 0 共線
ld len(P a) { return sqrtl(dot(a, a)); }
bool same(P a, P b) { return sign(a.first - b.first) == 0 && sign(a.second - b.second) == 0; }
P rotate(P a, ld th) { return {a.first * cosl(th) - a.second * sinl(th), a.first * sinl(th) + a.second * cosl(th)}; } // 逆時針
ld angle(P a) { return atan2l(a.second, a.first); } // (-PI, PI]
// 極角排序: sort(v.begin(), v.end(), [](P a, P b){ return angle(a) < angle(b); });
