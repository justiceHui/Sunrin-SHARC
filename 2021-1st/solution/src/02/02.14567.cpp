#include <bits/stdc++.h>
using namespace std;

int N, M, In[1010], D[1010];
vector<int> G[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1,s,e; i<=M; i++){
        cin >> s >> e;
        G[s].push_back(e);
        In[e]++;
    }

    queue<int> q;
    for(int i=1; i<=N; i++) if(!In[i]) q.push(i), D[i] = 1;
    while(q.size()){
        int v = q.front(); q.pop();
        for(auto i : G[v]){
            if(!--In[i]) q.push(i);
            D[i] = max(D[i], D[v] + 1);
        }
    }
    for(int i=1; i<=N; i++) cout << D[i] << " ";
}
