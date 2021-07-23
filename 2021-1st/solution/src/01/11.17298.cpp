#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
constexpr int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> V(N), R(N);
    for(auto &i : V) cin >> i;

    stack<int, vector<int>> stk; stk.push(INF);
    for(int i=N-1; ~i; i--){
        while(stk.top() <= V[i]) stk.pop();
        R[i] = stk.top() == INF ? -1 : stk.top();
        stk.push(V[i]);
    }
    for(auto i : R) cout << i << " ";
}
