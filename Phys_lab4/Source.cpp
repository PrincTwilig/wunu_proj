#include "Header.h"
#include <cmath>


// заокруглити до цілих чисел всі n з b1 b2 b3
void round_n()
{
	for (int i = 0; i < 3; i++)
	{
		b1.n1[i] = round(b1.n1[i]);
		b1.n2[i] = round(b1.n2[i]);
		b2.n1[i] = round(b2.n1[i]);
		b2.n2[i] = round(b2.n2[i]);
		b3.n1[i] = round(b3.n1[i]);
		b3.n2[i] = round(b3.n2[i]);
	}
}

// Знаходимо всі T1 в таблицях T1 = t1 / n1
void findT1()
{
	for (int i = 0; i < 3; i++)
	{
		b1.T1[i] = b1.t1[i] / b1.n1[i];
		b1.T2[i] = b1.t2[i] / b1.n2[i];
		b2.T1[i] = b2.t1[i] / b2.n1[i];
		b2.T2[i] = b2.t2[i] / b2.n2[i];
		b3.T1[i] = b3.t1[i] / b3.n1[i];
		b3.T2[i] = b3.t2[i] / b3.n2[i];
	}
}

// Знаходимо середнє значення всіх T1 та T2
void findTser()
{
	b1.T1[3] = (b1.T1[0] + b1.T1[1] + b1.T1[2]) / 3;
	b1.T2[3] = (b1.T2[0] + b1.T2[1] + b1.T2[2]) / 3;
	b2.T1[3] = (b2.T1[0] + b2.T1[1] + b2.T1[2]) / 3;
	b2.T2[3] = (b2.T2[0] + b2.T2[1] + b2.T2[2]) / 3;
	b3.T1[3] = (b3.T1[0] + b3.T1[1] + b3.T1[2]) / 3;
	b3.T2[3] = (b3.T2[0] + b3.T2[1] + b3.T2[2]) / 3;
}

// Знаходимо середнє значення всіх n1 та n2 і t1 та t2
void findser_n_t()
{
	b1.n1[3] = (b1.n1[0] + b1.n1[1] + b1.n1[2]) / 3;
	b1.n2[3] = (b1.n2[0] + b1.n2[1] + b1.n2[2]) / 3;
	b1.t1[3] = (b1.t1[0] + b1.t1[1] + b1.t1[2]) / 3;
	b1.t2[3] = (b1.t2[0] + b1.t2[1] + b1.t2[2]) / 3;
	b2.n1[3] = (b2.n1[0] + b2.n1[1] + b2.n1[2]) / 3;
	b2.n2[3] = (b2.n2[0] + b2.n2[1] + b2.n2[2]) / 3;
	b2.t1[3] = (b2.t1[0] + b2.t1[1] + b2.t1[2]) / 3;
	b2.t2[3] = (b2.t2[0] + b2.t2[1] + b2.t2[2]) / 3;
	b3.n1[3] = (b3.n1[0] + b3.n1[1] + b3.n1[2]) / 3;
	b3.n2[3] = (b3.n2[0] + b3.n2[1] + b3.n2[2]) / 3;
	b3.t1[3] = (b3.t1[0] + b3.t1[1] + b3.t1[2]) / 3;
	b3.t2[3] = (b3.t2[0] + b3.t2[1] + b3.t2[2]) / 3;
}

// Знаходимо всі dT1 в таблицях dT1 = 0.05/n1
void find_dT1()
{
	for (size_t i = 0; i < 3; i++)
	{
		b1.dT1[i] = 0.05 / b1.n1[i];
		b1.dT2[i] = 0.05 / b1.n2[i];
		b2.dT1[i] = 0.05 / b2.n1[i];
		b2.dT2[i] = 0.05 / b2.n2[i];
		b3.dT1[i] = 0.05 / b3.n1[i];
		b3.dT2[i] = 0.05 / b3.n2[i];
	}
}

