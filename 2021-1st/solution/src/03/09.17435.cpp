#include <bits/stdc++.h>
using namespace std;

int N, Q, T[20][202020];

int Get(int n, int x){
    for(int i=0; n; i++, n>>=1) if(n & 1) x = T[i][x];
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> T[0][i];
    for(int i=1; i<20; i++) for(int j=1; j<=N; j++) T[i][j] = T[i-1][T[i-1][j]];
    cin >> Q;
    while(Q--){
        int n, x; cin >> n >> x;
        cout << Get(n, x) << "\n";
    }
}
