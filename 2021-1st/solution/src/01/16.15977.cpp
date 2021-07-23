#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using Point = pair<int, int>;

struct Triplet{
    int x, y, z;
    bool operator < (const Triplet &t) const {
        return tie(x, y, z) < tie(t.x, t.y, t.z);
    }
};

struct Envelope{
    set<Point> st;
    void insert(const Point &pt){
        auto it = next(st.insert(pt).first);
        while(it != st.end() && it->y >= pt.y) it = st.erase(it);
    }
    bool Query(const Point &pt){
        auto it = st.lower_bound(pt);
        return it != st.begin() && prev(it)->y <= pt.y;
    }
};

int K, N, LIS[202020];
Triplet Input[202020];
Point A[202020];
Envelope st[202020];

int Get(int i){
    int l = 1, r = N;
    while(l < r){
        int m = l + r + 1 >> 1;
        if(st[m-1].Query(A[i])) l = m;
        else r = m - 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> K >> N;
    for(int i=1; i<=N; i++) cin >> Input[i].x;
    for(int i=1; i<=N; i++) cin >> Input[i].y;
    if(K == 3) for(int i=1; i<=N; i++) cin >> Input[i].z;
    else for(int i=1; i<=N; i++) Input[i].z = Input[i].y;

    sort(Input+1, Input+N+1);
    for(int i=1; i<=N; i++) A[i] = {Input[i].y, Input[i].z};

    for(int i=1; i<=N; i++){
        LIS[i] = Get(i);
        st[LIS[i]].insert(A[i]);
    }
    cout << *max_element(LIS+1, LIS+N+1);
}
