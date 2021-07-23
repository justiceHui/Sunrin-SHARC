#include <bits/stdc++.h>
using namespace std;

int N, Pre[1010], In[1010], Pos[1010];

void f(int s, int e, int l, int r){
    if(s > e || l > r) return;
    int root = Pre[s], pos = Pos[root];
    f(s+1, s+pos-1, l, pos-1);
    f(s+pos-l+1, e, pos+1, r);
    cout << root << " ";
}

void Solve(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> Pre[i];
    for(int i=1; i<=N; i++) cin >> In[i], Pos[In[i]] = i;
    f(1, N, 1, N);
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) Solve();
}
