#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

constexpr int SZ = 1 << 19;
struct SegmentTree{
    int T[SZ << 1];
    SegmentTree(){ memset(T, 0xc0, sizeof T); }
    void update(int x, int v){
        x |= SZ; T[x] = max(T[x], v);
        while(x >>= 1) T[x] = max(T[x], v);
    }
    int query(int l, int r){
        l |= SZ; r |= SZ; int ret = T[0];
        while(l <= r){
            if(l & 1) ret = max(ret, T[l++]);
            if(~r & 1) ret = max(ret, T[r--]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
};

int N, U, D, S, DP[505050];
vector<PII> A[505050];

SegmentTree T_D, T_U;

void Update(int pos, int dp){
    T_D.update(pos, dp + D * pos);
    T_U.update(pos, dp - U * pos);
}

int Query(int pos, int money){
    int dw = T_D.query(0, pos) - D * pos + money;
    int up = T_U.query(pos, 505050) + U * pos + money;
    return max(dw, up);
}

void SolveTime(int ti){
    if(A[ti].empty()) return;
    int len = A[ti].size();

    vector<int> DL(len), DR(len);
    for(int i=0; i<len; i++){
        DL[i] = DR[i] = Query(A[ti][i].x, A[ti][i].y);
    }
    for(int i=len-2; i>=0; i--){
        DL[i] = max(DL[i], DL[i+1] - U * (A[ti][i+1].x - A[ti][i].x) + A[ti][i].y);
    }
    for(int i=1; i<len; i++){
        DR[i] = max(DR[i], DR[i-1] - D * (A[ti][i].x - A[ti][i-1].x) + A[ti][i].y);
    }
    for(int i=0; i<len; i++){
        int res = max(DL[i], DR[i]);
        Update(A[ti][i].x, res);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> U >> D >> S;
    int sz = 0;
    for(int i=1; i<=N; i++){
        int t, l, m; cin >> t >> l >> m;
        A[t].emplace_back(l, m);
        sz = max(sz, t);
    }
    A[0].emplace_back(S, 0);    // start
    A[++sz].emplace_back(S, 0); // end
    for(int i=0; i<=sz; i++) sort(A[i].begin(), A[i].end());

    memset(DP, 0xc0, sizeof DP);
    DP[0] = 0; Update(S, 0);
    for(int i=1; i<=sz; i++) SolveTime(i);
    cout << Query(S, 0);
}
