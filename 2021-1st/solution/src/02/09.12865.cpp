#include <bits/stdc++.h>
using namespace std;

int N, K, W[111], V[111];
int D[111][101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            D[i][j] = D[i-1][j];
            if(j-W[i] >= 0) D[i][j] = max(D[i][j], D[i-1][j-W[i]]+V[i]);
        }
    }
    cout << *max_element(D[N], D[N]+K+1);
}

/*
#include <bits/stdc++.h>
using namespace std;

int N, K, W[111], V[111];
int D[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];
    for(int i=1; i<=N; i++){
        for(int j=K; j>=W[i]; j--){
            D[j] = max(D[j], D[j-W[i]]+V[i]);
        }
    }
    cout << *max_element(D, D+K+1);
}
*/
