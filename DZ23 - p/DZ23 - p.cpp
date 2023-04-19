// DZ 23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*Задача 1Создайте функцию, которая принимает три
переменные.Функция вычисляет максимальную из них,
после чего меняет значение остальных на значение
максимальной.
Пример кода с вызовом функции :
int A = 3, B = 5, C = 4;
three_max(A, B, C);
std::cout << A << ' ' << B << ' ' << C;
// на экране 5 5 5*/

template <typename T>
void three_max(T& a, T& b, T& c) {
	T max;
	if (a > b && a > c)
		max = a;
	if (b > a && b > c)
		max = b;
	if (c > a && c > b)
		max = c;
	a = b = c = max;
}

/*Задача 2
Создайте функцию, которая принимает массив и его
длину.Функция возвращает ссылку на первый
отрицательный элемент массива.Если отрицательных
элементов нет в массиве, то функция возвращает ссылку
на первый элемент.*/

template <typename T>
int& ref_arr(T arr[], T length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] < 0)
			return arr[i];
		return arr[0];
	}
}

/*Задача 3
Напишите функцию, которая принимает два массива
и их длины.Функция должна обнулить все элементы
второго массива, которые встречаются в первом.В теле
функции необходимо использовать синтаксис
указателей для перебора элементов массивов.
Пример:
Массив1:
[3, 6, 4, 1, 4, 8, 2]
Массив2 :
[5, 3, 1, 5, 10, 8]
Массив 2 после вызова функции :
[5, 0, 0, 5, 10, 0]*/

template <typename T>

void func_arr(T* arr1, T* arr2, T length1, T length2) {
	for (int i1 = 0; i1 < length1; i1++)
		for (int i2 = 0; i2 < length2; i2++)
			if (arr1[i1] == arr2[i2])
				arr2[i2] = 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//Задача 1
	int a = 3, b = 5, c = 4;
	three_max(a, b, c);
	std::cout << a << " " << b << " " << c << std::endl;

	//Задача 2
	const int size = 5;
	int arr[size]{ 4, 2, 3, -4, 5 };
	std::cout << ref_arr(arr, size);
	std::cout << std::endl;

	//Задача 3
	const int SIZE1 = 7;
	int ARR1[SIZE1]{ 3, 6, 4, 1, 4, 8, 2 };
	for (int i = 0; i < SIZE1; i++)
		std::cout << ARR1[i] << '\t';
	std::cout << std::endl;
	const int SIZE2 = 6;
	int ARR2[SIZE2]{ 5, 3, 1, 5, 10, 8 };
	for (int i = 0; i < SIZE2; i++)
		std::cout << ARR2[i] << '\t';
	std::cout << std::endl;
	func_arr(ARR1, ARR2, SIZE1, SIZE2);
	for (int i = 0; i < SIZE2; i++)
		std::cout << ARR2[i] << '\t';
	std::cout << std::endl;

	return 0;
}