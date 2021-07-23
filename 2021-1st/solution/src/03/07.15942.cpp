#include <bits/stdc++.h>
using namespace std;

int N, K, P, Heap[202020];
int Small, Large;

void FillSmall(){
    vector<int> up;
    for(int i=P/2; i; i/=2) up.push_back(i);
    reverse(up.begin(), up.end());
    for(auto i : up) Heap[i] = Small++;
}

void FillLarge(int v){
    if(v*2 <= N) FillLarge(v*2);
    if(v*2+1 <= N) FillLarge(v*2+1);
    Heap[v] = Large--;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> P;
    Small = 1; Large = N;
    Heap[P] = K;

    if(P != 1) FillSmall();
    if(P*2 <= N) FillLarge(P*2);
    if(P*2+1 <= N) FillLarge(P*2+1);

    if(Small > K || Large < K){
        cout << -1;
        return 0;
    }

    for(int i=1; i<=N; i++){
        if(Heap[i]) continue;
        if(Small == K) Small++;
        Heap[i] = Small++;
    }

    for(int i=1; i<=N; i++) cout << Heap[i] << "\n";
}
