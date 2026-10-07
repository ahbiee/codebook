// 最近點對 (距離平方)，整數座標，分治 O(N log N)。pts 會被排序
typedef pair<ll, ll> PL;
ll sq(ll x) { return x * x; }
ll closest_rec(vector<PL> &p, int l, int r) { // [l, r)，p 依 x 排序；結束時 [l,r) 依 y 排序
    if (r - l <= 3) {
        ll best = LLONG_MAX;
        for (int i = l; i < r; i++) for (int j = i + 1; j < r; j++)
            best = min(best, sq(p[i].first - p[j].first) + sq(p[i].second - p[j].second));
        sort(p.begin() + l, p.begin() + r, [](const PL &a, const PL &b) { return a.second < b.second; });
        return best;
    }
    int m = (l + r) / 2;
    ll midx = p[m].first;
    ll d = min(closest_rec(p, l, m), closest_rec(p, m, r));
    inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r, [](const PL &a, const PL &b) { return a.second < b.second; });
    vector<PL> strip; // 離中線 < sqrt(d) 的點，依 y 排好
    for (int i = l; i < r; i++) {
        if (sq(p[i].first - midx) >= d) continue;
        for (int j = (int)strip.size() - 1; j >= 0 && sq(p[i].second - strip[j].second) < d; j--)
            d = min(d, sq(p[i].first - strip[j].first) + sq(p[i].second - strip[j].second));
        strip.push_back(p[i]);
    }
    return d;
}
ll closest_pair(vector<PL> pts) { sort(pts.begin(), pts.end()); return closest_rec(pts, 0, pts.size()); }
