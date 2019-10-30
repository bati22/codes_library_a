//Odchudzanie
//simple
//O(n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 3000123;
ll n;
ll t[N_MAX];
ll result_now;
ll result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> t[i];
    for (ll i = 1; i <= n; i++)
    {
        if(t[i-1] >= t[i])
            result_now += t[i-1]-t[i];
        else
            result_now = 0;
        result = max(result, result_now);
    }

    cout << result << '\n';

    return 0;
}
/*
5
6 7 5 4 2
*/
