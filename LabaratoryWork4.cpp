//#include <math.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#define PI 3.141592
#define E 2.718281
using namespace std;
typedef double (*ToFunction)(double, int);
double functionS(double x, int n);
double functionY(double x, int n);
double functionZ(double x, int n);
void Out_Rez(ToFunction, double a, double b, double h, int n);
double Correct_Input();
int Correct_Input_Int();

int main()
{
	double a, b, h;
	int n;
	char code;
	do {
		cout << "Please, write a = ";
		a = Correct_Input();
		cout << "Please, write b = ";
		b = Correct_Input();
		cout << "Please, write h = ";
		h = Correct_Input();
		cout << "Please, write n = ";
		n = Correct_Input_Int();
		cout << "Function Y\n";
		Out_Rez(functionY, a, b, h, n);
		cout << "Function S\n";
		Out_Rez(functionS, a, b, h, n);
		cout << "|Function Y - Function S|\n";
		Out_Rez(functionZ, a, b, h, n);
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
			cout << "Error, please write number!\n" << "Try again!" << endl;
		}
	}
	return a;
}

int Correct_Input_Int()
{
	int a;
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
			cout << "Error, please write int number!\n" << "Try again!" << endl;
		}
	}
	return a;
}

double functionS(double x, int n)
{
	double recurrent, resultS;
	resultS = 0;
	recurrent = x;
	for (int k = 1; k <= n; k++) {
		recurrent *= x;
		resultS += recurrent * cos(k * PI / 3.) / (k * x);
	}
	return resultS;
}

double functionY(double x, int n)
{
	return (-1. / 2. * log(1. - 2. * x * cos(PI / 3.) + x * x) / log(E));
}

double functionZ(double x, int n)
{
	return (fabs(functionY(x, n) - functionS(x, n)));
}

void Out_Rez(ToFunction function, double a, double b, double h, int n)
{
	for (double x = a; x <= b; x += h)
	{
		cout << "x = " << x << setw(15) << "y = " << function(x, n) << endl;
	}
}