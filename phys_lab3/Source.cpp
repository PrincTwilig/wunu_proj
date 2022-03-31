#include "Header.h"



// меню з послідовним виконанням функцій та вибором таблиці
int menu() {
	int choice;
	// 
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