#include <bits/stdc++.h>
using namespace std;

int P[222];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
void Union(int u, int v){ if(Find(u) != Find(v)) P[Find(u)] = Find(v); }

int N, M, A[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    iota(P+1, P+N+1, 1); // for(int i=1; i<=N; i++) P[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int v; cin >> v;
            if(v == 1) Union(i, j);
        }
    }
    for(int i=1; i<=M; i++) cin >> A[i];

    bool flag = true;
    for(int i=2; i<=M; i++) if(Find(A[i-1]) != Find(A[i])) flag = false;
    if(flag) cout << "YES";
    else cout << "NO";
}
