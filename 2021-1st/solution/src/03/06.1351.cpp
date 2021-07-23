#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, P, Q;
map<ll, ll> D;

ll f(ll x){
    if(x == 0) return 1;
    if(D.find(x) != D.end()) return D[x];
    return D[x] = f(x/P) + f(x/Q);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> P >> Q;
    cout << f(N);
}
