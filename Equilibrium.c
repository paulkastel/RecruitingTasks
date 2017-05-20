#include<stdio.h>
#include <stdlib.h>

//rozmiar 
#define TAB_SIZE 9

/*
For example, consider the following array A consisting of N = 8 elements:

A[0] = -1
A[1] =  3
A[2] = -4
A[3] =  5
A[4] =  1
A[5] = -6
A[6] =  2
A[7] =  1

P = 1 is an equilibrium index of this array, because:
A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]

P = 3 is an equilibrium index of this array, because:
A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]

P = 7 is also an equilibrium index, because:
A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0

and there are no elements with indices greater than 7.

P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P < N.
*/

/// <summary>
/// Sumuje elementy w tablicy z zadanego przedzialu
/// </summary>
/// <param name="tab">Tablica z elementami</param>
/// <param name="t_size">Rozmiar tablicy</param>
/// <param name="index">indeks elementu od ktorego mam zliczac</param>
/// <returns>Sume elementow od indeksu do konca</returns>
int sumFromIndexTillEnd(int tab[], int t_size, int index)
{
	int sum = 0;
	for (int i = index; i < t_size; i++)
	{
		sum += tab[i];
	}
	return sum;
}

/// <summary>
/// Sumuje elementy w tablicy z zadanego przedzialu
/// </summary>
/// <param name="tab">tablica z elementami</param>
/// <param name="index">indeks elementu do ktorego ma sumowac</param>
/// <returns>suma elementow od zera do indeksu</returns>
int sumFromZeroTillIndex(int tab[], int index)
{
	int sum = 0;
	for (int i = 0; i < index; i++)
	{
		sum += tab[i];
	}
	return sum;
}

/// <summary>
/// Funkcja pozwalająca losować liczby z dowolnego zakresu.
/// </summary>
/// <param name="min">dolny przedzial</param>
/// <param name="max">gorny przedzial</param>
/// <returns>Losowa liczba</returns>
int random(int min, int max)
{
	int tmp;
	if (max >= min)
		max -= min;
	else
	{
		tmp = min - max;
		min = max;
		max = tmp;
	}
	return max ? (rand() % max + min) : min;
}

//===============================================
int main(int argc, char *argv[])
{
	int tab[TAB_SIZE];

	//losowe
	time_t tt;
	int seed = time(&tt);
	srand(seed);
	
	printf("Zawartosc tablicy: ");
	for (int i = 0; i < TAB_SIZE; i++)
	{
		//wypelnij tablice elementami losowymi z przedzialu od -5 do 5
		tab[i] = random(-5, 5);
		//wypisz
		printf("%d ", tab[i]);
	}
	printf("\nPunkty rownowagi sa w indeksach: ");
	
	//od 0 do rozmiaru tablicy
	for (int i = 0; i < sizeof(tab) / sizeof(int); i++)
	{
		//jezeli jest punkt rownowagi to wypisz
		if (sumFromZeroTillIndex(tab, i+1) == sumFromIndexTillEnd(tab, sizeof(tab)/sizeof(int), i))
		{
			printf("%d ", i);
		}
	}

	getchar();
	return 0;
}