#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 202020;

struct Node1{
    int l, r, v;
    Node1() : l(-1), r(-1), v(0) {}
} nd[60606060]; int pv;

struct Node2{
    int l, r, root;
    Node2() : l(-1), r(-1), root(-1) {}

    void update(int node, int s, int e, int x, int v){
        if (s == e){ nd[node].v = v; return; }
        int m = s + e >> 1, mx = 0;
        if (x <= m){
            if (nd[node].l == -1) nd[node].l = ++pv;
            update(nd[node].l, s, m, x, v);
            mx = max(mx, nd[nd[node].l].v);
            if (nd[node].r != -1) mx = max(mx, nd[nd[node].r].v);
        }
        else{
            if (nd[node].r == -1) nd[node].r = ++pv;
            update(nd[node].r, m + 1, e, x, v);
            mx = max(mx, nd[nd[node].r].v);
            if (nd[node].l != -1) mx = max(mx, nd[nd[node].l].v);
        }
        nd[node].v = mx;
    }
    int query(int node, int s, int e, int l, int r){
        if (node == -1) return 0;
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return nd[node].v;
        int m = s + e >> 1;
        return max(query(nd[node].l, s, m, l, r), query(nd[node].r, m + 1, e, l, r));
    }
    void update(int x, int v){
        if (root == -1) root = ++pv;
        update(root, 0, MX, x, v);
    }
    int query(int l, int r){
        return query(root, 0, MX, l, r);
    }
} nd2[4040404]; int pv2;

struct Seg2{
    int root = 0;
    void update(int node, int s, int e, int x, int y, int v){
        if (s == e){ nd2[node].update(y, v); return; }
        int m = s + e >> 1, mx = 0;
        if (x <= m){
            if (nd2[node].l == -1) nd2[node].l = ++pv2;
            update(nd2[node].l, s, m, x, y, v);
            mx = max(mx, nd2[nd2[node].l].query(y, y));
            if (nd2[node].r != -1) mx = max(mx, nd2[nd2[node].r].query(y, y));
        }
        else{
            if (nd2[node].r == -1) nd2[node].r = ++pv2;
            update(nd2[node].r, m + 1, e, x, y, v);
            mx = max(mx, nd2[nd2[node].r].query(y, y));
            if (nd2[node].l != -1) mx = max(mx, nd2[nd2[node].l].query(y, y));
        }
        nd2[node].update(y, mx);
    }
    int query(int node, int s, int e, int l, int r, int L, int R){
        if (node == -1) return 0;
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return nd2[node].query(L, R);
        int m = s + e >> 1;
        return max(query(nd2[node].l, s, m, l, r, L, R), query(nd2[node].r, m + 1, e, l, r, L, R));
    }
    void update(int x, int y, int v){
        update(root, 0, MX, x, y, v);
    }
    int query(int l, int r, int L, int R){
        return query(root, 0, MX, l, r, L, R);
    }
} seg;