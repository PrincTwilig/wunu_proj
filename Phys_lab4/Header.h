#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

// random generator
double random(double min, double max)
{
	return min + (max - min) * rand() / RAND_MAX;
}

// структура тіло з 3h  hсер L aсер k a 3t tсер A1сер A1 deltaA1 E,% n
struct body
{
	double h1 = 0;
	double n1[4] = { 0,0,0,0 };
	double t1[4] = { 0,0,0,0 };
	double T1[4] = { 0,0,0,0 };
	double dT1[4] = { 0,0,0,0 };
	double h2 = 0;
	double n2[4] = { 0,0,0,0 };
	double t2[4] = { 0,0,0,0 };
	double T2[4] = { 0,0,0,0 };
	double dT2[4] = { 0,0,0,0 };
	double g[2] = { 0,0 };
	double dg[2] = { 0,0 };
	double E[2] = { 0,0 };
};
// створити 3 об'єкти типу body
body b1, b2, b3;

// заповними b1 b2 b3 данними викладача
void fill()
{
	b1.h1 = 0.21;
	b1.n1[0] = 81;
	b1.n1[1] = 91;
	b1.n1[2] = 120;
	b1.t1[0] = 90;
	b1.t1[1] = 98;
	b1.t1[2] = 113;
	b1.h2 = 0.33;
	b1.n2[0] = 77;
	b1.n2[1] = 56;
	b1.n2[2] = 87;
	b1.t2[0] = 100;
	b1.t2[1] = 74;
	b1.t2[2] = 112;

	b2.h1 = 0.26;
	b2.n1[0] = 98;
	b2.n1[1] = 110.1;
	b2.n1[2] = 145.2;
	b2.t1[0] = 108.9;
	b2.t1[1] = 118.5;
	b2.t1[2] = 121.4;
	b2.h2 = 0.38;
	b2.n2[0] = 93.2;
	b2.n2[1] = 67.8;
	b2.n2[2] = 105.3;
	b2.t2[0] = 121;
	b2.t2[1] = 89.5;
	b2.t2[2] = 136;

	b3.h1 = 0.16;
	b3.n1[0] = 64;
	b3.n1[1] = 71.9;
	b3.n1[2] = 94.8;
	b3.t1[0] = 71.1;
	b3.t1[1] = 77.4;
	b3.t1[2] = 89.3;
	b3.h2 = 0.28;
	b3.n2[0] = 60.9;
	b3.n2[1] = 44.2;
	b3.n2[2] = 68.7;
	b3.t2[0] = 79;
	b3.t2[1] = 58.5;
	b3.t2[2] = 88.5;
}

