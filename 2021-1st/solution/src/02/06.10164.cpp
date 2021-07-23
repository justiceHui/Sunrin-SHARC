#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K, D[16][16];
int main(){
    cin >> N >> M >> K;
    if(K == 0) K = N * M;
    int y = (K-1) / M + 1, x = (K-1) % M + 1;

    D[1][1] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(i == 1 && j == 1) continue;
            D[i][j] = D[i-1][j] + D[i][j-1];
        }
    }

    cout << D[y][x] * D[N-y+1][M-x+1];
}


/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
__int128_t Fac[30];

ll D(int i, int j){
    return Fac[i+j-2] / Fac[i-1] / Fac[j-1];
}

int main(){
    cin >> N >> M >> K;
    if(K == 0) K = N * M;
    int y = (K-1) / M + 1, x = (K-1) % M + 1;

    Fac[0] = 1;
    for(int i=1; i<=28; i++) Fac[i] = Fac[i-1] * i;

    cout << D(y, x) * D(N-y+1, M-x+1);
}
*/
