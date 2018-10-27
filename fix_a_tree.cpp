// Fix a Tree
// http://codeforces.com/problemset/problem/698/B
/*
Rozwi?zanie
1. Znajd? zap?tlony do siebie wierzcho?ek i oznacz go jako main_root, je?li go nie ma, stw?rz go przy przerwaniu pierwszego cyklu.
2. Wykonaj dfsa.
3. Je?li wyst?pi? cykl (i nie jest to korze?), przerwij wierzcho?ek i poprowa? go do main_root (je?li takowy ju? jest), zliczaj liczb? operacji i uaktualniaj kopi? tablicy p.

Dow?d
Graf w zadaniu sk?ada si? z jednego b?d? wielu graf?w sp?jnych. W ka?dym grafie jest tylko jedna p?tla, gdy? ka?dy wierzcho?ek tworzy po??cznie tylko z jednym wierzcho?kiem.
*/






#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 200008;
int n;
int p[N_MAX];
int n_fail;
int p_correct[N_MAX];
int main_root;
bool is_main_root;

vector <int> A[N_MAX];
int color[N_MAX];
void dfs_visit(int v)
{
    color[v] = 1;
    for (int i = 0; i < A[v].size(); i++)
    {

        int u = A[v][i];
        if (color[u] == 0)
        {
            dfs_visit(u);
        }
        else if (color[u] == 1)
        {
            if (!is_main_root)
            {
                n_fail++;
                p_correct[v] = v;
                is_main_root = true;
                main_root = v;
            }

            else if (v != main_root)
            {
                n_fail++;
                p_correct[v] = main_root;
            }
        }
    }
    color[v] = 2;
}

void dfs()
{
    for (int i = 1; i <= n; i++)
    {
        color[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            dfs_visit(i);
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        p_correct[i] = p[i];
        A[i].push_back(p[i]);
        if (p[i] == i)
        {
            main_root = i;
            is_main_root = true;
        }
    }
    dfs();
    cout << n_fail << endl;
    for (int i = 1; i<= n; i++)
        cout << p_correct[i] << " ";
    cout << endl;


    return 0;
}



