#include <bits/stdc++.h>
using namespace std;

int N, R, C;

int Solve(int i, int j, int sz){
    if(sz == 0) return 0;

    int ret = 0;
    int ii = i + (1 << (sz-1));
    int jj = j + (1 << (sz-1));
    if(R < ii && C < jj) return ret + Solve(i, j, sz-1);
    ret += 1 << (sz-1)*2;
    if(R < ii && C >= jj) return ret + Solve(i, jj, sz-1);
    ret += 1 << (sz-1)*2;
    if(R >= ii && C < jj) return ret + Solve(ii, j, sz-1);
    ret += 1 << (sz-1)*2;
    return ret + Solve(ii, jj, sz-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> R >> C;
    cout << Solve(0, 0, N);
}
