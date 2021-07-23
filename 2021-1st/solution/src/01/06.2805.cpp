#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, A[1010101];

bool f(ll v){
    ll sum = 0;
    for(int i=1; i<=N; i++){
        if(A[i] > v) sum += A[i] - v;
    }
    return sum >= K;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    ll l = 0, r = 2e9;
    while(l < r){
        ll m = l + r + 1 >> 1;
        if(f(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}
