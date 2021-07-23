#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PII = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;

ll N, A[303030], Lmin[303030], Lmax[303030], Rmin[303030], Rmax[303030];
stack<PII> Smin, Smax;

inline void clear(){
    while(Smin.size()) Smin.pop();
    while(Smax.size()) Smax.pop();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    Smin.emplace(0, 0);
    Smax.emplace(INF, 0);
    for(int i=1; i<=N; i++){
        while(Smin.size() && Smin.top().x >= A[i]) Smin.pop();
        while(Smax.size() && Smax.top().x <= A[i]) Smax.pop();
        Lmin[i] = Smin.top().y + 1;
        Lmax[i] = Smax.top().y + 1;
        Smin.emplace(A[i], i);
        Smax.emplace(A[i], i);
    }

    clear();

    Smin.emplace(0, N+1);
    Smax.emplace(INF, N+1);
    for(int i=N; i>=1; i--){
        while(Smin.size() && Smin.top().x > A[i]) Smin.pop();
        while(Smax.size() && Smax.top().x < A[i]) Smax.pop();
        Rmin[i] = Smin.top().y - 1;
        Rmax[i] = Smax.top().y - 1;
        Smin.emplace(A[i], i);
        Smax.emplace(A[i], i);
    }

    ll ans = 0;
    for(int i=1; i<=N; i++){
        ll minCount = (Rmin[i] - i + 1) * (i - Lmin[i] + 1);
        ll maxCount = (Rmax[i] - i + 1) * (i - Lmax[i] + 1);
        ans += A[i] * (maxCount - minCount);
    }
    cout << ans;
}
