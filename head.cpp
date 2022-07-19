#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cout << (#x) << " = " << (x) << endl
#else
#define debug(...) 42
#endif

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {uniform_int_distribution<int> uni(l, r);return uni(rng);}
//__builtin_popcount(n)
//getline(cin,s);

int main0 ();
int main () {
	clock_t start, end;
	#ifdef LOCAL
		freopen("file.in", "r", stdin);
		start = clock();
	#endif
	main0();
	#ifdef LOCAL
		end = clock();
		cout << "( " << (end - start) << " ms )" << endl;
		fclose(stdin);
	#endif
	return 0;
}

const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head