//Messenger
//https://codeforces.com/problemset/problem/631/D
//KMP
//O(n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n, m;
string word[N_MAX];

ll num;
string num_word;
char c;

vector <pair<char, ll> > W;
vector <pair<char, ll> > T;
pair <char, ll> this_pair;

string word_now;
string word_next;


vector <pair<char, ll> > S;

ll ps[N_MAX];
ll t;
ll beg; 
ll endi;


void conv(ll n, vector <pair<char, ll> >* X)
{
	for (int i = 0; i < n; i++)
	{
		word_now = word[i];
		int j = 0;
		num_word = "";
		while (word_now[j] >= '0' && word_now[j] <= '9')
		{
			num_word += word_now[j];
			j++;
		}

		num += atoll(num_word.c_str());
		c = word_now[word_now.size()-1];


		if (i != n-1)
			word_next = word[i+1];
		if (i == n-1 || word_now[word_now.size()-1]!=word_next[word_next.size()-1]) 
		{
			this_pair.first = c;
			this_pair.second = num;
			X->push_back(this_pair);
			num = 0;
		}
	}
}

ll result;

int main()
{
	ios_base::sync_with_stdio();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> word[i];
	conv(n, &T);

	for (int i = 0; i < m; i++)
		cin >> word[i];
	conv(m, &W);

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

		this_pair.first = '#';
		this_pair.second = '0';
		S.push_back(this_pair);

		for (unsigned int i = 1; i < T.size()-1; i++)
			S.push_back(T[i]);

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

		for (unsigned int i = 0; i < S.size(); i++)
		{
			if (ps[i] == W.size()-2)
			{
				endi = i;
				endi -= (W.size()-2);
				endi++;

				beg = endi-W.size()+1; 

				if (T[beg].first==W[0].first && 
					T[endi].first==W[W.size()-1].first &&
					T[beg].second>=W[0].second &&
					T[endi].second>= W[W.size()-1].second)
				{
					result++;
				}
					
			}
		}

	}

	cout << result << endl;


	return 0;
}

/*
5 3
3-a 2-b 4-c 3-a 2-c
2-a 2-b 1-c
Result: 1
6 1
3-a 6-b 7-a 4-c 8-e 2-a
3-a
Result: 6
5 5
1-h 1-e 1-l 1-l 1-o
1-w 1-o 1-r 1-l 1-d
Result: 0
5 1
3-a 2-b 4-c 3-a 2-c
2-c
Result: 4
5 3
2-a 1-a 2-b 3-a 4-b
2-a 1-a 2-b
Result: 2
*/
