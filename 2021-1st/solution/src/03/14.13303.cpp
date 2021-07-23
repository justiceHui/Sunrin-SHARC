#include <bits/stdc++.H>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

struct Hurdle{
    int x, s, e;
    bool operator < (const Hurdle &hurdle) const { return x < hurdle.x; }
};

int N, SY, EX;
Hurdle A[101010];
ll D[2020202], R = INF;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> SY >> EX;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].s >> A[i].e;
    sort(A+1, A+N+1);

    set<int> S;
    memset(D, 0x3f, sizeof D);
    S.insert(SY); D[SY] = 0;

    for(int i=1; i<=N; i++){
        int s = A[i].s, e = A[i].e;
        for(auto it=S.upper_bound(s); it!=S.end() && *it<e; it=S.erase(it)){
            D[s] = min(D[s], D[*it] + *it - s);
            D[e] = min(D[e], D[*it] + e - *it);
            D[*it] = INF; // erase
        }
        if(D[s] != INF) S.insert(s);
        if(D[e] != INF) S.insert(e);
    }

    for(auto i : S) R = min(R, D[i] + EX);
    cout << R << "\n";

    vector<int> V;
    for(auto i : S) if(D[i]+EX == R) V.push_back(i);
    cout << V.size() << " ";
    for(auto i : V) cout << i << " ";
}