// функція для переведення всіх змінних під варіант користувача
void normalize(double spisk)
{
	if (spisk != 0)
	{
		// всі змінні b1 = b1 * (spisk/100) + b1
		b1.h1 = b1.h1 * (spisk / 100) + b1.h1;
		for (int i = 0; i < 4; i++)
		{
			b1.n1[i] = b1.n1[i] * (spisk / 100) + b1.n1[i];
			b1.t1[i] = b1.t1[i] * (spisk / 100) + b1.t1[i];
			b1.T1[i] = b1.T1[i] * (spisk / 100) + b1.T1[i];
			b1.dT1[i] = b1.dT1[i] * (spisk / 100) + b1.dT1[i];
		}
		b1.h2 = b1.h2 * (spisk / 100) + b1.h2;
		for (int i = 0; i < 4; i++)
		{
			b1.n2[i] = b1.n2[i] * (spisk / 100) + b1.n2[i];
			b1.t2[i] = b1.t2[i] * (spisk / 100) + b1.t2[i];
			b1.T2[i] = b1.T2[i] * (spisk / 100) + b1.T2[i];
			b1.dT2[i] = b1.dT2[i] * (spisk / 100) + b1.dT2[i];
		}
		for (int i = 0; i < 2; i++)
		{
			b1.g[i] = b1.g[i] * (spisk / 100) + b1.g[i];
			b1.dg[i] = b1.dg[i] * (spisk / 100) + b1.dg[i];
			b1.E[i] = b1.E[i] * (spisk / 100) + b1.E[i];
		}
		// всі змінні b2 = b2 * (spisk/100) + b2
		b2.h1 = b2.h1 * (spisk / 100) + b2.h1;
		for (int i = 0; i < 4; i++)
		{
			b2.n1[i] = b2.n1[i] * (spisk / 100) + b2.n1[i];
			b2.t1[i] = b2.t1[i] * (spisk / 100) + b2.t1[i];
			b2.T1[i] = b2.T1[i] * (spisk / 100) + b2.T1[i];
			b2.dT1[i] = b2.dT1[i] * (spisk / 100) + b2.dT1[i];
		}
		b2.h2 = b2.h2 * (spisk / 100) + b2.h2;
		for (int i = 0; i < 4; i++)
		{
			b2.n2[i] = b2.n2[i] * (spisk / 100) + b2.n2[i];
			b2.t2[i] = b2.t2[i] * (spisk / 100) + b2.t2[i];
			b2.T2[i] = b2.T2[i] * (spisk / 100) + b2.T2[i];
			b2.dT2[i] = b2.dT2[i] * (spisk / 100) + b2.dT2[i];
		}
		for (int i = 0; i < 2; i++)
		{
			b2.g[i] = b2.g[i] * (spisk / 100) + b2.g[i];
			b2.dg[i] = b2.dg[i] * (spisk / 100) + b2.dg[i];
			b2.E[i] = b2.E[i] * (spisk / 100) + b2.E[i];
		}
		// всі змінні b3 = b3 * (spisk/100) + b3
		b3.h1 = b3.h1 * (spisk / 100) + b3.h1;
		for (int i = 0; i < 4; i++)
		{
			b3.n1[i] = b3.n1[i] * (spisk / 100) + b3.n1[i];
			b3.t1[i] = b3.t1[i] * (spisk / 100) + b3.t1[i];
			b3.T1[i] = b3.T1[i] * (spisk / 100) + b3.T1[i];
			b3.dT1[i] = b3.dT1[i] * (spisk / 100) + b3.dT1[i];
		}
		b3.h2 = b3.h2 * (spisk / 100) + b3.h2;
		for (int i = 0; i < 4; i++)
		{
			b3.n2[i] = b3.n2[i] * (spisk / 100) + b3.n2[i];
			b3.t2[i] = b3.t2[i] * (spisk / 100) + b3.t2[i];
			b3.T2[i] = b3.T2[i] * (spisk / 100) + b3.T2[i];
			b3.dT2[i] = b3.dT2[i] * (spisk / 100) + b3.dT2[i];
		}
		for (int i = 0; i < 2; i++)
		{
			b3.g[i] = b3.g[i] * (spisk / 100) + b3.g[i];
			b3.dg[i] = b3.dg[i] * (spisk / 100) + b3.dg[i];
			b3.E[i] = b3.E[i] * (spisk / 100) + b3.E[i];
		}
	}
}

// зробити всі змінні b1 скоротити до 4 цифр після коми
void round_b1()
{
	b1.h1 = round(b1.h1 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b1.n1[i] = round(b1.n1[i] * 10000) / 10000;
		b1.t1[i] = round(b1.t1[i] * 10000) / 10000;
		b1.T1[i] = round(b1.T1[i] * 10000) / 10000;
		b1.dT1[i] = round(b1.dT1[i] * 10000) / 10000;
	}
	b1.h2 = round(b1.h2 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b1.n2[i] = round(b1.n2[i] * 10000) / 10000;
		b1.t2[i] = round(b1.t2[i] * 10000) / 10000;
		b1.T2[i] = round(b1.T2[i] * 10000) / 10000;
		b1.dT2[i] = round(b1.dT2[i] * 10000) / 10000;
	}
	for (int i = 0; i < 2; i++)
	{
		b1.g[i] = round(b1.g[i] * 10000) / 10000;
		b1.dg[i] = round(b1.dg[i] * 10000) / 10000;
		b1.E[i] = round(b1.E[i] * 10000) / 10000;
	}
}

