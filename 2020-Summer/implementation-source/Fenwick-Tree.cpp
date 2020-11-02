struct BIT{
    int tree[202020];
    void update(int x, int v){ for(x++; x<202020; x+=x&-x) tree[x] += v; }
    int query(int x){ int ret = 0; for(x++; x; x-=x&-x) ret += tree[x]; return ret; }
};