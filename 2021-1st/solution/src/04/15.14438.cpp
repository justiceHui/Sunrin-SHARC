#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SZ = 1 << 18;

int N, Q, A[SZ], T[SZ << 1];

void Build(){
    memset(T, 0x3f, sizeof T);
    for(int i=1; i<=N; i++) T[i|SZ] = A[i];
    for(int i=SZ-1; i>=1; i--) T[i] = min(T[i << 1], T[i << 1 | 1]);
}

void Update(int x, ll v){
    x |= SZ; T[x] = v;
    while(x >>= 1) T[x] = min(T[x << 1], T[x << 1 | 1]);
}

int Query(int l, int r){
    l |= SZ; r |= SZ;
    int ret = 0x3f3f3f3f;
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
    for(int i=1; i<=N; i++) cin >> A[i];
    Build();
    cin >> Q;
    for(int i=1; i<=Q; i++){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) Update(a, b);
        else cout << Query(a, b) << "\n";
    }
}
