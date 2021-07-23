#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, M;
ll D[1010][1010][2];
ll Pos[1010], Pow[1010], Sum[1010];

ll range_sum(int l, int r){
    return Sum[r] - Sum[l-1];
}

ll f(int l, int r, int flag){
    ll &res = D[l][r][flag];
    if(res != -1) return res;
    if(l == 1 && r == N) return res = 0;
    res = 0x3f3f3f3f3f3f3f3f;

    int now = flag ? r : l;
    ll power_on = range_sum(1, l-1) + range_sum(r+1, N);
    if(l > 1) res = min(res, f(l-1, r, 0) + (Pos[now] - Pos[l-1]) * power_on);
    if(r < N) res = min(res, f(l, r+1, 1) + (Pos[r+1] - Pos[now]) * power_on);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> Pos[i] >> Pow[i];
    partial_sum(Pow+1, Pow+N+1, Sum+1);

    memset(D, -1, sizeof D);
    cout << f(M, M, 0);
}
