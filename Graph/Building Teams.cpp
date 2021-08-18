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
const int N = 2e5 + 20;
vector<int>adj[N];
vector<int>color(N, -1);
bool check(int node, int c) {
	if (color[node] == -1) color[node] = c;
	for (auto child : adj[node]) {
		if (color[child] == -1) {
			if (!check(child, c ^ 1)) {
				return false;
			}
		}
		else if (color[node] == color[child]) {
			return false;
		}
	}
	return true;
}
void solve()
{
	int n, m, a, b; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		if (color[i] != -1) continue;
		if (!check(i, 0)) {
			cout << "IMPOSSIBLE";
			return;
		}
	}
	for (int i = 1; i <= n; i++) cout << color[i] + 1 << " ";

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