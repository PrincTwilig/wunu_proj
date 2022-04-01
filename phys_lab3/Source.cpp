#include "Header.h"
#include <cmath>

// знаходимо hser структур b1 b2 .h[i] / 3
void average()
{
	b1.hser = (b1.h[0] + b1.h[1] + b1.h[2]) / 3;
	b2.hser = (b2.h[0] + b2.h[1] + b2.h[2]) / 3;
}

// знаходимо tser
void find_tser()
{
	b1.tser = (b1.t[0] + b1.t[1] + b1.t[2]) / 3;
	b2.tser = (b2.t[0] + b2.t[1] + b2.t[2]) / 3;
}

// шукаємо k, k = tg A1
void find_k()
{
	b1.k = tan(b1.a);
	b2.k = tan(b2.a);
}

// знаходимо A1ser  A1ser = 2 * L / tser^2
void find_A1ser()
{
	b1.A1ser = 2 * b1.L / pow(b1.tser, 2);
	b2.A1ser = 2 * b2.L / pow(b2.tser, 2);
}

// знаходимо a = g * (sin(A1) - (k * cos(A1)))
// g = 9.80665
void find_a()
{
	b1.a = 9.80665 * (sin(b1.A1) - (b1.k * cos(b1.A1)));
	b2.a = 9.80665 * (sin(b2.A1) - (b2.k * cos(b2.A1)));
}

// deltaA1ser = A1ser - A1 в модулі
void find_deltaA1ser()
{
	b1.deltaA1 = abs(b1.A1ser - b1.A1);
	b2.deltaA1 = abs(b2.A1ser - b2.A1);
}

// відносна похибка E = (deltaA1 / A1ser) * 100
void find_E()
{
	b1.E = (b1.deltaA1 / b1.A1ser) * 100;
	b2.E = (b2.deltaA1 / b2.A1ser) * 100;
}

// Шукаємо ККД N=1-k * ctg(a)
void find_N()
{
	b1.n = 1 - b1.k * tan(b1.a);
	b2.n = 1 - b2.k * tan(b2.a);
}


// меню з послідовним виконанням функцій та вибором таблиці
int menu() {
	int choice;
	// -------
	average();
	find_k();
	find_tser();
	find_A1ser();
	find_a();
	find_deltaA1ser();
	find_E();
	find_N();
	// -------
	round();
	while (true)
	{
		system("cls");
		cout << "Виберіть тіло\n1. Тіло 1\n2. Тіло 2\n0. Вихід\nВаш вибір: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			print_b1();
			break;
		case 2:
			print_b2();
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