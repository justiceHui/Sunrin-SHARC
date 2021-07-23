#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Info{
    ll a, b, idx;
    Info() : a(0), b(0), idx(0) {}
    bool operator < (const Info &t) const {
        ll le = b - a, ri = t.b - t.a;
        if(le >= 0 && ri < 0) return true;
        if(le < 0 && ri >= 0) return false;
        if(le < 0 && ri < 0) return b > t.b;
        if(le >= 0 && ri >= 0) return a < t.a;
        return idx < t.idx;
    }
    Info& operator += (const Info &t){
        ll down = min(-a, -a + b - t.a);
        ll final = -a + b - t.a + t.b;
        this->a = -down;
        this->b = final - down;
        return *this;
    }
};

int N;
Info A[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].a >> A[i].b, A[i].idx = i;
    sort(A+1, A+N+1);

    Info res;
    for(int i=1; i<=N; i++) res += A[i];
    cout << res.a;
}
