#include <bits/stdc++.h>
using namespace std;

int P[101010];
set<int> S[101010];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
void Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(S[u].size() > S[v].size()) swap(u, v);
    for(auto i : S[u]) S[v].insert(i); S[u].clear();
    P[u] = v;
}

int N, Q, G[101010], A[1110101], B[1110101];
vector<int> R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q; Q += N-1;
    for(int i=2; i<=N; i++) cin >> G[i];
    for(int i=1,t; i<=N; i++) cin >> t, S[i].insert(t);

    iota(P+1, P+N+1, 1);
    for(int i=1; i<=Q; i++) cin >> A[i] >> B[i];
    for(int i=Q; i>=1; i--){
        if(A[i] == 1) Merge(B[i], G[B[i]]);
        else R.push_back(S[Find(B[i])].size());
    }
    reverse(R.begin(), R.end());
    for(auto i : R) cout << i << "\n";
}
