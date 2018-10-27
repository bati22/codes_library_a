#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n, m;
string wyraz[N_MAX];

ll liczba;
string liczba_wyraz;
char znak;

vector <pair<char, ll> > W;
vector <pair<char, ll> > T;
pair <char, ll> para;

string wyraz_now;
string wyraz_next;


vector <pair<char, ll> > S;

ll ps[N_MAX];
ll t;
ll pocz, kon;


void konwert(ll n, vector <pair<char, ll> >* X)
{
	for (int i = 0; i < n; i++)
	{
		wyraz_now = wyraz[i];
		int j = 0;
		liczba_wyraz = "";
		while (wyraz_now[j] >= '0' && wyraz_now[j] <= '9')
		{
			liczba_wyraz += wyraz_now[j];
			j++;
		}

		liczba += atoll(liczba_wyraz.c_str());
		znak = wyraz_now[wyraz_now.size()-1];


		if (i != n-1)
			wyraz_next = wyraz[i+1];
		if (i == n-1 || wyraz_now[wyraz_now.size()-1]!=wyraz_next[wyraz_next.size()-1]) // koniec takich samychl literek, wiec musze dodac pare
		{
			para.first = znak;
			para.second = liczba;
			X->push_back(para);
			liczba = 0;
		}
	}
}

ll result;

int main()
{
	ios_base::sync_with_stdio();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> wyraz[i];
	konwert(n, &T);

	for (int i = 0; i < m; i++)
		cin >> wyraz[i];
	konwert(m, &W);

	/*cout << "Tekst: " << endl;
	for (unsigned int i = 0; i < T.size(); i++)
		cout << T[i].first << " " << T[i].second << endl;
	cout << endl;*/

	/*cout << "Wzorzec: " << endl;
	for (unsigned int i = 0; i < W.size(); i++)
		cout << W[i].first << " " << W[i].second << endl;
	cout << endl;*/


	if (W.size()==1)
	{
		for (unsigned int i = 0; i < T.size(); i++)
		{
			if (W[0].first==T[i].first && T[i].second>=W[0].second)
				result += (T[i].second-W[0].second+1);
		}
	}

	else if (W.size()==2)
	{
		for (unsigned int i = 1; i < T.size(); i++)
		{
			if (
				(W[0].first==T[i-1].first) &&
				(W[1].first==T[i].first) &&
				(W[0].second<=T[i-1].second) &&
				(W[1].second<=T[i].second)
				)
			{
				result++;
			}
		}
	}

	else
	{
		for (unsigned int i = 1; i < W.size()-1; i++)
			S.push_back(W[i]);

		para.first = '#';
		para.second = '0';
		S.push_back(para);

		for (unsigned int i = 1; i < T.size()-1; i++)
			S.push_back(T[i]);

		/*cout << "S: " << endl;
		for (unsigned int i = 0; i < S.size(); i++)
			cout << S[i].first;
		cout << endl;
		cout << endl;*/

		ps[0] = 0;
		t = ps[0];
		for (unsigned int i = 1; i < S.size(); i++)
		{
			while(t>0 && S[i] != S[t])
				t = ps[t-1];
			if (S[t] == S[i])
				t++;
			ps[i] = t;
		}

		/*cout << "ps: " << endl;
		for (unsigned int i = 0; i < S.size(); i++)
			cout << ps[i] << " ";
		cout << endl;
		cout << endl;*/

		for (unsigned int i = 0; i < S.size(); i++)
		{
			if (ps[i] == W.size()-2)
			{
				kon = i;
				kon -= (W.size()-2);
				kon++;

				pocz = kon-W.size()+1; 

				if (T[pocz].first==W[0].first && 
					T[kon].first==W[W.size()-1].first &&
					T[pocz].second>=W[0].second &&
					T[kon].second>= W[W.size()-1].second)
				{
					result++;
				}
					
			}
		}

	}

	//cout << "Wynik: " << endl;
	cout << result << endl;


	return 0;
}

/*
5 3
3-a 2-b 4-c 3-a 2-c
2-a 2-b 1-c
Wynik: 1


6 1
3-a 6-b 7-a 4-c 8-e 2-a
3-a
Wynik: 6

5 5
1-h 1-e 1-l 1-l 1-o
1-w 1-o 1-r 1-l 1-d
Wynik: 0

5 1
3-a 2-b 4-c 3-a 2-c
2-c
Wynik: 4

5 3
2-a 1-a 2-b 3-a 4-b
2-a 1-a 2-b
Wynik: 2


*/
