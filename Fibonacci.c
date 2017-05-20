#include<stdio.h>

/*
Dwa sposoby na policzenie n-tego wyrazu ci¹gu fibonacciego
*/


/// <summary>
/// Fibonacci policzony rekurencyjnie
/// </summary>
/// <param name="num">n-ty element ciagu</param>
/// <returns>wartosc n-tego elementu w ciagu</returns>
int fibonacci_rec(int num)
{
	if (num == 0 || num == 1)
		return num;
	else
		return fibonacci_rec(num - 1) + fibonacci_rec(num - 2);
}

/// <summary>
/// Fibonacci policzony bez uzycia rekurencji
/// </summary>
/// <param name="num">n-ty element ciagu</param>
/// <returns>wartosc n-tego elementu w ciagu</returns>
int fibonacci_norm(int num)
{
	int next = 1, prev = 1, curr=0;
	for (int i = 2; i < num; i++)
	{
		curr = next + prev;
		next = prev;
		prev = curr;
	}
	return curr;
}

int main(int argc, char *argv[])
{

	int count=0;
	int input=0;
	printf("Wprowadz numer ciagu (mniej niz 48): ");
	scanf_s("%d", &input);
	if (input > 0)
	{
		count = fibonacci_rec(input);
		printf("Wynik uzyskany rekurencyjnie: %d\n", count);
		count = fibonacci_norm(input);
		printf("Wynik uzyskany normalnie: %d\n", count);
	}
	else
	{
		printf("Podana liczba jest ujemna!");
	}

	getchar();
	getchar();
	return 0;
}