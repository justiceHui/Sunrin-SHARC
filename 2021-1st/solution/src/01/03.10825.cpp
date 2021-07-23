#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

struct Info{
    int kor, eng, mat;
    string name;
};

bool comp(const Info &a, const Info &b){
    if(a.kor != b.kor) return a.kor > b.kor;
    if(a.eng != b.eng) return a.eng < b.eng;
    if(a.mat != b.mat) return a.mat > b.mat;
    return a.name < b.name;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<Info> V(N);
    for(auto &i : V) cin >> i.name >> i.kor >> i.eng >> i.mat;
    sort(all(V), comp);
    for(const auto &i : V) cout << i.name << "\n";
}
