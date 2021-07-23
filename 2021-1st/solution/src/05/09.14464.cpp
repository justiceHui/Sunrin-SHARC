#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

int C, N;
PII A[20202];
multiset<int> S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C >> N;
    for(int i=1; i<=C; i++){
        int t; cin >> t; S.insert(t);
    }
    for(int i=1; i<=N; i++){
        cin >> A[i].x >> A[i].y;
    }
    sort(A+1, A+N+1, [](PII p1, PII p2){
        if(p1.y != p2.y) return p1.y < p2.y;
        return p1.x < p2.x;
    });

    int ans = 0;
    for(int i=1; i<=N; i++){
        auto it = S.lower_bound(A[i].x);
        if(it != S.end() && *it <= A[i].y) ans++, S.erase(it);
    }
    cout << ans;
}
