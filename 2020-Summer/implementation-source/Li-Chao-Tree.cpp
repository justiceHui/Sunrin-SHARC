struct Line{
    ll a, b;
    Line() : a(0), b(1e18) {}
    Line(ll a, ll b) : a(a), b(b) {}
    ll f(ll x){ return a*x+b; }
};
struct Node{
    int l, r; Line v;
    Node() : l(-1), r(-1) {}
};
vector<Node> tree;

void update(int node, ll s, ll e, Line v){
    Line lo = tree[node].v, hi = v;
    if(lo.f(s) > hi.f(s)) swap(lo, hi);
    if(lo.f(e) <= hi.f(e)){ tree[node].v = lo; return; }
    ll m = s + e >> 1;
    if(lo.f(m) < hi.f(m)){
        tree[node].v = lo;
        if(tree[node].r == -1) tree[node].r = tree.size(), tree.emplace_back();
        update(tree[node].r, m+1, e, hi);
    }
    else{
        tree[node].v = hi;
        if(tree[node].l == -1) tree[node].l = tree.size(), tree.emplace_back();
        update(tree[node].l, s, m, lo);
    }
}

ll query(int node, ll s, ll e, ll x){
    if(node == -1) return 1e18;
    ll res = tree[node].v.f(x), m = s + e >> 1;
    if(x <= m) return min(res, query(tree[node].l, s, m, x));
    else return min(res, query(tree[node].r, m+1, e, x));
}

void useExample(){
    const ll INF = 1e12;
    auto init = [&](){ tree.clear(); tree.emplace_back(); };
    init();
    for(int i=1; i<=n; i++){
        update(0, -INF, INF, Line(a[i], b[i])); // insert y = ax+b
        cout << query(0, -INF, INF, 998244353) << "\n";
    }
}