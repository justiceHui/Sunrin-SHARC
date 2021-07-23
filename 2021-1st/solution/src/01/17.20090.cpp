#include "aliens.h"
#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

inline ll sq(ll v){ return v*v; }

struct Line{
    ll a, b, i;
    Line() : Line(0, INF, 0) {}
    Line(ll a, ll b, ll i) : a(a), b(b), i(i) {}
    ll f(ll x) const { return a * x + b; }
};

struct CHT{
    Line v[101010]; int pv, top;
    void clear(){ pv = top = 0; }
    int __cross(const Line &a, const Line &b, const Line &c){
        return (a.b - b.b) * (b.a - c.a) <= (c.b - b.b) * (b.a - a.a);
    }
    void update(Line l){
        while(top >= pv+2 && __cross(v[top-2], v[top-1], l)) top--;
        v[top++] = l;
    }
    PLL query(ll x){
        while(pv+1 < top && v[pv].f(x) >= v[pv+1].f(x)) pv++;
        return {v[pv].f(x), v[pv].i};
    }
} cht;

int N, K;
PLL A[101010];
ll D[101010], C[101010];

void init(int _n, int _m, int _k, const vector<int> &_r, const vector<int> &_c){
    K = _k;
    vector<PLL> pts;
    for(int i=0; i<_n; i++) pts.emplace_back(min(_r[i], _c[i]), max(_r[i], _c[i]));
    sort(all(pts), [&](const PLL &p1, const PLL &p2){
        return p1.x != p2.x ? p1.x < p2.x : p1.y > p2.y;
    });
    for(const auto &i : pts) if(!N || A[N].y < i.y) A[++N] = i;
}

Line makeLine(int i){
    ll a = -2*A[i+1].x, b = D[i] + sq(A[i+1].x) - 2*A[i+1].x;
    if(i) b -= sq(max(0LL, A[i].y-A[i+1].x+1));
    return {a, b, i};
}

ll get(ll c){
    cht.clear();
    cht.update(makeLine(0));
    for(int i=1; i<=N; i++){
        auto res = cht.query(A[i].y);
        D[i] = res.x + sq(A[i].y+1) + c;
        C[i] = C[res.y] + 1;
        cht.update(makeLine(i));
    }
    return C[N];
}

ll take_photos(int _n, int _m, int _k, vector<int> _r, vector<int> _c){
    init(_n, _m, _k, _r, _c);
    K = min(N, K);

    ll l = 0, r = 1e15, ans = 0;
    while(l <= r){
        ll m = l + r >> 1, cnt = get(m);
        if(cnt == K) return D[N] - K*m;
        else if(cnt < K) r = m - 1;
        else l = m + 1, ans = max(ans, D[N] - K*m);
    }
    return ans;
}
