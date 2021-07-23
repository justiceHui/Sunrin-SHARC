#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

int N, V[3][111], P[3], D[111][111][111][3];

int rotate(int a, int b){
    int d = abs(a - b) % N;
    return min(d, N-d);
}

int f(int a, int b, int c, int last){
    int &res = D[a][b][c][last];
    if(res != -1) return res;
    if(a == P[0] && b == P[1] && c == P[2]) return res = 0;
    if(a  > P[0] || b  > P[1] || c  > P[2]) return res = INF;

    res = INF;
    int now = array<int,3>{V[0][a], V[1][b]+N/3*2, V[2][c]+N/3}[last];
    res = min(res, f(a+1, b, c, 0) + rotate(now, V[0][a+1]));
    res = min(res, f(a, b+1, c, 1) + rotate(now, V[1][b+1]+N/3*2));
    res = min(res, f(a, b, c+1, 2) + rotate(now, V[2][c+1]+N/3));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<3; i++){
        cin >> P[i];
        for(int j=1; j<=P[i]; j++) cin >> V[i][j], V[i][j]--;
    }
    V[1][0] = N/3;
    V[2][0] = N/3*2;
    memset(D, -1, sizeof D);
    cout << f(0, 0, 0, 0);
}
