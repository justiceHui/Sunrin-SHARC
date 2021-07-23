#include <bits/stdc++.h>
using namespace std;

int N, A[3], D[66][66][66];

int f(int a, int b, int c){
    int &res = D[a][b][c];
    if(res != -1) return res;
    if(a == 0 && b == 0 && c == 0) return res = 0;

    int damage[3] = {1, 3, 9}, nxt[3];
    res = 0x3f3f3f3f;
    do{
        nxt[0] = max(0, a - damage[0]);
        nxt[1] = max(0, b - damage[1]);
        nxt[2] = max(0, c - damage[2]);
        sort(nxt, nxt+3);
        res = min(res, f(nxt[0], nxt[1], nxt[2]) + 1);
    }while(next_permutation(damage, damage+3));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A, A+3);
    memset(D, -1, sizeof D);
    cout << f(A[0], A[1], A[2]);
}
