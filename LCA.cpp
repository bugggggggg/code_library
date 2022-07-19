struct LCA { // 下标从1开始
    int DEP = 18;
    int dp[100066][19], dep[100066];

    void dfs(int x, int fa) {
        dp[x][0] = fa;
        for (int i = 1; i <= DEP; i++)
            dp[x][i] = dp[dp[x][i - 1]][i - 1];
        dep[x] = dep[fa] + 1;
        for (auto y: e[x]) {
            if (y == fa) continue;
            dfs(y, x);
        }
    }

    int lca(int x, int y) {
        if (dep[x] > dep[y]) swap(x, y);
        for (int i = DEP; i >= 0; i--)
            if (dep[dp[y][i]] >= dep[x]) y = dp[y][i];
        if (x == y) return x;
        for (int i = DEP; i >= 0; i--)
            if (dp[x][i] != dp[y][i]) x = dp[x][i], y = dp[y][i];
        return dp[x][0];
    }

    int climb(int x, int step) {
		for (int i = DEP; i >= 0; i--) {
			if ((step >> i) & 1) {
				x = dp[x][i];
			}
		}
		return x;
	}
}lca;