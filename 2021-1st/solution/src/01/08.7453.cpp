#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N), B(N), C(N), D(N), AB, CD;
    for(int i=0; i<N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    AB.reserve(N*N);
    CD.reserve(N*N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++)
        AB.push_back(A[i] + B[j]), CD.push_back(-(C[i] + D[j]));
    sort(all(AB));
    sort(all(CD));

    long long ans = 0;
    for(auto i : AB){
        auto range = equal_range(all(CD), i);
        ans += distance(range.first, range.second);
    }
    cout << ans;
}
