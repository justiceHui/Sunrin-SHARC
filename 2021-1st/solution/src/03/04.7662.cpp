#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int Q; cin >> Q;
    multiset<int> st;
    while(Q--){
        char op; int v; cin >> op >> v;
        if(op == 'I') st.insert(v);
        else if(op == 'D' && v == -1 && !st.empty()) st.erase(st.begin());
        else if(op == 'D' && v == +1 && !st.empty()) st.erase(prev(st.end()));
    }
    if(st.empty()) cout << "EMPTY\n";
    else cout << *st.rbegin() << " " << *st.begin() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) Solve();
}
