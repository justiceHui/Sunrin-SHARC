#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 1 << 20;

int N, T[SZ << 1];

void Update(int x, int v){
    x |= SZ; T[x] += v;
    while(x >>= 1) T[x] += v;
}
int Kth(int k){
    int x = 1;
    while(x < SZ){
        if(k <= T[x << 1]) x = x << 1;
        else k -= T[x << 1], x = x << 1 | 1;
    }
    return x ^ SZ;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        int op; cin >> op;
        if(op == 1){
            int a; cin >> a;
            int res = Kth(a);
            cout << res << "\n";
            Update(res, -1);
        }
        else{
            int a, b; cin >> a >> b;
            Update(a, b);
        }
    }
}
