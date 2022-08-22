struct DSU {
    int fa[100066];
    void init(int n) {
        iota(fa + 1, fa + n + 1, 1);
    }
    int get_fa(int x) {return x == fa[x]? x : fa[x] = get_fa(fa[x]);}
    bool unite(int x, int y) {
        int X = get_fa(x);
        int Y = get_fa(y);
        if (X == Y) return true;
        fa[X] = Y;
		return false;
    }
}dsu;