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
void solve()
{
	ll n, x;
	cin >> n >> x;
	vector<int>price(n);
	vector<int>pages(n);
	for (int i = 0; i < n; i++) cin >> price[i];
	for (int i = 0; i < n; i++) cin >> pages[i];
	vector<vector<int>>dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= price[i - 1])
			{
				dp[i][j] = max(dp[i - 1][j - price[i - 1]] + pages[i - 1], dp[i][j]);
			}
		}
	}
	cout << dp[n][x];

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