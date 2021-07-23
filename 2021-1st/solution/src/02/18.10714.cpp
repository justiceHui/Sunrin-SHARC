#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A[2020];
ll D[2020][2020];

int next(int v){ return (v + 1) % N; }
int prev(int v){ return (v + N - 1) % N; }

ll f(int l, int r, int turn){
    if(turn == 0){ // IOI
        if(next(r) == l) return 0;
        if(A[prev(l)] > A[next(r)]) return f(prev(l), r, 1);
        else return f(l, next(r), 1);
    }

    ll &res = D[l][r];
    if(res != -1) return res;
    if(next(r) == l) return res = 0;

    ll t1 = f(prev(l), r, 0) + A[prev(l)];
    ll t2 = f(l, next(r), 0) + A[next(r)];
    return res = max(t1, t2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    ll ans = 0;
    memset(D, -1, sizeof D);
    for(int i=0; i<N; i++) ans = max(ans, f(i, i, 0) + A[i]);
    cout <<ans;
}
