#include <iostream>
#include <Windows.h>
using namespace std;

float paralelepiped[4][6] = { {55,22,8,26},{48,12,10,20.5},{38,11,8,23} };
float celindr[4][5] = { {20,56,148.5},{16,43,127},{24,67,195} };
float cil_kil[4][6] = { {18,15,39,23.8},{15,8,20,19.7},{21,16,41,42} };
float kula[4][4] = { {23,57.5},{20,55},{30,84} };

void paralelepip() {
	int a;
	system("cls");
	for (size_t i = 0; i < 3; i++) // Шукаємо ро всіх варіантів
	{
		paralelepiped[i][4] = paralelepiped[i][3] / (paralelepiped[i][0] * paralelepiped[i][1] * paralelepiped[i][2]); // це наша формула p=m/(abc)
	}
	for (size_t i = 0; i < 5; i++) // всі середні значення
	{
		paralelepiped[3][i] = (paralelepiped[0][i] + paralelepiped[1][i] + paralelepiped[2][i]) / 3;
	}
	for (size_t i = 0; i < 3; i++) // шукаємо дельта ро
	{
		paralelepiped[i][5] = paralelepiped[3][4] - paralelepiped[i][4];
		if (paralelepiped[i][5] < 0) {
			paralelepiped[i][5] = paralelepiped[i][5] * (-1);
		}
	}
	paralelepiped[3][5] = (paralelepiped[0][5] + paralelepiped[1][5] + paralelepiped[2][5]) / 3;
	cout << "Ваша таблиця Паралелепіпед тут :)\n";
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			cout << paralelepiped[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "p = " << paralelepiped[3][4] << " +- " << paralelepiped[3][5] << endl;
	cout << "E = " << paralelepiped[3][5] / paralelepiped[3][4] << "\n\n";
	cout << "Напишіть 0 щоб вернутись\n"; cin >> a;
}

void celind() {
	int a;
	system("cls");
	for (size_t i = 0; i < 3; i++) // Шукаємо ро всіх варіантів
	{
		celindr[i][3] = (4 * celindr[i][2]) / (3.14 * celindr[i][0] * celindr[i][0] * celindr[i][1]); // це наша формула p=m/(abc)
	}
	for (size_t i = 0; i < 4; i++) // всі середні значення
	{
		celindr[3][i] = (celindr[0][i] + celindr[1][i] + celindr[2][i]) / 3;
	}
	for (size_t i = 0; i < 3; i++) // шукаємо дельта ро
	{
		celindr[i][4] = celindr[3][3] - celindr[i][3];
		if (celindr[i][4] < 0) {
			celindr[i][4] = celindr[i][4] * (-1);
		}
	}
	celindr[3][4] = (celindr[0][4] + celindr[1][4] + celindr[2][4]) / 3; // дельта ро середнє
	cout << "Ваша таблиця Циліндрів тут :)\n";
	for (size_t i = 0; i < 4; i++) // звичайний вивід таблиці
	{
		for (size_t j = 0; j < 5; j++)
		{
			cout << celindr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "p = " << celindr[3][3] << " +- " << celindr[3][4] << endl;
	cout << "E = " << celindr[3][4] / celindr[3][3] << "\n\n";
	cout << "Напишіть 0 щоб вернутись\n"; cin >> a;
}

void cil_ki() {
	int a;
	system("cls");
	for (size_t i = 0; i < 3; i++) // Шукаємо ро всіх варіантів
	{
		cil_kil[i][4] = (4 * cil_kil[i][3]) / (3.14 * cil_kil[i][2] * ((cil_kil[i][0] * cil_kil[i][0]) - (cil_kil[i][1] * cil_kil[i][1]))); // це наша формула p=m/(abc)
	}
	for (size_t i = 0; i < 5; i++) // всі середні значення
	{
		cil_kil[3][i] = (cil_kil[0][i] + cil_kil[1][i] + cil_kil[2][i]) / 3;
	}
	for (size_t i = 0; i < 3; i++) // шукаємо дельта ро
	{
		cil_kil[i][5] = cil_kil[3][4] - cil_kil[i][4];
		if (cil_kil[i][5] < 0) {
			cil_kil[i][5] = cil_kil[i][5] * (-1);
		}
	}
	cil_kil[3][5] = (cil_kil[0][5] + cil_kil[1][5] + cil_kil[2][5]) / 3; // дельта ро середнє
	cout << "Ваша таблиця Циліндричного кільця тут :)\n";
	for (size_t i = 0; i < 4; i++) // звичайний вивід таблиці
	{
		for (size_t j = 0; j < 6; j++)
		{
			cout << cil_kil[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "p = " << cil_kil[3][4] << " +- " << cil_kil[3][5] << endl;
	cout << "E = " << cil_kil[3][5] / cil_kil[3][4] << "\n\n";
	cout << "Напишіть 0 щоб вернутись\n"; cin >> a;
}

void kul() {
	int a;
	system("cls");
	for (size_t i = 0; i < 3; i++) // Шукаємо ро всіх варіантів
	{
		kula[i][2] = (6 * kula[i][1]) / (3.14 * (kula[i][0] * kula[i][0] * kula[i][0])); // це наша формула p=m/(abc)
	}
	for (size_t i = 0; i < 3; i++) // всі середні значення
	{
		kula[3][i] = (kula[0][i] + kula[1][i] + kula[2][i]) / 3;
	}
	for (size_t i = 0; i < 3; i++) // шукаємо дельта ро
	{
		kula[i][3] = kula[3][2] - kula[i][2];
		if (kula[i][3] < 0) {
			kula[i][3] = kula[i][3] * (-1);
		}
	}
	kula[3][3] = (kula[0][3] + kula[1][3] + kula[2][3]) / 3; // дельта ро середнє
	cout << "Ваша таблиця Кулі тут :)\n";
	for (size_t i = 0; i < 4; i++) // звичайний вивід таблиці
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << kula[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "p = " << kula[3][2] << " +- " << kula[3][3] << endl;
	cout << "E = " << kula[3][3] / kula[3][2] << "\n\n";
	cout << "Напишіть 0 щоб вернутись\n"; cin >> a;
}

void normalize(float numer) { // просто переводимо всі значення під конкретний варіант
	for (size_t i = 0, b = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			paralelepiped[i][j] = paralelepiped[i][j] * (numer / 100) + paralelepiped[i][j];
		}
	}
	for (size_t i = 0, b = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			celindr[i][j] = celindr[i][j] * (numer / 100) + celindr[i][j];
		}
	}
	for (size_t i = 0, b = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cil_kil[i][j] = cil_kil[i][j] * (numer / 100) + cil_kil[i][j];
		}
	}
	for (size_t i = 0, b = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			kula[i][j] = kula[i][j] * (numer / 100) + kula[i][j];
		}
	}
}

void menu() {
	int some;
	while (true)
	{
		system("cls");
		cout << "Виберіть тблицю якої фігури потрібно знайти \n1. Паралелепіпед.\n2. Циліндр.\n3. Циліндричне кільце.\n4. Куля\nВиберіть: ";
		cin >> some;
		if (some == 1) {
			paralelepip();
		}
		else if (some == 2) {
			celind();
		}
		else if (some == 3) {
			cil_ki();
		}
		else if (some == 4) {
			kul();
		}
	}
}

int main() {
	float spisk;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ver 0.2" << endl;
	cout << "Прога для фізики, просто введіть свій номер в списку і все готово :)\nВведіть свій номер: ";
	cin >> spisk;
	normalize(spisk);
	menu();
}