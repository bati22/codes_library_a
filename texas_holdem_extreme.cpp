#include <iostream>
#include <cmath>
using namespace std;

long long n;
long long t[100005];
long long roznica_pierwiastkowa;
long long indeksy_poczatkowe[100005];
long long indeksy_koncowe[100005];
long long indeks = 1;
long long s;
long long kwadrat_pierwiastka = 1;

long long maksy[1000];
long long sumy[1000];
long long pref[1000];
long long suf[1000];

long long suma_pref_suf;
long long maks;
long long suma_b2 = 0;
long long suma_b2_z_prefiksem;
long long suma_koncowa = -1000000000000;

long long sumy_wyswietlane[100005];
long long k;
long long nowa_liczba;
long long indeks_s;
long long bufor;




//void wyswietl_indeksy();
void oblicz_sume(long long i);
void oblicz_maksa(long long i);
void oblicz_pref(long long i);
void oblicz_suf(long long i);
void wyswietl_wszystko();
long long zwroc_indeks(long long indeks);

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long long i = 1; i <=n; i++)
        cin >> t[i];

    kwadrat_pierwiastka = sqrt(n);
    kwadrat_pierwiastka*=sqrt(n);
    //cout << "kwadrat_pierwiastka: " << kwadrat_pierwiastka << endl;
    roznica_pierwiastkowa = n -kwadrat_pierwiastka;
    //cout << "roznica_pierwiastkowa: " << roznica_pierwiastkowa << endl;
    s = sqrt(n);

    for (long long i = 1; i <= n; i++)
    {
        if (i%s==1)
            indeksy_poczatkowe[indeks] = i;
        else if (i%s==0)
        {
            indeksy_koncowe[indeks] = i;
            indeks++;
        }

    }
    bufor = s;
    s = n/s;
    if (n%bufor > 0)
    {
        //cout << "Indeks: " << indeks << endl;
        indeksy_koncowe[indeks] = n;
        s++;
    }


    //wyswietl_indeksy();

    for (long long i =1; i<= s; i++)
    {
        oblicz_sume(i);
        oblicz_maksa(i);
        oblicz_pref(i);
        oblicz_suf(i);
    }

    //wyswietl_wszystko();

    //cout << "Za 1. razem: " << endl;
    for (int i =1; i <= s; i++)
    {
        suma_pref_suf = suf[i] + pref[i+1];
        maks = maksy[i];
        if (suma_b2 >0)
        {
             suma_b2+=sumy[i];
             if (sumy[i] + suf[i-1] > suma_b2)
                suma_b2 = sumy[i] + suf[i-1];
        }

        else
        {
            suma_b2 = sumy[i];
            if (suf[i-1] > 0)
                suma_b2 += suf[i-1];

        }
        suma_b2_z_prefiksem = suma_b2+pref[i+1];

        //cout << i << ": " << endl;
        if (suma_pref_suf > suma_koncowa)
            suma_koncowa = suma_pref_suf;
        if (maks > suma_koncowa)
            suma_koncowa = maks;
        if (suma_b2 > suma_koncowa)
            suma_koncowa = suma_b2;
        if (suma_b2_z_prefiksem > suma_koncowa)
            suma_koncowa = suma_b2_z_prefiksem;

        //cout << "suma_pref_suf: " << suma_pref_suf << endl;
        //cout << "maks: " << maks << endl;
        //cout << "suma_b2: " << suma_b2 << endl;
        //cout << "suma_b2_z_prefiksem: " << suma_b2_z_prefiksem << endl;
        //cout << "suma_koncowa: " << suma_koncowa << endl;
    }

    //cout << "Suma ko?cowa: " << endl;
    //cout << suma_koncowa << endl;

    sumy_wyswietlane[0] = suma_koncowa;
    cin >> k;
    //cout << endl;
    //cout <<  endl;
    //cout << "Za drugim razem: " << endl;
    for (long long j = 1; j <= k; j++)
    {
        cin >> indeks >> nowa_liczba;
        indeks++;
        t[indeks] = nowa_liczba;
        indeks_s = zwroc_indeks(indeks);
        //cout << "indeks_s: " << indeks_s << endl;
        oblicz_sume(indeks_s);
        oblicz_maksa(indeks_s);
        oblicz_pref(indeks_s);
        oblicz_suf(indeks_s);

        suma_koncowa = -1000000000000;
        suma_b2 = 0;
        for (int i =1; i <= s; i++)
        {
            suma_pref_suf = suf[i] + pref[i+1];
            maks = maksy[i];
            if (suma_b2 >0)
            {
                suma_b2+=sumy[i];
                if (sumy[i] + suf[i-1] > suma_b2)
                    suma_b2 = sumy[i] + suf[i-1];
            }

            else
            {
                suma_b2 = sumy[i];
                if (suf[i-1] > 0)
                    suma_b2 += suf[i-1];

            }
            //cout << i << ": " << endl;
            suma_b2_z_prefiksem = suma_b2+pref[i+1];
            if (suma_pref_suf > suma_koncowa)
                suma_koncowa = suma_pref_suf;
            if (maks > suma_koncowa)
                suma_koncowa = maks;
            if (suma_b2 > suma_koncowa)
                suma_koncowa = suma_b2;
            if (suma_b2_z_prefiksem > suma_koncowa)
                suma_koncowa = suma_b2_z_prefiksem;

            //cout << "suma_pref_suf: " << suma_pref_suf << endl;
            //cout << "maks: " << maks << endl;
            //cout << "suma_b2: " << suma_b2 << endl;
            //cout << "suma_b2_z_prefiksem: " << suma_b2_z_prefiksem << endl;
            //cout << "suma_koncowa: " << suma_koncowa << endl;
        }
        sumy_wyswietlane[j] = suma_koncowa;
        //wyswietl_wszystko();

    }

    for (long long i = 0; i <= k; i++)
        cout << sumy_wyswietlane[i] << endl;


    return 0;
}

