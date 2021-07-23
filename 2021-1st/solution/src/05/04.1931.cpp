#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

int N;
PII A[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].y;
    sort(A+1, A+N+1, [](PII p1, PII p2){
        if(p1.y != p2.y) return p1.y < p2.y;
        return p1.x < p2.x;
    });

    int mx = 0, cnt = 0;
    for(int i=1; i<=N; i++){
        if(mx <= A[i].x) cnt++, mx = A[i].y;
    }
    cout << cnt;
}
