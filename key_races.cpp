//Key races
//https://codeforces.com/problemset/problem/835/A
//math
//O(1)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s;
ll v1;
ll v2;
ll t1;
ll t2;

ll result_1;
ll result_2;




int main()
{
  ios_base::sync_with_stdio(0);
  cin >> s >> v1 >> v2 >> t1 >> t2;
  result_1 = t1*2+s*v1;
  result_2 = t2*2+s*v2;
  if (result_1 < result_2)
        cout << "First" << endl;
  else if (result_2 < result_1)
        cout << "Second" << endl;
  else
        cout << "Friendship" << endl;







  return 0;
}
