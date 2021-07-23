#include <bits/stdc++.h>
using namespace std;

int N, K, A[11], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=N; i>=1; i--){
        R += K / A[i];
        K %= A[i];
    }
    cout << R;
}
