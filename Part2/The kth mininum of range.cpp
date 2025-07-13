#include <bits/stdc++.h>

#define endl '\n'
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define low(i,a,b) for (auto i = (a); i >= (b); --i)
#define repl(i,a,b,w) for (auto i = (a); i <= (b); i += w)
#define lowl(i,a,b,w) for (auto i = (a); i >= (b); i -= w)
#define lpin(i,a) for (auto (i) : (a))
#define Db(a) cout << #a << " = " << a << endl

using namespace std;

const int MAXN = 2e5 + 7;

vector <int> alls;

class zxtree {

	public :

		struct node {

			int l, r, cnt;
		} s[MAXN * 30];

		int root[MAXN];
		int size;

		int build (int l, int r) {

			int this_node = ++ size;
			s[this_node].cnt = 0;

			if (l == r) return this_node;

			int mid = l + r >> 1;

			s[this_node].l = build (l, mid);
			s[this_node].r = build (mid + 1, r);

			return this_node;
		}

		void init (void) {

			size = 0;
			root[0] = build (1, alls.size ());

			return ;
		}

		int insert (int pre, int l, int r, int id) {

			int this_node = ++ size;

			s[this_node] = s[pre];
			++ s[this_node].cnt;

			if (l == r) return this_node;

			int mid = l + r >> 1;

			if (id <= mid) s[this_node].l = insert (s[pre].l, l, mid, id);
			else s[this_node].r = insert (s[pre].r, mid + 1, r, id);

			return this_node;
		}

		int query (int u, int v, int l, int r, int k) {

			int value = s[s[v].l].cnt - s[s[u].l].cnt;

			if (l == r) return l;

			int mid = l + r >> 1;

			if (value >= k) return query (s[u].l, s[v].l, l, mid, k);
			else return query (s[u].r, s[v].r, mid + 1, r, k - value);
		}
} tr;

int a[MAXN], b[MAXN];		

int main (void) {

	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	int n, q;
	cin >> n >> q;

	rep (i, 1, n) {

		cin >> a[i];
		alls.push_back (a[i]);
	}

	sort (alls.begin (), alls.end ());
	alls.erase (unique (alls.begin (), alls.end ()), alls.end ());

	tr.init ();

	rep (i, 1, n) {

		b[i] = lower_bound (alls.begin (), alls.end (), a[i]) - alls.begin () + 1;
		tr.root[i] = tr.insert (tr.root[i - 1], 1, alls.size (), b[i]);
	}

	rep (i, 1, q) {

		int l, r, k;
		cin >> l >> r >> k;

		int id = tr.query (tr.root[l - 1], tr.root[r], 1, alls.size (), k);

		cout << alls[id - 1] << endl;
	}

	return 0;
}