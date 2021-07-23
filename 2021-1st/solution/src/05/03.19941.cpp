#include <bits/stdc++.h>
using namespace std;

int N, K, Eat[20202], R;
char A[20202];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];

    for(int i=1; i<=N; i++){
        if(A[i] == 'H') continue;
        for(int j=max(1, i-K); j<=min(N, i+K); j++){
            if(A[j] == 'H' && !Eat[j]){
                R++; Eat[j] = 1;
                break;
            }
        }
    }
    cout << R;
}
