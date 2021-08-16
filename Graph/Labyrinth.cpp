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
const int N = 0;
/*
Solve 10 Questions Daily
*/
struct point {
	int x, y, dist;
};
void solve()
{
	int n, m, fx, fy, sx, sy;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dist(n, vector<int>(m, -1));
	queue<point>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'A') {fx = i, fy = j;}
			if (v[i][j] == 'B') {
				sx = i, sy = j;
			}
		}
	}
	v[fx][fy] = '#';
	q.push({fx, fy, 0});
	while (!q.empty()) {
		auto [x, y, distance] = q.front();
		q.pop();
		dist[x][y] = distance;
		if (x == sx && y == sy) {
			cout << "YES" << endl;
			cout << distance << endl;
			string ans;
			while (x != fx || y != fy) {
				if (x > 0 && dist[x - 1][y] == distance - 1) {
					ans.pb('D');
					x--;
				} else if (x < n - 1 && dist[x + 1][y] == distance - 1) {
					ans.pb('U');
					x++;
				} else if (y > 0 && dist[x][y - 1] == distance - 1) {
					ans.pb('R');
					y--;
				} else {
					ans.pb('L');
					y++;
				}
				distance--;
			}
			for (int i = (int)ans.size() - 1; i >= 0; i--) {
				cout << ans[i];
			}
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int x1 = x + dx[dir]; int y1 = y + dy[dir];
			if ((x1 < 0 || y1 < 0 || x1 > n - 1 || y1 > m - 1 || v[x1][y1] == '#')) {
				continue;
			}
			v[x1][y1] = '#';
			q.push({x1, y1, distance + 1});
		}
	}
	cout << "NO";
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