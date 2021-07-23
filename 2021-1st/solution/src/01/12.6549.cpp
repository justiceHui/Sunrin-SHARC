#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PII = pair<int, int>;

ll N, A[101010], L[101010], R[101010];

void Solve(){
    for(int i=1; i<=N; i++) cin >> A[i];

    stack<PII, vector<PII>> stk;
    stk.emplace(-1, 0);
    for(int i=1; i<=N; i++){
        while(stk.top().x >= A[i]) stk.pop();
        L[i] = stk.top().y + 1;
        stk.emplace(A[i], i);
    }
    while(stk.size()) stk.pop();

    stk.emplace(-1, N+1);
    for(int i=N; i>=1; i--){
        while(stk.top().x >= A[i]) stk.pop();
        R[i] = stk.top().y - 1;
        stk.emplace(A[i], i);
    }

    ll ans = 0;
    for(int i=1; i<=N; i++){
        ans = max(ans, A[i] * (R[i] - L[i] + 1));
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(true){
        cin >> N; if(!N) break;
        Solve();
    }
}
