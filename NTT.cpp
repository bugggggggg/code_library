namespace NTT {
    #define poly vector<int>
    const int mod = 998244353;//如果2*mod爆int了，add和sub里加个long long
    const int ROOT = 3; //原根
    int mul(int a, int b) { return 1ll * a * b % mod;}
    int add(int a, int b) {a += b; return (a >= mod)? a - mod: a;}
    int sub(int a, int b) {a -= b; return (a < 0)? a + mod: a;}
    int qpow(int a, int b) {
        int ans = 1;
        while(b) {if (b & 1) ans = mul(ans, a); a = mul(a, a); b >>= 1;}
        return ans;
    }

    int lim, R[1000006];

    void NTT(poly& a) {
        for (int i = 0; i < lim; i++) if (i < R[i]) swap(a[i], a[R[i]]);
        for (int h = 2; h <= lim; h <<= 1) {
            int gn = qpow(ROOT, (mod - 1) / h);
            for(int j = 0; j < lim; j += h) {
                int g = 1;
                for (int k = j; k < j + h / 2; k++) {
                    int u = a[k], t = mul(g, a[k + h / 2]);
                    a[k] = add(u, t);
                    a[k + h / 2] = sub(u, t);
                    g = mul(g, gn);
                }
            }
        }
    }

    poly mul(poly a, poly b) {
        int siz = SZ(a) + SZ(b) - 1;
        lim = 1;
        while (lim < siz) lim <<= 1;
        for (int i = 1; i < lim; i++) {
            R[i] = (R[i >> 1] >> 1) | ((i & 1)? lim >> 1: 0);
        }
		while (SZ(a) < lim) a.push_back(0);
		while (SZ(b) < lim) b.push_back(0);
		NTT(a); NTT(b);
        for (int i = 0; i < lim; i++) a[i] = mul(a[i], b[i]);
        NTT(a);
        reverse(a.begin() + 1, a.end());
        a.resize(siz);
        int inv = qpow(lim, mod - 2);
        for (int i = 0; i < siz; i++) a[i] = mul(a[i], inv);
        return a;
    }
}