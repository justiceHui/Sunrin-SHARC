#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[1010101];

void Solve(){
    priority_queue<ll, vector<ll>, greater<>> pq;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], pq.push(A[i]);

    ll res = 0;
    while(pq.size() > 1){
        ll u = pq.top(); pq.pop();
        ll v = pq.top(); pq.pop();
        res += u + v;
        pq.push(u + v);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++) Solve();
}
