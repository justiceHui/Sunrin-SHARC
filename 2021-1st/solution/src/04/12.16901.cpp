#include <bits/stdc++.h>
using namespace std;
constexpr int MX_BIT = 29;

struct Node{
    int l, r;
    Node(){ l = r = -1; }
} T[202020 * MX_BIT];
int nd_cnt;

void Insert(int v, int node=0, int dep=MX_BIT){
    if(dep == -1) return;
    if(v & (1 << dep)){
        if(T[node].r == -1) T[node].r = ++nd_cnt, T[nd_cnt] = Node();
        Insert(v, T[node].r, dep-1);
    }
    else{
        if(T[node].l == -1) T[node].l = ++nd_cnt, T[nd_cnt] = Node();
        Insert(v, T[node].l, dep-1);
    }
}

// return min(v ^ element)
int Query(int v, int node=0, int dep=MX_BIT){
    if(dep == -1) return 0;
    if(v & (1 << dep)){
        if(T[node].r != -1) return Query(v, T[node].r, dep-1);
        else return (1 << dep) + Query(v, T[node].l, dep-1);
    }
    else{
        if(T[node].l != -1) return Query(v, T[node].l, dep-1);
        else return (1 << dep) + Query(v, T[node].r, dep-1);
    }
}

int N, A[202020];
long long R;

void Solve(int s, int e, int dep=MX_BIT){
    if(dep == -1 || s >= e) return;

    int m = s-1;
    while(m+1 <= e && (A[m+1] & (1 << dep)) == 0) m++;
    Solve(s, m, dep-1); Solve(m+1, e, dep-1);
    if(s > m || m+1 > e) return;

    int now = 0x3fffffff;
    nd_cnt = 0; T[0] = Node();
    for(int i=s; i<=m; i++) Insert(A[i]);
    for(int i=m+1; i<=e; i++) now = min(now, Query(A[i]));
    R += now;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    Solve(1, N);
    cout << R;
}
