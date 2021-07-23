#include <bits/stdc++.h>
using namespace std;

int N, D[303030];
long long C;
set<int> S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        int t; cin >> t;
        if(i == 1){
            S.insert(t); D[t] = 0;
            cout << C << "\n";
            continue;
        }
        auto it = S.upper_bound(t);
        if(it != S.end()) D[t] = max(D[t], D[*it] + 1);
        if(it != S.begin()) D[t] = max(D[t], D[*prev(it)] + 1);
        S.insert(t); C += D[t];
        cout << C << "\n";
    }
}
