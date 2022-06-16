struct Fenwick{
    int sum[100066];
    #define lowbit(x) ((x) & -(x))
    void init(int n) {
        for (int i = 1; i <= n; i++) sum[i] = 0;
    }
    void upd(int x, int w) {
        for ( ; x <= n; x += lowbit(x)) 
            sum[x] += w;
    }
    int ask(int x) {
        int ret = 0;
        assert(x >= 0);
        for ( ; x; x -= lowbit(x))
            ret += sum[x];
        return ret;
    }
}fenwick;