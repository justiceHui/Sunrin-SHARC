#include <bits/stdc++.h>
using namespace std;

constexpr int N = 18;
double A, B, D[22][22][22];

bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2; i*i<=n; i++) if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> A >> B; A /= 100; B /= 100;
    D[0][0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=i; j++){
            for(int k=0; k<=i; k++){
                if(j > 0) D[i][j][k] += D[i-1][j-1][k] * A * (1-B);
                if(k > 0) D[i][j][k] += D[i-1][j][k-1] * (1-A) * B;
                if(j > 0 && k > 0) D[i][j][k] += D[i-1][j-1][k-1] * A * B;
                D[i][j][k] += D[i-1][j][k] * (1-A) * (1-B);
            }
        }
    }

    double ans = 0;
    for(int i=0; i<=N; i++) for(int j=0; j<=N; j++)
        if(isPrime(i) || isPrime(j)) ans += D[18][i][j];

    cout << fixed << setprecision(10) << ans;
}