// Знаходимо dT1 dT2 середнього значення
void find_dTser()
{
	b1.dT1[3] = (b1.dT1[0] + b1.dT1[1] + b1.dT1[2]) / 3;
	b1.dT2[3] = (b1.dT2[0] + b1.dT2[1] + b1.dT2[2]) / 3;
	b2.dT1[3] = (b2.dT1[0] + b2.dT1[1] + b2.dT1[2]) / 3;
	b2.dT2[3] = (b2.dT2[0] + b2.dT2[1] + b2.dT2[2]) / 3;
	b3.dT1[3] = (b3.dT1[0] + b3.dT1[1] + b3.dT1[2]) / 3;
	b3.dT2[3] = (b3.dT2[0] + b3.dT2[1] + b3.dT2[2]) / 3;
}

// Знаходимо g = 4pi^2 * ((h2-h1)/(T1^2 - T2^2))
void fing_g()
{
	for (size_t i = 0; i < 3; i++)
	{
		b1.g[i] = 4 * 3.1415 * 3.1415 * ((b1.h2 - b1.h1) / (b1.T1[i] * b1.T1[i] - b1.T2[i] * b1.T2[i]));
		b2.g[i] = 4 * 3.1415 * 3.1415 * ((b2.h2 - b2.h1) / (b2.T1[i] * b2.T1[i] - b2.T2[i] * b2.T2[i]));
		b3.g[i] = 4 * 3.1415 * 3.1415 * ((b3.h2 - b3.h1) / (b3.T1[i] * b3.T1[i] - b3.T2[i] * b3.T2[i]));
	}
	// та g середнє за формулою g = 4pi^2 * ((h2-h1)/(T1сер^2 - T2сер^2))
	b1.g[3] = 4 * 3.1415 * 3.1415 * ((b1.h2 - b1.h1) / (b1.T1[3] * b1.T1[3] - b1.T2[3] * b1.T2[3]));
	b2.g[3] = 4 * 3.1415 * 3.1415 * ((b2.h2 - b2.h1) / (b2.T1[3] * b2.T1[3] - b2.T2[3] * b2.T2[3]));
	b3.g[3] = 4 * 3.1415 * 3.1415 * ((b3.h2 - b3.h1) / (b3.T1[3] * b3.T1[3] - b3.T2[3] * b3.T2[3]));
}

// Знаходимо dg
void find_dg()
{
	for (size_t i = 0; i < 3; i++)
	{
		b1.dg[i] = abs(b1.g[3] - b1.g[i]);
		b2.dg[i] = abs(b2.g[3] - b2.g[i]);
		b3.dg[i] = abs(b3.g[3] - b3.g[i]);
	}
	// Та dg середнє
	b1.dg[3] = (b1.dg[0] + b1.dg[1] + b1.dg[2]) / 3;
	b2.dg[3] = (b2.dg[0] + b2.dg[1] + b2.dg[2]) / 3;
	b3.dg[3] = (b3.dg[0] + b3.dg[1] + b3.dg[2]) / 3;
}


// меню з послідовним виконанням функцій та вибором таблиці
int menu() {
	int choice;
	// -------
	round_n();
	findT1();
	findTser();
	findser_n_t();
	find_dT1();
	find_dTser();
	fing_g();
	find_dg();
	// -------
	round_b1();
	round_b2();
	round_b3();
	while (true)
	{
		system("cls");
		cout << "Виберіть тіло\n1. Тіло 1\n2. Тіло 2\n3. Тіло 3\n0. Вихід\nВаш вибір: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			print_b1();
			break;
		case 2:
			print_b2();
			break;
		case 3:
			print_b3();
			break;
		case 0:
			return 0;
		}
	}
}

int main()
{
	srand(time(NULL));
	fill();
	double spisk;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ver 0.1" << endl;
	cout << "Прога для фізики, просто введіть свій номер в списку (якщо ви перший, то введіть 0) і все готово :)\nВведіть свій номер: ";
	cin >> spisk;
	normalize(spisk);
	menu();
}