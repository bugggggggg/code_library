ll exgcd(ll a, ll b, ll&x, ll&y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll g = exgcd(b, a % b, x, y);
	ll tmp = x;
	x = y; y = tmp - a / b * y;
	return g;
}