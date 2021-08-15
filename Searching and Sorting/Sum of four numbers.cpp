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
	ll n, target;
	cin >> n >> target;
	vector<ll>a(n);
	unordered_map<int, queue<int>>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].push(i + 1);
		if (mp[a[i]].size() > 4) mp[a[i]].pop();
	}
	sort(all(a));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int lhs = j + 1, rhs = n - 1;
			while (lhs < rhs) {
				ll sum = a[lhs] + a[rhs] + a[j] + a[i];
				if (sum == target) {
					cout << mp[a[i]].front() << " ";
					mp[a[i]].pop();
					cout << mp[a[j]].front() << " ";
					mp[a[j]].pop();
					cout << mp[a[lhs]].front() << " ";
					mp[a[lhs]].pop();
					cout << mp[a[rhs]].front();
					return;
				}
				else if (sum < target) {
					lhs++;
				}
				else {
					rhs--;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
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