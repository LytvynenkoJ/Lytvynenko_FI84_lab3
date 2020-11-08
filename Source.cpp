#include "Header.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	string firstNum;
	string secondNum;
	string deg;
	int* first = new int[t];
	int* second = new int[t];
	int* sum = new int[t];
	int* mul = new int[t];
	int* inv = new int[t];
	int* square = new int[t];
	int* tr = new int[t];
	int* degree = new int[t];
	degree = obnul(degree, t);
	tr = obnul(tr, t);
	first = obnul(first,t);
	second = obnul(second, t);
	sum = obnul(sum, t);
	mul = obnul(mul, t);
	inv = obnul(inv, t);
	square = obnul(square, t);
	mod = obnul(mod, t);
	cout << "Введите первый элемент:   ";
	cin >> firstNum;
	first = strToArr(firstNum);
	cout << "Введите второй элемент:   ";
	cin >> secondNum;
	second = strToArr(secondNum);

	//k=4
	mod[237] = 1;
	mod[461] = 1;
	mod[474] = 1;
	mod[475] = 1;
	mod[476] = 1;
	cout << "Модуль:   ";
	outArr(mod, k+1);
	cout << endl;

	// sum
	sum = Add(first,second);
	cout << "Сумма:   ";
	outArr(sum,k);
	cout << endl;
	cout << dec << "Время работы суммы в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	// multiple
	mul = mult(first,second);
	cout << "Произведение:   ";
	outArr(mul, k);
	cout << endl;
	cout << dec << "Время работы произведения в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	square = Squa(first);
	cout << "Квадрат:   ";
	outArr(square, k);
	cout << endl;
	cout << dec << "Время работы квадрата в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	tr = trace(first);
	cout << "След:   ";
	if (compare(tr,NulEl())==0)
	{
		cout << "0" << endl;
	}
	if (compare(tr, OneEl()) == 0)
	{
		cout << "1" << endl;
	}
	cout << dec << "Время работы функции следа в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	cout << "В какую степень вы хотите вознести первый полином? (в двоичном виде, не более чем 2^{n}-1)" << endl;
	cin >> deg;
	degree = strToArr(deg);
	degree = Degr(first, degree);
	cout << "Степень:   ";
	outArr(degree, k);
	cout << endl;
	cout << dec << "Время работы степени в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	inv = inverse(first);
	cout << "Обратный:   ";
	outArr(inv, k);
	cout << endl;
	cout << dec << "Время работы нахождения обратного в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mod;
	delete[] mul;
	delete[] square;
	delete[] tr;
	return 0;
}
