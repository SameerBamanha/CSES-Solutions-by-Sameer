//Sameer's Code
#include "bits/stdc++.h"
using namespace std;
#define allsort(a) 		sort(a.begin(),a.end());
#define allsorta(a) 	sort(a,a+n);
#define all(a) 			a.begin(),a.end()
#define ll 				long long
#define endl 			"\n"
#define MOD 			1000000007
#define pb 				push_back
//Useful declartions
vector<int>dx = {1, 0, -1, 0, 1, -1, 1, -1};
vector<int>dy = {0, 1, 0, -1, 1, -1, -1, 1};
//
//Templates
template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v) {os << v.first << " " << v.second; return os;}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (int i = 0; i < v.size(); ++i) { os << v[i] << " ";} os << "\n"; return os; }
//
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
void DFS(int u)
{
	visited[u] = true;
	for (auto &v : adj[u])
		if (!visited[v]) DFS(v);
}
void solve()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> components;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i]) continue;
		components.push_back(i);
		DFS(i);
	}
	cout << components.size() - 1 << '\n';
	for (int i = 1; i < components.size(); ++i)
		cout << components[i - 1] << " " << components[i] << '\n';
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long int t = 1;
	//cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		solve();
	}
	return 0;
}