#include <bits/stdc++.h>

#define endl '\n'
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define low(i,a,b) for (auto i = (a); i >= (b); --i)
#define repl(i,a,b,w) for (auto i = (a); i <= (b); i += w)
#define lowl(i,a,b,w) for (auto i = (a); i >= (b); i -= w)
#define lpin(i,a) for (auto (i) : (a))
#define Db(a) cout << #a << " = " << a << endl

using namespace std;

class xtrie {

	private :

		
	
} ;

int main (void) {

	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	xtrie w;
	w.insert (1);
	w.insert (2);

	cout << w.getmax (4) << endl;

	return 0;
}