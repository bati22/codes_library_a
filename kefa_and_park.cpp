//Kefa and park
//https://codeforces.com/problemset/problem/580/C
//DFS
//O(n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned ull;
const ll N_MAX = 100123;
ll n, m;
ll a[N_MAX];
ll x, y;
vector<ll> A[N_MAX];
ll result;
bool visited[N_MAX];

void dfs(ll v, ll cat_number)
{
	visited[v] = true;
	if(a[v])
		cat_number++;
	else
		cat_number = 0;

	if(A[v].size()==1 && v != 1 && m >= cat_number)
		result++;

	for (ull i = 0; i < A[v].size(); i++)
	{
		ll u = A[v][i];
		if(!visited[u] && m >= cat_number)
			dfs(u, cat_number);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n-1; i++)
	{
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}

	dfs(1, 0);

	cout << result << '\n';



	return 0;
}
