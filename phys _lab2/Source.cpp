#include <iostream>
#include <Windows.h>
using namespace std;
// створити двухвимірний масив 5 рядків по 10 елементів типу float
// h - 0
// l1,l2,l3,l4,l5 - 1,2,3,4,5
// Lser - 6
// t - 7
// Vser - 8
// delta Vser - 9

double ball[6][10] = {
	{0.83,0.31,0.33,0.31,0.29,0.30},
	{0.81,0.28,0.32,0.31,0.31,0.32},
	{0.76,0.21,0.20,0.31,0.20,0.24},
	{0.60,0.26,0.24,0.38,0.26,0.29},
	{0.82,0.16,0.16,0.24,0.16,0.19} };
// h - 0
// l1,l2,l3,l4,l5 - 1,2,3,4,5
// Lser - 6
// t - 7
// Vser - 8
// delta Vser - 9


// шукаєм всі Lser
void Lser() {
	for (size_t i = 0; i < 5; i++)
	{
		ball[i][6] = (ball[i][1] + ball[i][2] + ball[i][3] + ball[i][4] + ball[i][5]) / 5;
	}
}


// шукаєм всі t
void ti() {
	for (size_t i = 0; i < 5; i++)
	{
		// t = sqrt(2*ball[i][0]/g)
		ball[i][7] = sqrt(2 * ball[i][0] / 9.81);
	}
}

// початкова швидкість ball[i][6]/ball[i][7]
void Vser() {
	for (size_t i = 0; i < 5; i++)
	{
		ball[i][8] = ball[i][6] / ball[i][7];
	}
	// середнє значення початкової швидкості
	ball[5][8] = (ball[0][8] + ball[1][8] + ball[2][8] + ball[3][8] + ball[4][8]) / 5;
}

// пошук похибки початкової швидкості ball[5][8] - ball[i][8]
void deltaVser() {
	for (size_t i = 0; i < 5; i++)
	{
		ball[i][9] = ball[5][8] - ball[i][8];
		// ball[i][9] за модулем
		if (ball[i][9] < 0)
		{
			ball[i][9] = ball[i][9] * (-1);
		}
	}
	// середнє значення похибки початкової швидкості
	ball[5][9] = (ball[0][9] + ball[1][9] + ball[2][9] + ball[3][9] + ball[4][9]) / 5;
}

// додати всі lser та всі t і поділити їх
bool Lser_t() {
	// lср1 : lср2 : lср3 : lср4,: lср5 = t1 : t2 : t3 : t4 : t5
	if (ball[0][6] / ball[1][6] / ball[2][6] / ball[3][6] / ball[4][6] == ball[0][7] / ball[1][7] / ball[2][7] / ball[3][7] / ball[4][7]) {
		cout << "ok";
		return true;
	}
	return false;
}




void normalize(float numer) { // просто переводимо всі значення під конкретний варіант
	for (size_t i = 0, b = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			ball[i][j] = ball[i][j] * (numer / 100) + ball[i][j];
		}
	}
}

// print ball
void print_ball() {
	cout << "0.h\t1.l\t2.l\t3.l\t4.l\t5.l\t6.lser\t7.t\t\t8.V0\t9.deltaV0\n";
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << ball[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "V0ser: " << ball[5][8] << endl;
	cout << "deltaV0ser: " << ball[5][9] << "\n\n";
	// вивести v0ser +- deltaV0ser
	cout << "V0: " << ball[5][8] << " +- " << ball[5][9] << endl;
	cout << "E: " << ball[5][9] / ball[5][8] << "\n\n";
	// вивести lср1 : lср2 : lср3 : lср4,: lср5 = t1 : t2 : t3 : t4 : t5
	cout << "vidnosenia   lср1 : lср2 : lср3 : lср4,: lср5 = t1 : t2 : t3 : t4 : t5: " << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << ball[i][6];
		// i != 4 ? " : " : " = "
		if (i != 4)
		{
			cout << " : ";
		}
		else
		{
			cout << " = ";
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		cout << ball[i][7];
		// i != 4 ? " : " : " = "
		if (i != 4)
		{
			cout << " : ";
		}
	}
	cout << endl;
	cout << ball[0][6] / ball[1][6] / ball[2][6] / ball[3][6] / ball[4][6] << " = " << ball[0][7] / ball[1][7] / ball[2][7] / ball[3][7] / ball[4][7] << endl;
	if (ball[0][6] / ball[1][6] / ball[2][6] / ball[3][6] / ball[4][6] == ball[0][7] / ball[1][7] / ball[2][7] / ball[3][7] / ball[4][7]) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	cout << endl;
}

void menu() {
	Lser();
	ti();
	Vser();
	deltaVser();
	print_ball();
	system("pause");
}

int main() {
	float spisk;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ver 0.1" << endl;
	cout << "Прога для фізики, просто введіть свій номер в списку (якщо ви перший, то введіть 0) і все готово :)\nВведіть свій номер: ";
	cin >> spisk;
	normalize(spisk);
	menu();
}