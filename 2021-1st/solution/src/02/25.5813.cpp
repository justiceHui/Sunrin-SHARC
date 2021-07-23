#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9;
constexpr int di[] = {1, -1, 0, 0};
constexpr int dj[] = {0, 0, 1, -1};

int N;
PII A[101010];
int S[101010];
vector<int> G[101010];

int getSize(int v, int b=-1){
    for(auto i : G[v]) if(i != b) S[v] += getSize(i, v);
    return S[v];
}

ll Solve(){
    memset(S, 0, sizeof S);
    for(int i=1; i<=N; i++) G[i].clear();
    sort(A+1, A+N+1);

    int pv = 0;
    map<PII, int> mp;
    for(int i=1; i<=N; i++){
        if(i != 1 && A[i-1].x == A[i].x && A[i-1].y+1 == A[i].y) mp[A[i]] = pv;
        else mp[A[i]] = ++pv;
        S[pv]++;
    }

    for(int i=1; i<=N; i++){
        int now = mp[A[i]];
        for(int k=0; k<4; k++){
            int nxt = mp[{A[i].x+di[k], A[i].y+dj[k]}];
            if(nxt && now != nxt) G[now].push_back(nxt);
        }
    }
    for(int i=1; i<=pv; i++) compress(G[i]);

    getSize(1);
    ll ret = 0;
    for(int i=1; i<=N; i++) ret += 1LL * S[i] * (N - S[i]) % MOD;
    return ret % MOD;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    ll ans = 0;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].y;
    ans += Solve();
    for(int i=1; i<=N; i++) swap(A[i].x, A[i].y);
    ans += Solve();
    if(ans >= MOD) ans -= MOD;
    cout << ans;
}
