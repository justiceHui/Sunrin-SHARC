#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int D[41] = {0, 5, 13};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=3; i<=40; i++) D[i] = D[i-1] + D[i-2] + 1;

    int N; cin >> N; N--;
    for(int i=40; i>=2; i--) if(D[i] <= N) N -= D[i] + 1;
    if(N == -1 || N == 5) cout << "Messi Messi Gimossi";
    else cout << "Messi Gimossi"[N];
}
