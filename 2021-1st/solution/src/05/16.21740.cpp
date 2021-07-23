#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int N;
string A[1010101], R[1010101];

string Reverse(const string &s){
    string ret = s; reverse(all(ret));
    for(auto &i : ret){
        if(i == '6') i = '9';
        else if(i == '9') i = '6';
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], R[i] = Reverse(A[i]);
    int largest = max_element(R+1, R+N+1, [](const string &s1, const string &s2){
        if(s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    }) - R;

    vector<int> O(N+1);
    iota(all(O), 1); O.back() = largest;
    sort(all(O), [](int s1, int s2){
        return R[s1] + R[s2] > R[s2] + R[s1];
    });
    reverse(all(O));
    for(auto i : O) cout << A[i];
}
