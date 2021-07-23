#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int median;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int N, cnt = 0; cin >> N;
    cout << (N+1) / 2 << "\n";

    cin >> median;
    cout << median << " "; cnt++;
    for(int i=2; i<=N; i+=2){
        int a, b; cin >> a >> b;
        if(a < median) max_heap.push(a);
        else min_heap.push(a);
        if(b < median) max_heap.push(b);
        else min_heap.push(b);

        while(max_heap.size() != min_heap.size()){
            if(max_heap.size() >  min_heap.size()){
                min_heap.push(median);
                median = max_heap.top(); max_heap.pop();
            }
            else{
                max_heap.push(median);
                median = min_heap.top(); min_heap.pop();
            }
        }
        cout << median << " "; cnt++;
        if(cnt % 10 == 0) cout << "\n";
    }
    if(cnt % 10 != 0) cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) Solve();
}
