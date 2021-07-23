#include <bits/stdc++.h>
using namespace std;

int N, A[1010], D[1010][1010][2];

int f(int i, int j, int turn){
    int &res = D[i][j][turn];
    if(res != -1) return res;
    if(i >= j) return res = (turn ? 0 : A[i]);

    if(turn == 0) res = max(f(i+1, j, 1) + A[i], f(i, j-1, 1) + A[j]);
    else res = min(f(i+1, j, 0), f(i, j-1, 0));
    return res;
}

void Solve(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    memset(D, -1, sizeof D);
    cout << f(1, N, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) Solve();
}
