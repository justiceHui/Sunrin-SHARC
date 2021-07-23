#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[101010];

ll Solve(int s, int e){
    if(s > e) return 0;
    int m = s + e >> 1;
    int l = m, r = m;
    ll now = A[m], h = A[m];
    while(l > s && r < e){
        if(min(h, A[l-1]) > min(h, A[r+1])) h = min(h, A[--l]);
        else h = min(h, A[++r]);
        now = max(now, h * (r-l+1));
    }
    while(l > s) h = min(h, A[--l]), now = max(now, h * (r-l+1));
    while(r < e) h = min(h, A[++r]), now = max(now, h * (r-l+1));
    return max({ now, Solve(s, m-1), Solve(m+1, e) });
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; for(int i=1; i<=N; i++) cin >> A[i];
    cout << Solve(1, N);
}
