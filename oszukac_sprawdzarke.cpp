//Oszukac sprawdzarke
//binsearch + sorting
// O(n log(n))

#include <iostream>
#include <cstdio>
using namespace std;

void quicksort(int t[], int n, int d, int g);
int log(int n);
int binsearch(int t[], int index[], int n, int l, int r, int x, int thisTime, int timeMax);

int main()
{
    int n;
    scanf("%d", &n);

    int t[n];
    int indexOne[n];
    int indexTwo[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);


    quicksort(t, n, 0, n-1);

    int bufor = -1;
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (bufor != t[i])
        {
            j++;
            indexOne[j] = i;
            bufor = t[i];
            indexTwo[j] = i;
        }

        else
            indexTwo[j]++;
    }
    j++;

    int nSearch;
    scanf("%d", &nSearch);

    int toFind[nSearch];
    for (int i = 0; i < nSearch; i++)
        scanf("%d", &toFind[i]);

    for (int i = 0; i < nSearch; i++)
    {
        bufor = binsearch(t, indexTwo, j, 0, j-1, toFind[i], -1, log(j));
        if (bufor < 0)
        {
            printf("%d", 0);
            printf("%c", '\n');
        }

        else
        {
            printf("%d", indexTwo[bufor] - indexOne[bufor] + 1 );
            printf("%c", '\n');
        }
    }

    return 0;
}

void quicksort(int t[], int n, int d, int g)
{
    int bufor;
    int l = d;
    int p = g;
    int v = t[(d+g) / 2];
    while (l <= p)
    {
        while (t[l] < v)
            l++;
        while (v < t[p])
            p--;
        if (l <= p)
        {
            bufor = t[l];
            t[l] = t[p];
            t[p] = bufor;
            l++;
            p--;
        }
    }

    if (d < p)
        quicksort(t, n, d, p);
    if (l < g)
        quicksort(t, n, l, g);
}

int binsearch(int t[], int index[], int n, int l, int r, int x, int thisTime, int timeMax)
{
    thisTime++;
    if (thisTime > timeMax)
        return -1;

    int mid = (l + r)/2;
    if (x == t[index[mid]])
    {
        return mid;
    }

    else
    {
        if (x < t[index[mid]])
            binsearch(t, index, n, l, mid-1, x, thisTime, timeMax);
        else
            binsearch(t, index, n, mid+1, r, x, thisTime, timeMax);
    }


}

int log(int n)
{
    int c = 0;
    int b = 1;
    while (b <= n)
    {
        c++;
        b*=2;
    }

    return c;
}
