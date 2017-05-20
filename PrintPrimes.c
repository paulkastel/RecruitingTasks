#include<stdio.h>

/*
Zadanie polegaj�ce na tym aby wy�wietli� wszystkie liczby pierwsze z podanego zakresu i zwr�ci� ich ilo��,
co drug� liczb� wpisa� prefix S
co trzeci� liczb� wpisa� suffix T
*/

/// <summary>
/// typ bool
/// </summary>
typedef enum { false, true } bool;

/// <summary>
/// Funkcja sprawdzaj�ca czy liczba jest liczb� pierwsz�
/// </summary>
bool isPrime(int num)
{
	//liczby pierwsze nie s� <2
	if (num < 2)
		return false;
	else
	{
		//wczytaj n i zmiennej p przypisz warto�� 2
		int p = 2;
		while (true) //do skutku
		{
			//jesli p jest == n to jest to liczba pierwsza 
			if (p == num)
				return true;
			else
			{
				//jesli liczba jest podzielna przez p to nie jest pierwsza
				if (num % p == 0)
					return false;
				else p++; //zwieksz p o 1 i powrot
			}
		}
	}
}

/// <summary>
/// glowna funkcja
/// </summary>
int printPrimes(int min, int max)
{
	//licznik ilo�ci liczb pierwszych
	int counter = 0;
	for (int i = min; i <= max; i++)
	{
		bool s = false, t = false;
		if (isPrime(i))
		{
			if (counter % 2 == 0) //co druga
			{
				s = true;
			}

			if (counter % 3 == 0) //co trzecia
			{
				t = true;
			}

			if (s == true && t == true)
			{
				printf("S%dT\n", i);
				counter++;
			}
			else if (s == true && t == false)
			{
				printf("S%d\n", i);
				counter++;
			}
			else if (s == false && t == true)
			{
				printf(" %dT\n", i);
				counter++;
			}
			else
			{
				printf(" %d \n", i);
				counter++;
			}
		}
	}
	return counter; //zwroc ilosc
}


int main(int argc, char *argv[])
{
	int min=0, max=0;

	int x=0;
	printf("Podaj wartosc poczatkowa [min]: ");
	scanf_s("%d", &min);
	printf("Podaj wartosc koncowa [max]: ");
	scanf_s("%d", &max);

	if (max > min)
		x = printPrimes(min, max);

	printf("Ilosc wyswietlonych liczb: %d", x);

	getchar();
	getchar();
	return 0;
}