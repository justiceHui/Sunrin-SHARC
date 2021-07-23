#include <bits/stdc++.h>
using namespace std;

int N, K;
string A[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K; for(int i=1; i<=N; i++) cin >> A[i];
    string largest = *max_element(A+1, A+N+1, [](const string &s1, const string &s2){
        if(s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    });
    while(N < K) A[++N] = largest;
    sort(A+1, A+N+1, [](const string &s1, const string &s2){
        return s1 + s2 > s2 + s1;
    });
    for(int i=1; i<=N; i++) cout << A[i];
}
