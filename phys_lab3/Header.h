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
	double h[3] = { 0,0,0 };
	double hser = 0;
	double L = 0;
	double aser = 0;
	double k = 0;
	double a = 0;
	double t[3] = { 0,0,0 };
	double tser = 0;
	double A1ser = 0;
	double A1 = 0;
	double deltaA1 = 0;
	double E = 0;
	double n = 0;
};
// створити 2 об'єкти типу body
body b1, b2;

// заповними b1 b2 данними викладача
void fill()
{
	b1.h[0] = 0.5;
	b1.h[1] = 0.5;
	b1.h[2] = 0.5;
	b1.hser = 0.5;
	b1.L = 0.5;
	b1.aser = 0.5;
	b1.k = 0.5;
	b1.a = 0.5;
	b1.t[0] = 0.5;
	b1.t[1] = 0.5;
	b1.t[2] = 0.5;
	b1.tser = 0.5;
	b1.A1ser = 0.5;
	b1.A1 = 0.5;
	b1.deltaA1 = 0.5;
	b1.E = 0.5;
	b1.n = 0.5;

	b2.h[0] = 0.5;
	b2.h[1] = 0.5;
	b2.h[2] = 0.5;
	b2.hser = 0.5;
	b2.L = 0.5;
	b2.aser = 0.5;
	b2.k = 0.5;
	b2.a = 0.5;
	b2.t[0] = 0.5;
	b2.t[1] = 0.5;
	b2.t[2] = 0.5;
	b2.tser = 0.5;
	b2.A1ser = 0.5;
	b2.A1 = 0.5;
	b2.deltaA1 = 0.5;
	b2.E = 0.5;
	b2.n = 0.5;
}

// якщо spisk != 0 то всі змінні b1 b2 = b1 b2 * (spisk/100) + b1 b2
void normalize(double spisk)
{
	if (spisk != 0)
	{
		b1.h[0] = b1.h[0] * (spisk / 100) + b1.h[0];
		b1.h[1] = b1.h[1] * (spisk / 100) + b1.h[1];
		b1.h[2] = b1.h[2] * (spisk / 100) + b1.h[2];
		b1.hser = b1.hser * (spisk / 100) + b1.hser;
		b1.L = b1.L * (spisk / 100) + b1.L;
		b1.aser = b1.aser * (spisk / 100) + b1.aser;
		b1.k = b1.k * (spisk / 100) + b1.k;
		b1.a = b1.a * (spisk / 100) + b1.a;
		b1.t[0] = b1.t[0] * (spisk / 100) + b1.t[0];
		b1.t[1] = b1.t[1] * (spisk / 100) + b1.t[1];
		b1.t[2] = b1.t[2] * (spisk / 100) + b1.t[2];
		b1.tser = b1.tser * (spisk / 100) + b1.tser;
		b1.A1ser = b1.A1ser * (spisk / 100) + b1.A1ser;
		b1.A1 = b1.A1 * (spisk / 100) + b1.A1;
		b1.deltaA1 = b1.deltaA1 * (spisk / 100) + b1.deltaA1;
		b1.E = b1.E * (spisk / 100) + b1.E;
		b1.n = b1.n * (spisk / 100) + b1.n;
		b2.h[0] = b2.h[0] * (spisk / 100) + b2.h[0];
		b2.h[1] = b2.h[1] * (spisk / 100) + b2.h[1];
		b2.h[2] = b2.h[2] * (spisk / 100) + b2.h[2];
		b2.hser = b2.hser * (spisk / 100) + b2.hser;
		b2.L = b2.L * (spisk / 100) + b2.L;
		b2.aser = b2.aser * (spisk / 100) + b2.aser;
		b2.k = b2.k * (spisk / 100) + b2.k;
		b2.a = b2.a * (spisk / 100) + b2.a;
		b2.t[0] = b2.t[0] * (spisk / 100) + b2.t[0];
		b2.t[1] = b2.t[1] * (spisk / 100) + b2.t[1];
		b2.t[2] = b2.t[2] * (spisk / 100) + b2.t[2];
		b2.tser = b2.tser * (spisk / 100) + b2.tser;
		b2.A1ser = b2.A1ser * (spisk / 100) + b2.A1ser;
		b2.A1 = b2.A1 * (spisk / 100) + b2.A1;
		b2.deltaA1 = b2.deltaA1 * (spisk / 100) + b2.deltaA1;
		b2.E = b2.E * (spisk / 100) + b2.E;
		b2.n = b2.n * (spisk / 100) + b2.n;
	}
}

