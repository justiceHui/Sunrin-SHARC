#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> V;
map<string, int> C;

bool Compare(const string &a, const string &b){
    if(C[a] != C[b]) return C[a] > C[b];
    if(a.size() != b.size()) return a.size() > b.size();
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        if(s.size() >= M) V.push_back(s), C[s]++;
    }
    sort(V.begin(), V.end(), Compare);
    for(int i=0; i<V.size(); i++){
        if(i == 0 || V[i-1] != V[i]) cout << V[i] << "\n";
    }
}
