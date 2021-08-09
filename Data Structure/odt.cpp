
template <typename T> struct Chtholly_Tree {
    struct Node {
        mutable int l, r;
        mutable T v;
        bool operator<(const Node &b) const { return l < b.l; }
    };
    set<Node> S;
    typedef typename set<Node>::iterator Iter;
    void init(int l, int r, T v) { S = {{l, r + 1, v}}; }
    Iter split(int x){
        Iter it = S.lower_bound({x});
        if (it != S.end() && it->l == x) { return it; }
        --it; Iter re = S.insert({x, it->r, it->v}).first;
        it->r = x - 1; return re;
    }
    void update(int l, int r, T i) {
        auto it = split(l), ed = split(r + 1);
        vector<Iter> vc;
        for (; it != ed; ++it) {
            vc.push_back(it);
            int j = it->v;
            if (j == i) continue;
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        for (auto it : vc) S.erase(it);
        S.insert({l, r, i});
    }
};
