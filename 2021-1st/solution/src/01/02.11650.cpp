#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> V(N);
    for(auto &i : V) cin >> i.x >> i.y;
    sort(all(V));
    for(auto i : V) cout << i.x << " " << i.y << "\n";
}
