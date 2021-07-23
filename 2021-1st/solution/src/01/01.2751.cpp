#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> V(N);
    for(auto &i : V) cin >> i;
    sort(V.begin(), V.end());
    for(auto i : V) cout << i << "\n";
}
