#include <bits/stdc++.h>
using namespace std;

int P[202020];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
void Merge(int u, int v){ if(Find(u) != Find(v)) P[Find(u)] = Find(v); }

int N, Q, G[202020];
int A[404040], B[404040], C[404040];
vector<int> R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q; Q += N-1;
    for(int i=2; i<=N; i++) cin >> G[i];
    for(int i=1; i<=Q; i++){
        cin >> A[i];
        if(A[i] == 0) cin >> B[i];
        else cin >> B[i] >> C[i];
    }

    iota(P+1, P+N+1, 1);
    for(int i=Q; i>=1; i--){
        if(A[i] == 0) Merge(B[i], G[B[i]]);
        else R.push_back(Find(B[i]) == Find(C[i]));
    }

    reverse(R.begin(), R.end());
    for(auto i : R) cout << (i ? "YES" : "NO") << "\n";
}
