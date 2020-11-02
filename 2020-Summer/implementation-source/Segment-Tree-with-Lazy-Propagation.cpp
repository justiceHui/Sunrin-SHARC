#include <iostream>
using namespace std;

typedef long long ll;

ll tree[1 << 18];
ll tmp[1 << 18]; // lazy

void push(int node, int s, int e){
    if (!tmp[node]) return;
    tree[node] += (e - s + 1) * tmp[node];
    if (s != e){
        tmp[node << 1] += tmp[node];
        tmp[node << 1 | 1] += tmp[node];
    }
    tmp[node] = 0;
}

void update(int node, int s, int e, int l, int r, int v){
    push(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r){
        tmp[node] += v; push(node, s, e);
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, l, r, v);
    update(node << 1 | 1, m + 1, e, l, r, v);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll query(int node, int s, int e, int l, int r){
    push(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int m = s + e >> 1;
    return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
}