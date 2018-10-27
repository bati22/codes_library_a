// Alyona and the Tree
// http://codeforces.com/problemset/problem/682/C

/*
Rozwi?zanie
1. Przypisz wierzcho?kom kraw?d? (liczb? na niej) prowadz?c? do ich rodzic?w.
2. Wylicz najwi?ksz? ?cie?ke dla ka?dego wierzcho?ka prowadz?c? z danego wierzcho?ka do przodka (najwi?ksza, tzn. suma liczb na kraw?dziach jest najwi?ksza).
3. Wierzcho?ki, kt?rych najwi?ksza ?cie?ka jest wi?ksza ni? liczba na nich, oznacz jako odwiedzone.
4. Wykonaj dfs(1), przy okazji liczac liczbe odwiedzin w zmiennej counter/
5. result = n - counter
6. Wy?wietl result.

Dow?d
Najwi?ksza ?cie?ka to co? przypominaj?cego sum? prefiksow?: je?li ?cie?ka do dziadka(?) jest wi?ksza od 0, to dodaj j? do maksymalnej ?cie?ki. Dfs odwiedzi tylko te wierzcho?ki, z kt?rymi ma po??czenie, wi?c te kt?rych nie odwiedzi? s? tymi skasowanymi.

*/
#include <iostream>
#include <vector>
using namespace std;

const long long N_MAX = 100005;
long long n;
long long a[N_MAX];
long long p[N_MAX];
long long c[N_MAX];
long long parent[N_MAX];
bool visited[N_MAX];
long long up_edge[N_MAX];
bool delete_vertex[N_MAX];
long long counter;
long long result;

vector <long long> A[N_MAX];
void dfs_parent(long long v)
{
    visited[v] = true;
    for (long long i = 0; i < A[v].size(); i++)
    {
        long long u = A[v][i];
        if (!visited[u])
        {
            parent[u] = v;
            dfs_parent(u);
        }
    }
}

void dfs_max_edge(long long v)
{
    visited[v] = true;
    if (up_edge[parent[v]] > 0)
        up_edge[v] += up_edge[parent[v]];

    if (up_edge[v] > a[v])
    {
        delete_vertex[v] = true;
    }



    for (long long i = 0; i < A[v].size(); i++)
    {
        long long u = A[v][i];
        if (!visited[u])
        {
            parent[u] = v;
            dfs_max_edge(u);
        }
    }
}

void dfs(long long v)
{
    visited[v] = true;
    counter++;
    for (long long i = 0; i < A[v].size(); i++)
    {
        long long u = A[v][i];
        if (!visited[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    for (long long i = 2; i <= n; i++)
    {
        cin >> p[i] >> c[i];
        A[p[i]].push_back(i);
        A[i].push_back(p[i]);
    }
    dfs_parent(1);
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    /*cout << "Rodzice: " << endl;
    for (long long i = 1; i <= n; i++)
        cout << i << ": " << parent[i] << endl;
    cout << endl;*/

    for (long long i = 2; i <= n; i++)
    {
        if (parent[i] == p[i])
        {
            up_edge[i] = c[i];
        }

        else
            up_edge[p[i]] = c[i];
    }


    /*cout << "Kraw?dzie do rodzica: " << endl;
    for (long long i = 1; i <= n; i++)
        cout << i << ": " << up_edge[i] << endl;
    cout << endl;*/

    dfs_max_edge(1);
    for (long long i = 1; i <= n; i++)
        visited[i] = false;

    /*cout << "Kraw?dzie max: " << endl;
    for (long long i = 1; i <= n; i++)
        cout << i << ": " << up_edge[i] << endl;
    cout << endl;*/

    /*cout << "Do usni?cia: " << endl;
    for (long long i = 1; i <= n; i++)
        if (delete_vertex[i])
            cout << i << " ";
    cout << endl;
    cout << endl;*/


    for (long long i = 1; i <= n; i++)
        if (delete_vertex[i])
            visited[i] = true;
    dfs(1);
    result = n - counter;
    cout << result << endl;

    return 0;
}