// зробити всі змінні b2 скоротити до 4 цифр після коми
void round_b2()
{
	b2.h1 = round(b2.h1 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b2.n1[i] = round(b2.n1[i] * 10000) / 10000;
		b2.t1[i] = round(b2.t1[i] * 10000) / 10000;
		b2.T1[i] = round(b2.T1[i] * 10000) / 10000;
		b2.dT1[i] = round(b2.dT1[i] * 10000) / 10000;
	}
	b2.h2 = round(b2.h2 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b2.n2[i] = round(b2.n2[i] * 10000) / 10000;
		b2.t2[i] = round(b2.t2[i] * 10000) / 10000;
		b2.T2[i] = round(b2.T2[i] * 10000) / 10000;
		b2.dT2[i] = round(b2.dT2[i] * 10000) / 10000;
	}
	for (int i = 0; i < 2; i++)
	{
		b2.g[i] = round(b2.g[i] * 10000) / 10000;
		b2.dg[i] = round(b2.dg[i] * 10000) / 10000;
		b2.E[i] = round(b2.E[i] * 10000) / 10000;
	}
}

// зробити всі змінні b3 скоротити до 4 цифр після коми
void round_b3()
{
	b3.h1 = round(b3.h1 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b3.n1[i] = round(b3.n1[i] * 10000) / 10000;
		b3.t1[i] = round(b3.t1[i] * 10000) / 10000;
		b3.T1[i] = round(b3.T1[i] * 10000) / 10000;
		b3.dT1[i] = round(b3.dT1[i] * 10000) / 10000;
	}
	b3.h2 = round(b3.h2 * 10000) / 10000;
	for (int i = 0; i < 4; i++)
	{
		b3.n2[i] = round(b3.n2[i] * 10000) / 10000;
		b3.t2[i] = round(b3.t2[i] * 10000) / 10000;
		b3.T2[i] = round(b3.T2[i] * 10000) / 10000;
		b3.dT2[i] = round(b3.dT2[i] * 10000) / 10000;
	}
	for (int i = 0; i < 2; i++)
	{
		b3.g[i] = round(b3.g[i] * 10000) / 10000;
		b3.dg[i] = round(b3.dg[i] * 10000) / 10000;
		b3.E[i] = round(b3.E[i] * 10000) / 10000;
	}
}



// вивести все в b1
void print_b1()
{
	system("cls");
	cout << "Table 1" << endl;
	// назви змінних таблиці
	cout << "No\tn1\tt1\tT1\tdT1\t|n2\tt2\tT2\tdT2\tg\tdg\tE" << endl;
	// вивести все в b1
	cout << 1 << "\t" << b1.n1[0] << "\t" << b1.t1[0] << "\t" << b1.T1[0] << "\t" << b1.dT1[0] << "\t|" << b1.n2[0] << "\t" << b1.t2[0] << "\t" << b1.T2[0] << "\t" << b1.dT2[0] << endl;
	cout << 2 << "\t" << b1.n1[1] << "\t" << b1.t1[1] << "\t" << b1.T1[1] << "\t" << b1.dT1[1] << "\t|" << b1.n2[1] << "\t" << b1.t2[1] << "\t" << b1.T2[1] << "\t" << b1.dT2[1] << endl;
	cout << 3 << "\t" << b1.n1[2] << "\t" << b1.t1[2] << "\t" << b1.T1[2] << "\t" << b1.dT1[2] << "\t|" << b1.n2[2] << "\t" << b1.t2[2] << "\t" << b1.T2[2] << "\t" << b1.dT2[2] << "\t" << b1.g[0] << "\t" << b1.dg[0] << "\t" << b1.E[0] << endl;
	cout << 4 << "\t" << b1.n1[3] << "\t" << b1.t1[3] << "\t" << b1.T1[3] << "\t" << b1.dT1[3] << "\t|" << b1.n2[3] << "\t" << b1.t2[3] << "\t" << b1.T2[3] << "\t" << b1.dT2[3] << "\t" << b1.g[1] << "\t" << b1.dg[1] << "\t" << b1.E[1] << endl;
	system("pause");
}

