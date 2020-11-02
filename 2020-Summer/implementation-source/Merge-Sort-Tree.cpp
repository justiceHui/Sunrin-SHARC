#define all(v) v.begin(), v.end()
const int sz = 1 << 17;
vector<T> tree[sz*2];
void add(int x, T v){
  x += sz; tree[x].push_back(v);
}
void build(){
  for(int i=1; i<=n; i++) add(i, a[i]);
  for(int i=sz-1; i; i--){
    merge(all(tree[i*2]), all(tree[i*2+1]), back_inserter(tree[i]));
  }
}