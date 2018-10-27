#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 2*100123;
ll a[N_MAX];
ll n, m;
ll k;
ll result;

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	k = n/m;

	vector <vector<ll>> val(n);
	vector<pair<ll,ll>> fre;

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		val[a[i]%m].push_back(i);
	}
	

	for (ll i = 0; i < 2*m; i++)
	{
		ll cur = i%m;

		while(val[cur].size() > k)
		{
			ll element = val[cur].back();
			ll indeks = i;
			val[cur].pop_back();
			fre.push_back(make_pair(element, indeks));
		}

		while(val[cur].size() < k && !fre.empty())
		{
			ll element = fre.back().first;
			ll indeks = fre.back().second;
			fre.pop_back();
			val[cur].push_back(element);
			a[element] += i-indeks;
			result += i-indeks;
		}
	}

	cout << result << endl;
	for (ll i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;





	return 0;
}
