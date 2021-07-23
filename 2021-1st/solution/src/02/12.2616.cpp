#include <bits/stdc++.h>
using namespace std;

int N, K, A[50505], D[4][50505], mx;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    cin >> K;
    partial_sum(A+1, A+N+1, A+1);
    for(int i=1; i<=3; i++){
        for(int j=i*K; j<=N; j++){
            D[i][j] = max(D[i][j-1], D[i-1][j-K] + A[j] - A[j-K]);
            mx = max(mx, D[i][j]);
        }
    }
    cout << mx;
}
