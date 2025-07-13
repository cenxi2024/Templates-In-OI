#include <bits/stdc++.h>

#define endl '\n'
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define low(i,a,b) for (auto i = (a); i >= (b); --i)
#define repl(i,a,b,w) for (auto i = (a); i <= (b); i += w)
#define lowl(i,a,b,w) for (auto i = (a); i >= (b); i -= w)
#define lpin(i,a) for (auto (i) : (a))
#define Db(a) std :: cout << #a << " = " << a << endl

using namespace std;

class trie {

	private :

		struct node {

			std :: unordered_map <char, node *> child;
			bool end;

			node (void) : end (false) {}
		} ;

		node * root;

		void del (node * this_node) {

			if (this_node == nullptr) return ;

			lpin (it, this_node -> child) del (it.second);

			delete this_node;

			return ;
		}

		node * getend (const string & s) {

			node * this_node = root;

			rep (i, 0, s.size () - 1) {

				if (this_node -> child[s[i]] == nullptr) return nullptr;

				this_node = this_node -> child[s[i]];
			}

			return this_node;
		}
	public :

		trie (void) {

			root = new node ();
			return ;
		}

		~ trie (void) {

			del (root);
			return ;
		}

		void insert (const string & s) {

			node * this_node = root; 

			rep (i, 0, s.size () - 1) {

				if (this_node -> child[s[i]] == nullptr) {

					node * temp = new node ();
					this_node -> child[s[i]] = temp;
				} 

				this_node = this_node -> child[s[i]];
			}

			return ;
		}

		bool find (const string & s) {

			node * temp = getend (s);
			return temp != nullptr and temp -> end == true;
		}

		bool pre (const string & s) {

			return getend (s) != nullptr;
		}
} ;

int main (void) {

	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	int t;
	cin >> t;

	while (t --) {

		int n, q;
		cin >> n >> q;

		trie tr;

		rep (i, 1, n) {

			string s;
			cin >> s;

			tr.insert (s);
		}

		rep (i, 1, q) {

			string s;
			cin >> s;

			
		}
	}

	return 0;
}