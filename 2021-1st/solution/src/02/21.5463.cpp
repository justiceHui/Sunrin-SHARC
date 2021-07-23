#include <bits/stdc++.h>
using namespace std;

int N, M, A[55][55], D[55][55][55][55];

int f(int r1, int c1, int r2, int c2){
    int &res = D[r1][c1][r2][c2];
    if(res != -1) return res;
    if(r1 == r2 && c1 == c2) return res = 0;

    res = 0x3f3f3f3f;
    for(int i=r1; i<r2; i++) res = min(res, f(r1, c1, i, c2) + f(i+1, c1, r2, c2));
    for(int j=c1; j<c2; j++) res = min(res, f(r1, c1, r2, j) + f(r1, j+1, r2, c2));
    res += A[r2][c2] - A[r2][c1-1] - A[r1-1][c2] + A[r1-1][c1-1];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> A[i][j];
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
    memset(D, -1, sizeof D);
    cout << f(1, 1, N, M);
}
