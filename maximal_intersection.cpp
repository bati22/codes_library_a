#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 300123;
ll l[N_MAX];
ll r[N_MAX];

ll n;

ll max_l1 = -1;
ll max_l2 = -1;
ll max_l_new;

ll min_r1 = LLONG_MAX;
ll min_r2 = LLONG_MAX;
ll min_r_new;

ll result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		if(l[i]==max_l1)
			max_l2 = l[i];
		else if (l[i] > max_l1)
		{
			max_l2 = max_l1;
			max_l1 = l[i];
		}
		else // l[i] < max_l1
		{
			max_l2 = max(max_l2, l[i]);
		}

		if(r[i]==min_r1)
			min_r2 = r[i];
		else if(r[i] < min_r1)
		{
			min_r2 = min_r1;
			min_r1 = r[i];
		}
		else
		{
			min_r2 = min(min_r2, r[i]);
		}

		//cout << max_l1 << " " << max_l2 << " " << min_r1 << " " << min_r2 << '\n';
	}

	if(n==1)
		cout << 0 << '\n';
	else
	{
		for (ll i = 1; i <= n; i++)
		{
			if(max_l1==l[i])
				max_l_new = max_l2;
			else
				max_l_new = max_l1;

			if(min_r1==r[i])
				min_r_new = min_r2;
			else
				min_r_new = min_r1;

			//cout << max_l_new << " " << min_r_new << '\n';

			if(min_r_new-max_l_new >= 0)
				result = max(result, min_r_new-max_l_new);
		}
		cout << result << '\n';
	}


	return 0;

}

/*
4
1 3
2 6
0 4
3 3
Wynik: 1

5
2 6
1 3
0 4
1 20
0 4
Wynik: 2

3
4 5
1 2
9 20
Wynik: 0

2
3 10
1 5
Wynik: 7

*/
