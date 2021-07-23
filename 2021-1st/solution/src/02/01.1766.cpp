#include <bits/stdc++.h>
using namespace std;

int N, M, In[32323];
vector<int> G[32323];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1,s,e; i<=M; i++){
        cin >> s >> e;
        G[s].push_back(e);
        In[e]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=1; i<=N; i++) if(!In[i]) pq.push(i);
    while(pq.size()){
        int v = pq.top(); pq.pop();
        cout << v << " ";
        for(auto i : G[v]) if(!--In[i]) pq.push(i);
    }
}
