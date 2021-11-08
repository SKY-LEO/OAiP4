#include <math.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#define PI 3.141592
#define E 2.718281
using namespace std;
typedef double (*ToFunc)(double, double);
double funS(double, double);
double funY(double, double);
double funZ(double, double);
void Out_Rez(ToFunc, double, double, double, double);
double Correct_Input();

int main()
{
	double a, b, h, n;
	char code;
	do {
		cout << "Please, write a = ";
		a = Correct_Input();
		cout << "Please, write b = ";
		b = Correct_Input();
		cout << "Please, write h = ";
		h = Correct_Input();
		cout << "Please, write n = ";
		n = Correct_Input();
		cout << "Function Y\n";
		Out_Rez(funY, a, b, h, n);
		cout << "Function S\n";
		Out_Rez(funS, a, b, h, n);
		cout << "|Function Y - Function S|\n";
		Out_Rez(funZ, a, b, h, n);
		cout << "Do you want to continue? Y/N" << endl;
		code = _getch();
	} while (code == 'Y' || code == 'y');
	return 0;
}

double Correct_Input()
{
	double a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please write numbers!\n" << "Try again!" << endl;
		}
	}
	return a;
}

double funS(double x, double n)
{
	double r, resultS;
	resultS = 0;
	r = x;
	for (int k = 1; k <= n; k++) {
		r *= x;
		resultS += r * cos(k * PI / 3.) / (k * x);
	}
	return resultS;
}

double funY(double x, double n)
{
	return (-1. / 2. * log(1 - 2 * x * cos(PI / 3.) + x * x) / log(E));
}

double funZ(double x, double n)
{
	return (fabs(funY(x, n) - funS(x, n)));
}

void Out_Rez(ToFunc f, double a, double b, double h, double n)
{
	for (double x = a; x <= b; x += h)
	{
		cout << "x = " << x << setw(15) << "y = " << f(x, n) << endl;
	}
}