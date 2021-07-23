#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K, A[111], D[10101];
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];

    D[0] = 1;
    for(int c=1; c<=N; c++){ // 1...c번째 동전만 사용해서 i원을 만드는 경우
        for(int j=1; j<=K; j++){
            if(j-A[c] >= 0) D[j] += D[j-A[c]];
        }
    }
    cout << D[K];
}
