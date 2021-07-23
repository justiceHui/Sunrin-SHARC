#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, D[99] = {0, 1};
int main(){
    cin >> N;
    for(int i=2; i<=N; i++) D[i] = D[i-1] + D[i-2];
    cout << D[N];
}