/*void wyswietl_indeksy()
{
    cout << "Indeksy: " << endl;
    for (long long i = 1; i <= s; i++)
        cout << i << ": " << indeksy_poczatkowe[i] << " " <<  indeksy_koncowe[i] << endl;
}*/

void oblicz_sume(long long i)
{
    long long suma = 0;
    for (long long j =indeksy_poczatkowe[i]; j <=indeksy_koncowe[i]; j++)
        suma += t[j];
    sumy[i] = suma;

}

void oblicz_maksa(long long i)
{
    long long suma = t[indeksy_poczatkowe[i]];
    long long wynik = t[indeksy_poczatkowe[i]];
    for (long long j = indeksy_poczatkowe[i]+1; j <= indeksy_koncowe[i]; j++)
    {
        if (suma > 0)
        {
            suma+= t[j];
        }

        else
        {
            suma = t[j];
        }



        if (suma > wynik)
        {
            wynik = suma;

        }

    }
    maksy[i] = wynik;
}

void oblicz_pref(long long i)
{
    long long suma = 0;
    long long wynik = -1000000000000;
    long long prefiks = t[indeksy_poczatkowe[i]];
    if (prefiks > wynik)
        wynik = prefiks;
    for (long long j =indeksy_poczatkowe[i]+1; j <=indeksy_koncowe[i]; j++)
    {
        prefiks += t[j];

        if (prefiks > wynik)
            wynik = prefiks;
    }
    pref[i]  = wynik;
}

void oblicz_suf(long long i)
{
    long long suma = 0;
    long long wynik = -1000000000000;
    long long sufiks = t[indeksy_koncowe[i]];
    if (sufiks > wynik)
        wynik = sufiks;
    for (long long j =indeksy_koncowe[i]-1; j >= indeksy_poczatkowe[i]; j--)
    {
        sufiks += t[j];

        if (sufiks > wynik)
            wynik = sufiks;
    }
    suf[i]  = wynik;
}


/*void wyswietl_wszystko()
{
    cout << "Wszystko: " << endl;
    for (long long i = 1; i <= s; i++)
    {
        cout << i << ": " << endl;
        cout << "indeksy: " << indeksy_poczatkowe[i] << " " << indeksy_koncowe[i] << endl;
        cout << "maks: " << maksy[i] << endl;
        cout << "suma: " << sumy[i] << endl;
        cout << "sufix: " << suf[i] << endl;
        cout << "prefix: " << pref[i] << endl;
        cout << endl;
        cout << endl;
    }
}
*/
long long zwroc_indeks(long long indeks)
{
    long long zwracany_indeks;
    long long dzielnik = sqrt(n);
    zwracany_indeks = (indeks/dzielnik);
    if (indeks%dzielnik>0)
        zwracany_indeks++;
    return zwracany_indeks;
}


/*
10
-3 10 -2 -9 -8 9 1 -1 5 9




9
-3 10 -2 4 -8 9 1 -1 5

9
-3 10 -2 4 -8 -4 1 -1 5

9
-3 10 -2 4 12 -4 1 -1 5

9
-3 20 -2 4 12 -4 1 -1 5


9
-3 20 -2 -8 12 -4 1 -1 5



9
-3 10 -2 -9 -8 9 1 -1 5
1
3 4




5
9 -11 22 9 15
1
4 7




