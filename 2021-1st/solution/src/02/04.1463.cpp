#include <bits/stdc++.h>
using namespace std;

int N, D[1010101];
int main(){
    cin >> N;
    for(int i=2; i<=N; i++){
        D[i] = D[i-1] + 1;
        if(i % 2 == 0) D[i] = min(D[i], D[i/2] + 1);
        if(i % 3 == 0) D[i] = min(D[i], D[i/3] + 1);
    }
    cout << D[N];
}
