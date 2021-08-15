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
const int N = 6000;
/*
Solve 10 Questions Daily
*/
void solve()
{
	long long int n, sum = 0;
	cin >> n;
	vector<long long int>a(n);
	for (long long int i = 0; i < n; i++) {
		cin >> a[i]; ;
	}
	long long int dp[n][n][2];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		sum += a[i];
		dp[i][i][0] = sum;
	}
	for (long long int len = 1; len < n; len++) {
		for (long long int i = 0; i + len < n; i++) {
			long long int right = i + len;
			dp[i][right][0] = max(dp[i + 1][right][1] + a[i], dp[i][right - 1][1] + a[right]);
			dp[i][right][1] = min(dp[i + 1][right][0], dp[i][right - 1][0]);
		}
	}
	cout << dp[0][n - 1][0] << endl;
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