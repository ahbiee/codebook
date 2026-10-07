// unordered_map 被惡意測資卡成 O(N) 時 (Codeforces 常見)，換成隨機化的 hash
uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
const uint64_t RND = chrono::steady_clock::now().time_since_epoch().count();
auto safe_hash = [](uint64_t x) { return splitmix64(x + RND); };
unordered_map<ll, int, decltype(safe_hash)> mp(1 << 16, safe_hash);
unordered_set<ll, decltype(safe_hash)> st_(1 << 16, safe_hash);
// pair 當 key: 合成一個 ll，例如 (ll)a * 1000000007 + b，或直接用 map (O(log N) 通常也夠)
// 加速: mp.reserve(1 << 20); mp.max_load_factor(0.25);