// зробити щоб всі змінні b1 b2 мали 5 цифри після коми
void round()
{
	b1.h[0] = round(b1.h[0] * 100000) / 100000;
	b1.h[1] = round(b1.h[1] * 100000) / 100000;
	b1.h[2] = round(b1.h[2] * 100000) / 100000;
	b1.hser = round(b1.hser * 100000) / 100000;
	b1.L = round(b1.L * 100000) / 100000;
	b1.aser = round(b1.aser * 100000) / 100000;
	b1.k = round(b1.k * 100000) / 100000;
	b1.a = round(b1.a * 100000) / 100000;
	b1.t[0] = round(b1.t[0] * 100000) / 100000;
	b1.t[1] = round(b1.t[1] * 100000) / 100000;
	b1.t[2] = round(b1.t[2] * 100000) / 100000;
	b1.tser = round(b1.tser * 100000) / 100000;
	b1.A1ser = round(b1.A1ser * 100000) / 100000;
	b1.A1 = round(b1.A1 * 100000) / 100000;
	b1.deltaA1 = round(b1.deltaA1 * 100000) / 100000;
	b1.E = round(b1.E * 100000) / 100000;
	b1.n = round(b1.n * 100000) / 100000;
	b2.h[0] = round(b2.h[0] * 100000) / 100000;
	b2.h[1] = round(b2.h[1] * 100000) / 100000;
	b2.h[2] = round(b2.h[2] * 100000) / 100000;
	b2.hser = round(b2.hser * 100000) / 100000;
	b2.L = round(b2.L * 100000) / 100000;
	b2.aser = round(b2.aser * 100000) / 100000;
	b2.k = round(b2.k * 100000) / 100000;
	b2.a = round(b2.a * 100000) / 100000;
	b2.t[0] = round(b2.t[0] * 100000) / 100000;
	b2.t[1] = round(b2.t[1] * 100000) / 100000;
	b2.t[2] = round(b2.t[2] * 100000) / 100000;
	b2.tser = round(b2.tser * 100000) / 100000;
	b2.A1ser = round(b2.A1ser * 100000) / 100000;
	b2.A1 = round(b2.A1 * 100000) / 100000;
	b2.deltaA1 = round(b2.deltaA1 * 100000) / 100000;
	b2.E = round(b2.E * 100000) / 100000;
	b2.n = round(b2.n * 100000) / 100000;
}


// вивести все в b1
void print_b1()
{
	system("cls");
	// назви змінних таблиці
	cout << "No\th\thser\tL\taser\tk\ta\tt\ttser\tA1ser\tA1\tdeltaA1\tE\tn" << endl;
	// вивести все в b1
	cout << "1.\t" << b1.h[0] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << b1.t[0] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << endl;
	cout << "2.\t" << b1.h[1] << '\t' << b1.hser << '\t' << b1.L << '\t' << b1.aser << '\t' << b1.k << '\t' << b1.a << '\t' << b1.t[1] << '\t' << b1.tser << '\t' << b1.A1ser << '\t' << b1.A1 << '\t' << b1.deltaA1 << '\t' << b1.E << '\t' << b1.n << endl;
	cout << "3.\t" << b1.h[2] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << b1.t[2] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << endl;
	system("pause");
}

// вивести все в b2
void print_b2()
{
	system("cls");
	// назви змінних таблиці
	cout << "No\th\thser\tL\taser\tk\ta\tt\ttser\tA1ser\tA1\tdeltaA1\tE\tn" << endl;
	// вивести все в b2
	cout << "1.\t" << b2.h[0] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << b2.t[0] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << endl;
	cout << "2.\t" << b2.h[1] << '\t' << b2.hser << '\t' << b2.L << '\t' << b2.aser << '\t' << b2.k << '\t' << b2.a << '\t' << b2.t[1] << '\t' << b2.tser << '\t' << b2.A1ser << '\t' << b2.A1 << '\t' << b2.deltaA1 << '\t' << b2.E << '\t' << b2.n << endl;
	cout << "3.\t" << b2.h[2] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << b2.t[2] << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << '\t' << ' ' << endl;
	system("pause");
}