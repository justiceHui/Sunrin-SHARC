#include <bits/stdc++.h>
using namespace std;

int N, G[26][2];

void pre_order(int v){
    cout << char(v + 'A');
    if(G[v][0]) pre_order(G[v][0]);
    if(G[v][1]) pre_order(G[v][1]);
}
void in_order(int v){
    if(G[v][0]) in_order(G[v][0]);
    cout << char(v + 'A');
    if(G[v][1]) in_order(G[v][1]);
}
void post_order(int v){
    if(G[v][0]) post_order(G[v][0]);
    if(G[v][1]) post_order(G[v][1]);
    cout << char(v + 'A');
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++){
        char p, l, r; cin >> p >> l >> r;
        if(l != '.') G[p-'A'][0] = l-'A';
        if(r != '.') G[p-'A'][1] = r-'A';
    }
    pre_order(0); cout << "\n";
    in_order(0); cout << "\n";
    post_order(0); cout << "\n";
}
