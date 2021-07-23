#include <bits/stdc++.h>
using namespace std;

int N, A[222][222], R[2];

void Solve(int r, int c, int sz){
    if(sz == 1){ R[A[r][c]]++; return; }
    int flag[2] = {0};
    for(int i=r; i<r+sz; i++) for(int j=c; j<c+sz; j++) flag[A[i][j]] = 1;
    if(flag[0] && flag[1]){
        Solve(r, c, sz/2);
        Solve(r+sz/2, c, sz/2);
        Solve(r, c+sz/2, sz/2);
        Solve(r+sz/2, c+sz/2, sz/2);
    }
    else if(flag[0]) R[0]++;
    else R[1]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> A[i][j];
    Solve(1, 1, N);
    cout << R[0] << "\n" << R[1];
}
