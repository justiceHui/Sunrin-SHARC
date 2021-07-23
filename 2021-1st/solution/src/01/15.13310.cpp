#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Point = pair<ll, ll>;
constexpr Point O = {0, 0};

struct Star{
    ll x, y, dx, dy;
    Point get(ll t) const { return {x + dx*t, y + dy*t}; }
};

int CCW(const Point &p1, const Point &p2, const Point &p3){
    ll res = (p2.x-p1.x)*(p3.y-p2.y) - (p3.x-p2.x)*(p2.y-p1.y);
    return (res > 0) - (res < 0);
}
ll D2(const Point &p1, const Point &p2){
    return (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y);
}

vector<Point> ConvexHull(vector<Point> &V){
    vector<Point> H;
    swap(V[0], *min_element(all(V)));
    sort(1+all(V), [&](const Point &a, const Point &b){
        if(int cw = CCW(V[0], a, b); cw) return cw > 0;
        return D2(V[0], a) < D2(V[0], b);
    });
    for(const auto &i : V){
        while(H.size() >= 2 && CCW(H[H.size()-2], H.back(), i) <= 0) H.pop_back();
        H.push_back(i);
    }
    return move(H);
}

pair<Point, Point> RotatingCalipers(const vector<Point> &H){
    auto Check = [&](Point s1, Point e1, Point s2, Point e2){
        Point p1 = {e1.x-s1.x, e1.y-s1.y};
        Point p2 = {e2.x-s2.x, e2.y-s2.y};
        return CCW(O, p1, p2) >= 0;
    };
    ll mx = 0; Point a, b;
    for(int i=0, j=0; i<H.size(); i++){
        while(j+1 < H.size() && Check(H[i], H[i+1], H[j], H[j+1])){
            if(ll now = D2(H[i], H[j]); mx < now) mx = now, a = H[i], b = H[j];
            j++;
        }
        if(ll now = D2(H[i], H[j]); mx < now) mx = now, a = H[i], b = H[j];
    }
    return {a, b};
}

ll N, T;
vector<Star> V;

ll f(ll t){
    vector<Point> P; P.reserve(N);
    for(const auto &i : V) P.push_back(i.get(t));
    auto [a,b] = RotatingCalipers(ConvexHull(P));
    return D2(a, b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> T; V.resize(N);
    for(auto &i : V) cin >> i.x >> i.y >> i.dx >> i.dy;

    ll l = 0, r = T;
    while(l+3 <= r){
        ll m1 = (l + l + r) / 3, m2 = (l + r + r) / 3;
        if(f(m1) > f(m2)) l = m1;
        else r = m2;
    }

    ll mn = 0x3f3f3f3f3f3f3f3f, idx = l;
    for(ll i=l; i<=r; i++){
        if(ll now = f(i); mn > now) mn = now, idx = i;
    }
    cout << idx << "\n" << mn;
}
