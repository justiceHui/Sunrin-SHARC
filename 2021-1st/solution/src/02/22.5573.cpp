#include <bits/stdc++.h>
using namespace std;
constexpr int di[] = {1, 0}; // down, right
constexpr int dj[] = {0, 1}; // down, right

int H, W, N, A[1010][1010], D[1010][1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> H >> W >> N;
    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) cin >> A[i][j];
    D[1][1] = N - 1;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            int flag = A[i][j];
            D[i+di[flag]][j+dj[flag]] += (D[i][j] + 1) / 2;
            D[i+di[flag^1]][j+dj[flag^1]] += D[i][j] / 2;
            if(D[i][j] & 1) A[i][j] ^= 1;
        }
    }
    int i = 1, j = 1;
    while(i <= H && j <= W){
        i += di[A[i][j]];
        j += dj[A[i][j]];
    }
    cout << i << " " << j;
}
