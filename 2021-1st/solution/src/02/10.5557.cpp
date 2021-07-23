#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A[111];
ll D[111][22];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    D[1][A[1]] = 1;
    for(int i=2; i<N; i++){
        for(int j=0; j<=20; j++){
            if(j-A[i] >= 0) D[i][j] += D[i-1][j-A[i]];
            if(j+A[i] <= 20) D[i][j] += D[i-1][j+A[i]];
        }
    }
    cout << D[N-1][A[N]];
}
