#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 12;

struct Point{
    ll x, y, w;
    bool operator < (const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

struct Node{
    ll l, r, mx, sum;
    Node() : Node(0) {}
    Node(ll v) : l(v), r(v), mx(v), sum(v) {}
    void set(ll v){ l = r = mx = sum = v; }
    void add(ll v){ l += v; r += v; mx += v; sum += v; }
    Node operator + (const Node &t) const {
        Node ret;
        ret.l = max(l, sum + t.l);
        ret.r = max(r + t.sum, t.r);
        ret.mx = max({ mx, t.mx, r + t.l });
        ret.sum = sum + t.sum;
        return ret;
    }
} T[SZ << 1];

void Init(){
    for(int i=0; i<(SZ<<1); i++) T[i].set(0);
}

void Update(int x, ll v){
    x |= SZ; T[x].add(v);
    while(x >>= 1) T[x] = T[x << 1] + T[x << 1 | 1];
}

int N;
Point A[3030];
vector<int> X, Y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i].x >> A[i].y >> A[i].w;
        X.push_back(A[i].x); Y.push_back(A[i].y);
    }
    compress(X); compress(Y);
    for(int i=1; i<=N; i++){
        A[i].x = IDX(X, A[i].x) + 1;
        A[i].y = IDX(Y, A[i].y) + 1;
    }
    sort(A+1, A+N+1);

    ll mx = 0;
    for(int i=1; i<=N; i++){
        if(i > 1 && A[i-1].x == A[i].x) continue;
        Init();
        for(int j=i; j<=N; j++){
            Update(A[j].y, A[j].w);
            if(j == N || A[j].x != A[j+1].x) mx = max(mx, T[1].mx);
        }
    }
    cout << mx;
}
