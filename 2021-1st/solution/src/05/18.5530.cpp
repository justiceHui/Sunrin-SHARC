#include <bits/stdc++.h>
using namespace std;

int N;
char A[1010101];
vector<int> Pos;

bool Check(int make){
    int a = 0, b = 0, c = 0, sep = Pos[Pos.size() - make];
    for(int i=1; i<=N; i++){
        if(A[i] == 'J') a++;
        if(A[i] == 'O'){
            if(a > 0) a--, b++;
        }
        if(A[i] == 'I'){
            if(i < sep) a++;
            else if(b > 0) b--, c++;
        }
    }
    return make == c;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> (A+1);
    for(int i=1; i<=N; i++) if(A[i] == 'I') Pos.push_back(i);
    if(Pos.empty() || !Check(1)){ cout << 0; return 0; }

    int l = 1, r = Pos.size();
    while(l < r){
        int m = l + r + 1 >> 1;
        if(Check(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}
