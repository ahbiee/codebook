// 座標壓縮: 值很大 (1e9) 但個數少 → 映射到 1..k，之後可開陣列/BIT
vector<ll> vals;
void compress(vector<ll> &a) {
    vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (ll &x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
} // 還原: vals[id - 1]

// pb_ds 平衡樹 (可查名次的 set)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ordered_set os; os.insert(x); os.erase(x);
// *os.find_by_order(k): 第 k 小 (0-based)；os.order_of_key(x): 有幾個 < x
// 要允許重複值: 改存 pair<ll,int>{值, 獨一無二的編號}
