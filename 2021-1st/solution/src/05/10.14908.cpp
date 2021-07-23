#include <bits/stdc++.h>
using namespace std;

struct Task{
    int idx, deadline, penalty;
    bool operator < (const Task &task) const {
        int t1 = deadline * task.penalty;
        int t2 = task.deadline * penalty;
        if(t1 != t2) return t1 < t2;
        return idx < task.idx;
    }
};

int N;
Task A[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i].deadline >> A[i].penalty, A[i].idx = i;
    sort(A+1, A+N+1);
    for(int i=1; i<=N; i++) cout << A[i].idx << " ";
}
