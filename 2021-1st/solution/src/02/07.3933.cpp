#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 1 << 15;

int D[SZ][5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=1; i*i<SZ; i++){
        D[i*i][1] = 1;
        for(int j=1; j+i*i<SZ; j++){
            D[j+i*i][2] += D[j][1];
            D[j+i*i][3] += D[j][2];
            D[j+i*i][4] += D[j][3];
        }
    }

    while(true){
        int N; cin >> N; if(!N) break;
        cout << D[N][1] + D[N][2] + D[N][3] + D[N][4] << "\n";
    }
}
