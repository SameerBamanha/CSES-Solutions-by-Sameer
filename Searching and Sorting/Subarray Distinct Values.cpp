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
	ll n, k, left = 0, ans = 0;
	cin >> n >> k;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	map<ll, ll>mp;
	for (ll i = 0; i < n; i++) {
		mp[a[i]] += 1;
		while (mp.size() > k) {
			mp[a[left]]--;
			if (mp[a[left]] == 0) mp.erase(a[left]);
			left++;
		}
		ans += (i - left + 1);
	}
	cout << ans;
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