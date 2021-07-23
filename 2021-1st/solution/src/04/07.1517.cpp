#include <bits/stdc++.h>
using namespace std;

int N, A[505050], T[505050];
long long Inv;

void Merge(int s, int m, int e){
    int i = s, j = m+1, idx = s, cnt = 0;
    while(i <= m && j <= e){
        if(A[i] <= A[j]) T[idx++] = A[i++], Inv += cnt;
        else T[idx++] = A[j++], cnt++;
    }
    while(i <= m) T[idx++] = A[i++], Inv += cnt;
    while(j <= e) T[idx++] = A[j++];
    for(int k=s; k<=e; k++) A[k] = T[k];
}

void MergeSort(int s, int e){
    if(s >= e) return;
    int m = s + e >> 1;
    MergeSort(s, m);
    MergeSort(m+1, e);
    Merge(s, m, e);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; for(int i=1; i<=N; i++) cin >> A[i];
    MergeSort(1, N);
    cout << Inv;
}
