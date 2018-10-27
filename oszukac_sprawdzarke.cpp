 By bati, contest: Semestr letni 15-16: Zadania domowe, problem: (B3) Bajtolotek - Hard, Accepted, #

#include <iostream>
#include <cstdio>
using namespace std;

void quicksort(int t[], int n, int d, int g);
int logarytm(int liczba);
int przeszukiwanie_binarne(int t[], int indeks[], int n, int poczatek, int koniec, int szukana, int czas, int czas_max);

int main()
{
    //cout << "Ile liczb?" << endl;
    int n;
    scanf("%d", &n);

    //cout << "Wprowad? liczby do tablicy: " << endl;
    int t[n];
    int indeks1[n];
    int indeks2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);


    quicksort(t, n, 0, n-1);

    /*cout << "Posortowane: " << endl;
    for (int i =0 ; i <n; i++)
        cout << t[i] << '\t';
    cout << endl;*/

    int bufor = -1;
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (bufor != t[i])
        {
            j++;
            indeks1[j] = i;
            bufor = t[i];
            indeks2[j] = i;
        }

        else
            indeks2[j]++;
    }
    j++;

    /*cout << "Indeksy pierwsze: " << endl;
    for (int i = 0; i < j; i++)
        cout << indeks1[i] << '\t';
    cout << endl;

    cout << "Indeksy drugie: " << endl;
    for (int i = 0; i < j; i++)
        cout << indeks2[i] << '\t';
    cout << endl;*/

    //cout << "Ile liczb szukasz?"  << endl;
    int ile_szukam;
    scanf("%d", &ile_szukam);

    //cout << "Jakich szukasz?" << endl;
    int szukane[ile_szukam];
    for (int i = 0; i < ile_szukam; i++)
        scanf("%d", &szukane[i]);

    //cout << "Wyniki" << endl;
    for (int i = 0; i < ile_szukam; i++)
    {
        bufor = przeszukiwanie_binarne(t, indeks2, j, 0, j-1, szukane[i], -1, logarytm(j));
        if (bufor < 0)
        {
            printf("%d", 0);
            printf("%c", '\n');
        }

        else
        {
            printf("%d", indeks2[bufor] - indeks1[bufor] + 1 );
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

int przeszukiwanie_binarne(int t[], int indeks[], int n, int poczatek, int koniec, int szukana, int czas, int czas_max)
{
    czas++;
    if (czas > czas_max)
        return -1;

    int srodek = (poczatek + koniec)/2;
    if (szukana == t[indeks[srodek]])
    {
        return srodek;
    }

    else
    {
        if (szukana < t[indeks[srodek]])
            przeszukiwanie_binarne(t, indeks, n, poczatek, srodek-1, szukana, czas, czas_max);
        else
            przeszukiwanie_binarne(t, indeks, n, srodek+1, koniec, szukana, czas, czas_max);
    }


}

int logarytm(int liczba)
{
    int c = 0;
    int b = 1;
    while (b <= liczba)
    {
        c++;
        b*=2;
    }

    return c;
}


