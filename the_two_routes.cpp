// K2. The Two Routes
//http://codeforces.com/group/iKIf4DVs3E/contest/206748/problem/K2
//BFS
//O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int N_MAX = 405;
int n, m;
int vertex_1, vertex_2;
int busy_time_city[N_MAX];


bool A_car[N_MAX][N_MAX];
bool visited_car[N_MAX];
int distance_car[N_MAX];
int final_distance_car;
queue <int> bfs_vertex_car;

bool A_train[N_MAX][N_MAX];
bool visited_train[N_MAX];
int distance_train[N_MAX];
int final_distance_train;
queue <int> bfs_vertex_train;

int bfs(int v, bool A[N_MAX][N_MAX], bool visited[N_MAX], int distance[N_MAX], queue <int> bfs_vertex)
{
    bfs_vertex.push(v);
    distance[v] = 0;
    visited[v] = true;

    while (!bfs_vertex.empty())
    {
        for (int i = 1; i <= n; i++)
        {
            if (A[v][i])
            {
                int w = i;
                int distance_now = distance[v]+1;
                if (!visited[w] && (w != busy_time_city[distance_now]))
                {
                    distance[w] = distance_now;
                    busy_time_city[distance_now] = w;
                    if (w == n)
                        return distance_now;
                    bfs_vertex.push(w);
                    visited[w] = true;
                }
            }
        }
        bfs_vertex.pop();
        v = bfs_vertex.front();
    }
    return -1;
}





int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            A_car[i][j] = true;

    for (int i = 0; i < m; i++)
    {
        cin >> vertex_1 >> vertex_2;
        A_car[vertex_1][vertex_2] = false;
        A_car[vertex_2][vertex_1] = false;
        A_train[vertex_1][vertex_2] = true;
        A_train[vertex_2][vertex_1] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        A_car[i][i] = false;
        A_train[i][i] = false;
    }

    final_distance_car = bfs(1, A_car, visited_car, distance_car,  bfs_vertex_car);
    final_distance_train = bfs(1, A_train, visited_train, distance_train,  bfs_vertex_train);

    if (min (final_distance_car, final_distance_train) < 0)
        cout << -1 << endl;
    else
        cout << max(final_distance_car, final_distance_train) << endl;


    return 0;
}


