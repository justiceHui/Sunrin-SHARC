#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
constexpr ll MOD = 40'000;

int N;
PLL A[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].y;
    sort(A+1, A+N+1, [](PLL p1, PLL p2){
        if(p1 == PLL(0,0)) return false;
        if(p2 == PLL(0,0)) return true;
        ll p12 = p1.y * p2.x, p21 = p2.y * p1.x;
        return p12 < p21;
    });

    ll ans = 0, ti = 0;
    for(int i=1; i<=N; i++){
        ans = (ans + A[i].x * ti + A[i].y) % MOD;
        ti = ans;
    }
    cout << ans;
}
