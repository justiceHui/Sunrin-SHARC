#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int S = 505050;
constexpr int M = 100003;

struct FenwickTree{
    ll T[S];
    void _add(int x, int v){ for(x+=2; x<S; x+=x&-x) T[x] += v; }
    void add(int s, int e, int v=1){ _add(s, v); _add(e+1, -v); }
    ll get(int x){ ll ret = 0; for(x+=2; x>0; x-=x&-x) ret += T[x]; return ret; }
};
struct SparseTable{
    int T[22][M];
    void set(int x, int v){ T[0][x] = v; }
    void build(){
        for(int i=1; i<22; i++) for(int j=0; j<M; j++) T[i][j] = T[i-1][T[i-1][j]];
    }
    int get(int x, int v){
        for(int i=0; v; i++, v>>=1) if(v & 1) x = T[i][x];
        return x;
    }
};

inline int f(ll x){ return (2*x*x - 1 + M) % M; }
inline int g(ll x){ return (4*x*x - 3 + M) * x % M; }

int N, Q, A[S];
FenwickTree Tf, Tg;
SparseTable Sf, Sg;

int Get(int x, int a, int b){
    return Sg.get(Sf.get(x, a), b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=0; i<M; i++) Sf.set(i, f(i)), Sg.set(i, g(i));
    Sf.build(); Sg.build();
    while(Q--){
        int op, a, b; cin >> op >> a;
        if(op == 3) cout << Get(A[a], Tf.get(a), Tg.get(a)) << "\n";
        else cin >> b, (op == 1 ? Tf : Tg).add(a, b);
    }
}
