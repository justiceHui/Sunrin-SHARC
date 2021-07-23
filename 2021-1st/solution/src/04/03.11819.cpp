#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128_t;

LL Pow(LL A, LL B, LL MOD){
    LL ret = 1;
    while(B){
        if(B & 1) ret = ret * A % MOD;
        B >>= 1; A = A * A % MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll A, B, C; cin >> A >> B >> C;
    cout << ll(Pow(A, B, C));
}
