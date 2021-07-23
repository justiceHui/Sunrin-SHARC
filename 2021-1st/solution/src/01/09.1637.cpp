#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[20202], B[20202], C[20202];

ll f(ll x){
    ll sum = 0;
    for(int i=1; i<=N; i++){
        if(x >= A[i]) sum += (min(x, B[i]) - A[i]) / C[i] + 1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i];

    ll l = 0, r = 1LL << 32;
    while(l < r){
        ll m = l + r >> 1;
        if(f(m) & 1) r = m;
        else l = m + 1;
    }
    if(f(r) & 1) cout << r << " " << f(r) - f(r-1);
    else cout << "NOTHING";
}
