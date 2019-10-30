//"Bilet"
//Prefix sum
// O(n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 100123;
ll z;
ll n;
ll k[N_MAX];

ll pref_now;
ll pref;
ll suf_now;
ll suf;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> z;
    while(z != 0)
    {
        cin >> n;
        n--;
        for (ll i = 1; i <= n; i++)
            cin >> k[i];

        for (ll i = 1; i <= n; i++)
        {
            pref_now += k[i];
            pref = max(pref_now, pref);
        }
        for (ll i = n; i >= 1; i--)
        {
            suf_now  += k[i];
            suf = max(suf_now, suf);
        }

        cout << suf+pref << '\n';

        pref_now = 0;
        suf_now = 0;
        pref = 0;
        suf = 0;
        z--;
    }

    return 0;
}
/*
2
3
-1 -1
5
3 5 5 2
*/
