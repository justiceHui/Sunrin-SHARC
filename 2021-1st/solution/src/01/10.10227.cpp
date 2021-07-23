#include <bits/stdc++.h>
using namespace std;

int N, M, H, W, A[3030][3030], T[3030][3030];

void Init(int X){
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        if(A[i][j] > X) T[i][j] = 1;
        else if(A[i][j] < X) T[i][j] = -1;
        else T[i][j] = 0;
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        T[i][j] += T[i-1][j] + T[i][j-1] - T[i-1][j-1];
    }
}

int Query(int r1, int r2, int c1, int c2){
    return T[r2][c2] - T[r2][c1-1] - T[r1-1][c2] + T[r1-1][c1-1];
}

bool f(int X){
    Init(X);
    for(int i=1; i<=N; i++) if(i+H-1 <= N) {
        for(int j=1; j<=M; j++) if(j+W-1 <= M) {
            if(Query(i, i+H-1, j, j+W-1) <= 0) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> H >> W;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> A[i][j];
    int l = 0, r = 3030*3030;
    while(l < r){
        int m = l + r >> 1;
        if(f(m)) r = m;
        else l = m + 1;
    }
    cout << r;
}
