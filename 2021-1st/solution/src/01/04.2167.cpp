#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[333][333], S[333][333];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> A[i][j];
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
    }
    cin >> K;
    while(K--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1] << "\n";
    }
}
