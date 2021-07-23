#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[101010];

ll f(ll m){
    ll ret = 0;
    for(int i=0; i<N; i++) ret += abs(A[i] - i*m);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=N-1; ~i; i--) A[i] -= A[0];
    A[0] = 0;

    ll l = 0, r = 1e9;
    while(l+3 <= r){
        ll m1 = (l + l + r) / 3, m2 = (l + r + r) / 3;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(ll i=l; i<=r; i++) ans = min(ans, f(i));
    cout << ans;
}
