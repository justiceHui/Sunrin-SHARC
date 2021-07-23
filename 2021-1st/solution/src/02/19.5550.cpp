#include <bits/stdc++.h>
using namespace std;

int N, K, A[11][2020], ptr[11];
int C[11][2020], D[11][2020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        int c, g; cin >> c >> g;
        A[g][++ptr[g]] = c;
    }
    for(int i=1; i<=10; i++){
        sort(A[i]+1, A[i]+ptr[i]+1, greater<>());
        partial_sum(A[i]+1, A[i]+ptr[i]+1, C[i]+1);
        for(int j=1; j<=ptr[i]; j++) C[i][j] += j * (j - 1);
    }
    for(int i=1; i<=10; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<=j; k++) D[i][j] = max(D[i][j], D[i-1][k] + C[i][j-k]);
        }
    }
    cout << D[10][K];
}
