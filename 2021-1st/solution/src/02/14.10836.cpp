#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

int N, Q, Sum[1414], D[777][777];
vector<PII> Border;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=N; i>=1; i--) Border.emplace_back(i, 1);
    for(int j=2; j<=N; j++) Border.emplace_back(1, j);
    for(int i=1; i<=Q; i++){
        int a, b, c; cin >> a >> b >> c;
        Sum[a]++; Sum[a+b]++;
    }
    partial_sum(Sum, Sum+1414, Sum);
    for(int i=0; i<Border.size(); i++){
        D[Border[i].x][Border[i].y] += Sum[i];
    }
    for(int i=2; i<=N; i++){
        for(int j=2; j<=N; j++){
            D[i][j] = max({D[i-1][j], D[i][j-1], D[i-1][j-1]});
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cout << D[i][j] + 1 << " ";
        cout << "\n";
    }
}
