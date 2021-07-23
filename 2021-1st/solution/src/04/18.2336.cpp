#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 1 << 19;

struct Point{
    int x, y, z;
    bool operator < (const Point &t) const {
        return tie(x,y,z) < tie(t.x,t.y,t.z);
    }
};

int N, T[SZ << 1];
Point A[SZ];

void Update(int x, int v){
    x |= SZ; T[x] = v;
    while(x >>= 1) T[x] = min(T[x<<1], T[x<<1|1]);
}

int Query(int l, int r){
    l |= SZ; r |= SZ; int ret = 0x3f3f3f3f;
    while(l <= r){
        if(l & 1) ret = min(ret, T[l++]);
        if(~r & 1) ret = min(ret, T[r--]);
        l >>= 1; r >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1,t; i<=N; i++) cin >> t, A[t].x = i;
    for(int i=1,t; i<=N; i++) cin >> t, A[t].y = i;
    for(int i=1,t; i<=N; i++) cin >> t, A[t].z = i;
    sort(A+1, A+N+1);

    int R = 0;
    memset(T, 0x3f, sizeof T);
    for(int i=1; i<=N; i++){
        if(Query(1, A[i].y) > A[i].z) R++;
        Update(A[i].y, A[i].z);
    }
    cout << R;
}
