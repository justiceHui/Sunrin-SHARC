#include <bits/stdc++.h>
using namespace std;

int N, A[1010], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);

    for(int i=1,s=0; i<=N; i++){
        s += A[i];
        R += s;
    }
    cout << R;
}
