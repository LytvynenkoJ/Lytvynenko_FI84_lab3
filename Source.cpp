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
	first = obnul(first,t);
	second = obnul(second, t);
	sum = obnul(sum, t);
	mul = obnul(mul, t);
	inv = obnul(inv, t);
	mod = obnul(mod, t);
	cout << "Ââåäèòå ïåðâûé ýëåìåíò:   ";
	cin >> firstNum;
	first = strToArr(firstNum);
	cout << "Ââåäèòå âòîðîé ýëåìåíò:   ";
	cin >> secondNum;
	second = strToArr(secondNum);

	//k=4
	mod[2] = 1;
	mod[5] = 1;
	mod[6] = 1;
	cout << "Ìîäóëü:   ";
	outArr(mod, k+1);
	cout << endl;

	// sum
	sum = Add(first,second);
	cout << "Ñóììà:   ";
	outArr(sum,k);
	cout << endl;

	// multiple
	mul = mult(first,second);
	cout << "Ïðîèçâåäåíèå:   ";
	outArr(mul, k);
	cout << endl;

	cout << "q:   ";
	outArr(q, k);
	cout << endl;

	inv = inverse(first);
	cout << "Îáðàòíûé:   ";
	outArr(inv, k);
	cout << endl;
	
	square = Squa(first);
	cout << "Квадрат:   ";
	outArr(square, k);
	cout << endl;

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mod;
	delete[] mul;
	return 0;
}
