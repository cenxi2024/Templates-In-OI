#include <bits/stdc++.h>

#define endl '\n'
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define low(i,a,b) for (auto i = (a); i >= (b); --i)
#define repl(i,a,b,w) for (auto i = (a); i <= (b); i += w)
#define lowl(i,a,b,w) for (auto i = (a); i >= (b); i -= w)
#define lpin(i,a) for (auto (i) : (a))
#define Db(a) cout << #a << " = " << a << endl

using namespace std;

const int MAXN = 1e6 + 7;

class zxtree {

	public :

		struct node {

			int l, r, value;
		} s[MAXN * 30];

		int root[MAXN];
		int size;

		int insert (int this_node) {

			++ size;
			s[size] = s[this_node];

			return size;
		}

		int build (int this_node, int l, int r, int a[]) {

			++ size;
			this_node = size;

			if (l == r) {

				s[this_node].value = a[l];
				return size;
			}

			int mid = l + r >> 1;

			s[this_node].l = build (s[this_node].l, l, mid, a);
			s[this_node].r = build (s[this_node].r, mid + 1, r, a);

			return this_node;
		}

		int update (int this_node, int l, int r, int id, int value) {

			this_node = insert (this_node);

			if (l == r) {

				s[this_node].value = value;
				return this_node;
			}

			int mid = l + r >> 1;
			if (id <= mid) s[this_node].l = update (s[this_node].l, l, mid, id, value);
			else s[this_node].r = update (s[this_node].r, mid + 1, r, id, value);

			return this_node;
		}

		int query (int this_node, int l, int r, int id) {

			if (l == r) return s[this_node].value;

			int mid = l + r >> 1;

			if (id <= mid) return query (s[this_node].l, l, mid, id);
			else return query (s[this_node].r, mid + 1, r, id);
		}
} tree;

int a[MAXN];

int n, q;

int main (void) {

	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	cin >> n >> q;

	rep (i, 1, n) cin >> a[i];

	tree.root[0] = tree.build (0, 1, n, a);

	rep (i, 1, q) {

		int ver, op;
		cin >> ver >> op;

		if (op == 1) {

			int p, c;
			cin >> p >> c;

			tree.root[i] = tree.update (tree.root[ver], 1, n, p, c);
		} else {

			int p;
			cin >> p;

			cout << tree.query (tree.root[ver], 1, n, p) << endl;

			tree.root[i] = tree.root[ver];
		}
	}

	return 0;
}