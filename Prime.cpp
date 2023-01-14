vector<int> prime;
int v[100066];

void init_prime(int n) {
	for (int i = 2; i <= n; i++) {
		if (!v[i]) {
			prime.emplace_back(i);
			v[i] = i;
		}
		for (auto p : prime) {
			if (p > v[i] || 1ll * p * i > n) {
				break;
			}
			v[i * p] = p;
		}
	}
}