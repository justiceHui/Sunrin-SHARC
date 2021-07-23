#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, A[10101];

bool f(ll v){
    ll sum = 0;
    for(int i=1; i<=N; i++){
        sum += min(A[i], v);
    }
    return sum <= K;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    cin >> K;
    if(accumulate(A+1, A+N+1, 0LL) <= K){
        cout << *max_element(A+1, A+N+1);
        return 0;
    }
    ll l = 0, r = 2e9;
    while(l < r){
        ll m = l + r + 1 >> 1;
        if(f(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}
