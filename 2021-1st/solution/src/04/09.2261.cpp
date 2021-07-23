#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using Point = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll Dist(const Point &p1, const Point &p2){
    ll dx = p1.x - p2.x, dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int N;
Point A[101010], T[101010];

ll DnC(int s, int e){
    if(s == e) return INF;
    int m = (s + e) / 2;
    ll divLine = A[m].x;
    ll d = min(DnC(s, m), DnC(m+1, e));

    int l = s, r = m+1, idx = s;
    while(l <= m && r <= e){
        if(A[l].y < A[r].y) T[idx++] = A[l++];
        else T[idx++] = A[r++];
    }
    while(l <= m) T[idx++] = A[l++];
    while(r <= e) T[idx++] = A[r++];
    for(int i=s; i<=e; i++) A[i] = T[i];

    vector<Point> now;
    for(int i=s; i<=e; i++){
        ll dx = A[i].x - divLine;
        if(dx * dx < d) now.push_back(A[i]);
    }

    ll ret = d;
    for(int i=1; i<now.size(); i++){
        for(int j=i-1; j>=0; j--){
            ll dy = now[i].y - now[j].y;
            if(dy * dy >= d) break;
            ret = min(ret, Dist(now[i], now[j]));
        }
    }
    return ret;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].x >> A[i].y;
    sort(A+1, A+N+1);
    cout << DnC(1, N);
}
