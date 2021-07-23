#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000;

struct Matrix{
    int sz;
    vector<vector<int>> a;
    Matrix(int sz, int init=0) : sz(sz), a(sz, vector<int>(sz)) {
        for(int i=0; i<sz; i++) a[i][i] = init;
    }
};

Matrix Multiply(const Matrix &l, const Matrix &r){
    int n = l.sz;
    Matrix ret(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++) ret.a[i][j] += l.a[i][k] * r.a[k][j];
            ret.a[i][j] %= MOD;
        }
    }
    return ret;
}

Matrix Pow(Matrix a, long long b){
    Matrix ret(a.sz, 1);
    while(b){
        if(b & 1) ret = Multiply(ret, a);
        b >>= 1; a = Multiply(a, a);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; long long B;
    cin >> N >> B;

    Matrix M(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> M.a[i][j];
    }

    Matrix Res = Pow(M, B);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << Res.a[i][j] << " ";
        cout << "\n";
    }
}
