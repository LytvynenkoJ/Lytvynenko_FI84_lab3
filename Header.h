#pragma once
#include <iostream>
#include "locale.h"
using namespace std;
int k = 4;
int t = 2*k-1;
int* mod = new int[t];
int* q = new int[t];


int* obnul(int arr[], int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int* NulEl()
{
	int* arr = new int[t];
	obnul(arr, t);
	return arr;
}
int* OneEl()
{
	int* arr = new int[t];
	obnul(arr, t);
	arr[t - 1] = 1;
	return arr;
}
int stringTo2(char letter)
{
	switch (letter)
	{
	case '0': return 0;
	case '1':return 1;
	}
	return -1;
}
int* strToArr(string num)
{
	int* arr = new int[t];
	arr = obnul(arr, t);
	if (num.size()>k)
	{
		cout << "Error 404: Вы ввели некорректное значение (слишком длинное)" << endl;
		exit(0);
	}
	for (int i = 1; i < num.size()+1; i++)
	{
		if(stringTo2(num[num.size() - i])!=-1)
			arr[t - i] = stringTo2(num[num.size()-i]);
		else
		{
			cout << "Error 404: Вы ввели некорректное значение (таких коэффициентов нет в поле характеристики 2)" << endl;
			exit(0);
		}
	}
	return arr;
}
void outArr(int arr[], int c)
{
	for (int i = t-c; i < t; i++)
	{
		cout << arr[i];
	}
}
int compare(int first[], int second[])
{
	for (int i = 0; i < t; i++)
	{
		if (first[i] > second[i]) return 1;
		if (first[i] < second[i]) return 2;
	}
	return 0;
}
int high(int num[])
{
	int h = -1;
	for (int i = 0; i < t; i++)
	{
		if (num[i] != 0)
		{
			h = t-i;
			i = t;
		}
	}
	return h;
}
int* Add(int first[], int second[])
{
	int* sum = new int[t];
	obnul(sum,t);
	for (int i = 0; i < t; i++)
	{
		sum[i] = (first[i] + second[i])%2;
	}
	return sum;
}
int* module(int num[],int m[])
{
	int* arr = new int[t];
	obnul(arr, t);
	obnul(q, t);
	if (high(num) <= high(m))
	{
		q[t - 1] = 1;
	}
	while (high(num)>=high(m))
	{
		arr = obnul(arr, t);
		int a = high(num);
		int b = high(m);
		int he = a - b;
		q[t - 1 - he] = 1;
		for (int i = 0; i < t-he; i++)
		{
			arr[i] = m[i + he];
		}
		num = Add(num,arr);
	}
	return num;
}
int* mult(int first[], int second[])
{
	int* mul = new int[t];
	mul = obnul(mul,t);
	int* arr = new int[t];
	for (int i = t-k; i < t; i++)
	{
		if (second[i]==1)
		{
			arr = obnul(arr, t);
			for (int j = 0; j < i+1; j++)
			{
				arr[j] = first[j+(t-i-1)];
			}
			mul = Add(mul,arr);
		}
	}
	mul = module(mul,mod);
	return mul;
}
int* inverse(int num[])
{
	int* inv = new int[t];
	inv = obnul(inv, t);
	int* a = new int[t];
	a = obnul(a, t);
	int* b = new int[t];
	b = obnul(b, t);
	int* m = new int[t];
	m = obnul(m, t);
	int* one = new int[t];
	one = NulEl();
	int* two = new int[t];
	two = OneEl();
	for (int i = 0; i < t; i++)
	{
		a[i] = mod[i];
	}
	m = module(a, num);
	while (compare(m,OneEl())!=0 && compare(m, OneEl()) != 2)
	{
		for (int i = 0; i < t; i++)
		{
			b[i] = q[i];
		}
		inv = mult(b, two);
		inv = Add(inv,one);                       
		for (int i = 0; i < t; i++)
		{
			one[i] = two[i];
			two[i] = inv[i];
			a[i] = num[i];
			num[i] = m[i];
		}
		m = module(a,num);
	}
	for (int i = 0; i < t; i++)
	{
		b[i] = q[i];
	}
	inv = mult(b, two);
	inv = Add(inv, one);
	delete[] one;
	delete[] two;
	delete[] a;
	delete[] b;
	return inv;
}
int* Squa(int num[])
{
	int* square = new int[t];
	square = obnul(square, t);
	for (int i = 0; i < t; i++)
	{
		if (i%2==0)
		{
			square[i] = num[k+i/2-1];
		}
	}
	square = module(square, mod);
	return square;
}
int* trace(int num[])
{
	int* tr = new int[t];
	tr = obnul(tr,t);
	int* b = new int[t];
	b = obnul(b,t);
	for (int i = 0; i < t; i++)
	{
		b[i] = num[i];
		tr[i] = num[i];
	}
	for (int i = 0; i < k-1; i++)
	{
		b = Squa(b);
		tr = Add(b, tr);
	}
	delete[] b;
	return tr;
}
int* Degr(int first[], int second[])
{
	int* degree = new int[t];
	degree = obnul(degree, t);
	degree[t - 1] = 1;
	for (int i = t- high(second); i < t; i++)
	{
		if (second[i] == 1) degree = mult(degree,first);
		if(i!=t-1) degree = Squa(degree);
	}
	return degree;
}
