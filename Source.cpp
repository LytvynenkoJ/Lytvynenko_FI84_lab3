#include "Header.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	cout << t << endl;
	string firstNum;
	string secondNum;
	int* first = new int[t];
	int* second = new int[t];
	int* sum = new int[t];
	int* mul = new int[t];
	int* inv = new int[t];
	int* square = new int[t];
	int* tr = new int[t];
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
	mod[2] = 1;
	mod[5] = 1;
	mod[6] = 1;
	cout << "Модуль:   ";
	outArr(mod, k+1);
	cout << endl;

	// sum
	sum = Add(first,second);
	cout << "Сумма:   ";
	outArr(sum,k);
	cout << endl;

	// multiple
	mul = mult(first,second);
	cout << "Произведение:   ";
	outArr(mul, k);
	cout << endl;

	cout << "q:   ";
	outArr(q, k);
	cout << endl;

	inv = inverse(first);
	cout << "Обратный:   ";
	outArr(inv, k);
	cout << endl;

	square = Squa(first);
	cout << "Квадрат:   ";
	outArr(square, k);
	cout << endl;

	tr = trace(first);
	cout << "След:   ";
	outArr(tr, k);
	cout << endl;

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mod;
	delete[] mul;
	delete[] square;
	delete[] tr;
	return 0;
}
