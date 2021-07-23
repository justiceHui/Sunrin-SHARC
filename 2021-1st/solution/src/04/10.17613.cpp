#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

map<PII, int> D;

int f(int l, int r){
    if(l == 0 && r == 0) return 0;
    if(D.find(PII(l,r)) != D.end()) return D[{l,r}];

    int ret = 0;
    for(int i=0; i<30; i++){
        int s = (1 << i) - 1, e = (1 << (i+1)) - 2;
        s = max(s, l); e = min(r, e);
        if(s <= e) ret = max(ret, i + f(s-(1<<i)+1, e-(1<<i)+1));
    }
    return D[{l,r}] = ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int a, b; cin >> a >> b;
        cout << f(a, b) << "\n";
    }
}
