#include <bits/stdc++.h>
using namespace std;

int N, R[555], C[555], D[555][555];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> R[i] >> C[i];

    memset(D, 0x3f, sizeof D);
    for(int i=1; i<=N; i++) D[i][i] = 0;
    for(int i=1; i<N; i++) D[i][i+1] = R[i] * C[i] * C[i+1];

    for(int t=2; t<=N; t++){
        for(int i=1; i+t<=N; i++){
            int j = i + t;
            for(int k=i; k<j; k++) D[i][j] = min(D[i][j], D[i][k] + D[k+1][j] + R[i]*C[k]*C[j]);
        }
    }
    cout << D[1][N];
}