// вивести все в b2
void print_b2()
{
	system("cls");
	cout << "Table b2" << endl;
	// назви змінних таблиці
	cout << "n1\tt1\tT1\tdT1\t|n2\tt2\tT2\tdT2\tg\tdg\tE" << endl;
	// вивести все в b2
	cout << 1 << "\t" << b2.n1[0] << "\t" << b2.t1[0] << "\t" << b2.T1[0] << "\t" << b2.dT1[0] << "\t|" << b2.n2[0] << "\t" << b2.t2[0] << "\t" << b2.T2[0] << "\t" << b2.dT2[0] << endl;
	cout << 2 << "\t" << b2.n1[1] << "\t" << b2.t1[1] << "\t" << b2.T1[1] << "\t" << b2.dT1[1] << "\t|" << b2.n2[1] << "\t" << b2.t2[1] << "\t" << b2.T2[1] << "\t" << b2.dT2[1] << endl;
	cout << 3 << "\t" << b2.n1[2] << "\t" << b2.t1[2] << "\t" << b2.T1[2] << "\t" << b2.dT1[2] << "\t|" << b2.n2[2] << "\t" << b2.t2[2] << "\t" << b2.T2[2] << "\t" << b2.dT2[2] << "\t" << b2.g[0] << "\t" << b2.dg[0] << "\t" << b2.E[0] << endl;
	cout << 4 << "\t" << b2.n1[3] << "\t" << b2.t1[3] << "\t" << b2.T1[3] << "\t" << b2.dT1[3] << "\t|" << b2.n2[3] << "\t" << b2.t2[3] << "\t" << b2.T2[3] << "\t" << b2.dT2[3] << "\t" << b2.g[1] << "\t" << b2.dg[1] << "\t" << b2.E[1] << endl;
	system("pause");
}

// вивести все в b3
void print_b3()
{
	system("cls");
	cout << "Table 3" << endl;
	// назви змінних таблиці
	cout << "n1\tt1\tT1\tdT1\t|n2\tt2\tT2\tdT2\tg\tdg\tE" << endl;
	// вивести все в b3
	cout << 1 << "\t" << b3.n1[0] << "\t" << b3.t1[0] << "\t" << b3.T1[0] << "\t" << b3.dT1[0] << "\t|" << b3.n2[0] << "\t" << b3.t2[0] << "\t" << b3.T2[0] << "\t" << b3.dT2[0] << endl;
	cout << 2 << "\t" << b3.n1[1] << "\t" << b3.t1[1] << "\t" << b3.T1[1] << "\t" << b3.dT1[1] << "\t|" << b3.n2[1] << "\t" << b3.t2[1] << "\t" << b3.T2[1] << "\t" << b3.dT2[1] << endl;
	cout << 3 << "\t" << b3.n1[2] << "\t" << b3.t1[2] << "\t" << b3.T1[2] << "\t" << b3.dT1[2] << "\t|" << b3.n2[2] << "\t" << b3.t2[2] << "\t" << b3.T2[2] << "\t" << b3.dT2[2] << "\t" << b3.g[0] << "\t" << b3.dg[0] << "\t" << b3.E[0] << endl;
	cout << 4 << "\t" << b3.n1[3] << "\t" << b3.t1[3] << "\t" << b3.T1[3] << "\t" << b3.dT1[3] << "\t|" << b3.n2[3] << "\t" << b3.t2[3] << "\t" << b3.T2[3] << "\t" << b3.dT2[3] << "\t" << b3.g[1] << "\t" << b3.dg[1] << "\t" << b3.E[1] << endl;
	system("pause");
}