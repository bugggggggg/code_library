struct ST {
	int N = 19;
	int mx[200066][20];

	void init(int n, int* a) {
		for (int i = 1; i <= n; i++) {
			mx[i][0] = a[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
			}
		}
	}

	int get_mx(int l, int r) {
		int len = (r - l + 1);
		int p = log2(len);
		return max(mx[l][p], mx[r - (1 << p) + 1][p]);
	}
} st;