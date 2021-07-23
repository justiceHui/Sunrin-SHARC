#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, X, K;
bool Use[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> X;
    K = (N - 1) * (N - 2) / 2;
    if(X > K){ cout << -1; return 0; }
    K -= X;
    memset(Use, true, sizeof Use);
    for(int i=1; i<=N-2; i++){
        if(K >= N-i-1) K -= N-i-1, Use[i] = false;
    }
    cout << N << " ";
    for(int i=1; i<=N-2; i++) if(Use[i]) cout << i << " ";
    cout << N - 1 << " ";
    for(int i=N-2; i>=1; i--) if(!Use[i]) cout << i << " ";
}
