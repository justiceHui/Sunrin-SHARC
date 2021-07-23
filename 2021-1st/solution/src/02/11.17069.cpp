#include <bits/stdcd++.h>
using namespace std;
using ll = long long;

int N, A[55][55];
ll D[55][55][3]; // - | \

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> A[i][j];

    D[1][2][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(A[i][j]) continue;
            D[i][j][0] += D[i][j-1][0] + D[i][j-1][2];
            D[i][j][1] += D[i-1][j][1] + D[i-1][j][2];
            if(!A[i-1][j] && !A[i][j-1]){
                D[i][j][2] += D[i-1][j-1][0] + D[i-1][j-1][1] + D[i-1][j-1][2];
            }
        }
    }
    cout << D[N][N][0] + D[N][N][1] + D[N][N][2];
}
