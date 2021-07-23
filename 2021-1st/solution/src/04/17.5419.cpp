#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;
using PII = pair<int, int>;
constexpr int SZ = 1 << 18;

int N, T[SZ << 1];
PII A[SZ];

void Add(int x){
    x |= SZ; T[x]++;
    while(x >>= 1) T[x]++;
}
int Query(int l, int r){
    l |= SZ; r |= SZ; int ret = 0;
    while(l <= r){
        if(l & 1) ret += T[l++];
        if(~r & 1) ret += T[r--];
        l >>= 1; r >>= 1;
    }
    return ret;
}

void Solve(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].y;
    sort(A+1, A+N+1, [](const PII &a, const PII &b){
        if(a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });
    memset(T, 0, sizeof T);

    vector<int> Y;
    for(int i=1; i<=N; i++) Y.push_back(A[i].y);
    compress(Y);
    for(int i=1; i<=N; i++) A[i].y = IDX(Y, A[i].y) + 1;

    long long ans = 0;
    for(int i=1; i<=N; i++){
        ans += Query(A[i].y, Y.size());
        Add(A[i].y);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    while(TC--) Solve();
}
