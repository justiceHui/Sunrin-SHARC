#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using LL = __int128_t;

struct Card{
    int id, idx;
    Card() = default;
    Card(int id, int idx) : id(id), idx(idx) {}
};

int N, K, A[4];
vector<ll> V[4], S[4];

bool operator > (const Card &a, const Card &b){
    LL a1 = S[a.id][a.idx], a2 = S[a.id][a.idx-1];
    LL b1 = S[b.id][b.idx], b2 = S[b.id][b.idx-1];
    return a1*b2 > b1*a2; // a1/a2 > b1/b2
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=0; i<4; i++) cin >> A[i];
    for(int i=0; i<N; i++){
        char c; int x; cin >> c >> x;
        V[c-'A'].push_back(x);
    }
    for(int i=0; i<4; i++){
        sort(all(V[i]), greater<>());
        V[i].insert(V[i].begin(), A[i]);
        partial_sum(all(V[i]), back_inserter(S[i]));
    }

    vector<Card> cards;
    for(int i=0; i<4; i++){
        for(int j=1; j<V[i].size(); j++) cards.emplace_back(i, j);
    }
    sort(all(cards), greater<>());
    cards.resize(K);
    for(auto [id,idx] : cards) cout << char('A'+id) << " " << V[id][idx] << "\n";
}
