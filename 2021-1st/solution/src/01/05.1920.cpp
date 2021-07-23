#include <bits/stdc++.h>
using namespace std;

int N, Q, A[101010];

bool search(int v){
    int l = 1, r = N;
    while(l <= r){
        int m = l + r >> 1;
        if(A[m] == v) return true;
        else if(A[m] < v) l = m + 1;
        else r = m - 1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    cin >> Q;
    while(Q--){
        int t; cin >> t;
        cout << search(t) << "\n";
    }
}
