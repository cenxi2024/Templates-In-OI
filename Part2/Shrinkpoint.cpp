#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int N (1e5 + 10);

queue<int> q;
vector<int> G[N];
vector<int> E[N];

int a[N], sd[N], st[N], in[N], dist[N], vis[N], low[N], dfn[N];

int n, m, cnt, top, ans;

inline void tarjan(register const int u)
{

	vis[u] = 1;
	st[++ top] = u;

	++ cnt;
	low[u] = cnt;
	dfn[u] = cnt;

	register const int len (G[u].size ());

	for (register int i (0); i < len; ++ i)
	{

		register const int v (G[u][i]);

		if (not dfn[v])
		{

			tarjan (v);

			low[u] = min (low[u], low[v]);
		}

		else if (vis[v])
		{

			low[u] = min (low[u], dfn[v]);
		}
	}

	if (dfn[u] == low[u])
	{

		register int y;

		while (y = st[top --])
		{

			sd[y] = u;
			vis[y] = 0;

			if (u == y)
			{

				break;
			}

			a[u] += a[y];
		}
	}

	return;
}

inline void topo (void)
{

	for (register int i (1); i <= n; ++ i)
	{

		if (sd[i] == i and not in[i])
		{

			q.push (i);

			dist[i] = a[i];
		}
	}
	while (not q.empty ())
	{

		register const int u (q.front ());
		q.pop ();

		register const int len (E[u].size ());

		for (register int i (0); i < len; ++ i)
		{

			register int v (E[u][i]);
			-- in[v];
			dist[v] = max(dist[v], dist[u] + a[v]);

			if (not in[v])
			{

				q.push (v);
			}
		}
	}

	for (register int i (1); i <= n; ++ i)
	{

		ans = max(ans, dist[i]);
	}

	return;
}

int main (void)
{

	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	cin >> n >> m;

	for (register int i (1); i <= n; ++ i)
	{

		cin >> a[i];
	}

	for (register int i (1); i <= m; ++ i)
	{

		register int u, v;

		cin >> u >> v;

		G[u].push_back(v);
	}

	for (register int i (1); i <= n; ++ i)
	{

		if (not dfn[i])
		{

			tarjan(i);
		}
	}
	
	for (register int i (1); i <= n; ++ i)
	{
		
		register const int u (sd[i]);
		register const int len (G[i].size ());
		
		for (register int j (0); j < len; ++ j)
		{
			
			register int v (sd[G[i][j]]);
			
			if (u != v)
			{
				
				E[u].push_back(v);
				
				++ in[v];
			}
		}
	}
	
	topo ();
	
	cout << ans << '\n';
	
	return 0;
}