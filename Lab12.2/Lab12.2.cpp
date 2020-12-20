#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* first);
int Process(Elem* L, int n);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;

	bool action;
	Info info, N;

	do
	{
		cout << "Введіть кількість елементів списку: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << "Введіть дані: "; cin >> info;
		Enqueue(first, last, info);
	}

	cout << "Елементи черги: "; Print(first); cout << endl;
	cout << "Кількість елементів списку з непарними значеннями інформаційного поля: " << Process(first, 0);;
	Process(first, 0);

	return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
void Print(Elem* L)
{
	if (L != NULL)
	{
		cout << L->info << " ";
		return Print(L->link);
	}
}
int Process(Elem* L, int n)
{
	if (L != NULL)
	{
		if (L->info % 2 != 0)
		{
			return Process(L->link, n + 1);
		}

		return Process(L->link, n);  //6 - забезпечує переміщення по списку
	}
	return n;
}