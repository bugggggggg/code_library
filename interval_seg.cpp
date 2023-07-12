struct SegmentTree
{
    // range update and query single position
	#define ls p << 1
	#define rs ls | 1
	long long sum[100066 * 4];
	long long tag[100066 * 4];
    
    void init() {
        for (int i = 0; i < 100066 * 4 ;i++) {
            sum[i] = tag[i] = 0;
        }
    }
    
	void pushdown(int p, int l, int r) {
        if (tag[p]) {
            int mid = (r + l) / 2;
            sum[ls] += (mid - l + 1) * tag[p];
            sum[rs] += (r - mid) * tag[p];
            tag[ls] += tag[p];
            tag[rs] += tag[p];
            tag[p] = 0;
        }
	}

	void upd(int p, int l, int r, int ql, int qr, long long w) {
		if (ql <= l && r <= qr) {
            // printf("%d %d %lld\n", l, r, w);
            sum[p] += (r - l + 1) * w;
            tag[p] += w;
            return ;
        }
		pushdown(p, l , r);
		int mid = (l + r) >> 1;
		if (ql <= mid) upd(ls, l, mid, ql, qr, w);
		if (mid < qr) upd(rs, mid + 1, r, ql, qr, w);
		sum[p] = sum[ls] + sum[rs];
	}

	long long ask(int p, int l, int r, int w) {
		if (l == r) {
			return sum[p];
		}
		pushdown(p, l, r);
		int mid = (l + r) >> 1;
        int ret = 0;
		if (w <= mid) ret = ask(ls, l, mid, w);
		else ret = ask(rs, mid + 1, r, w);
        sum[p] = sum[ls] + sum[rs];
        return ret;
	}
}seg;
