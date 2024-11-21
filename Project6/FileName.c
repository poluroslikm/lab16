#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
double* full_elements(double* ptr_array, int n)
{
	double z, y = 0;
	z = 2.1 / n;
	for (int i = 0; i < n; i++)
	{
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return (ptr_array);
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] < 0) ptr_array[i] = 0;
	}

	return (ptr_array);
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%+lf \n", ptr_array[i]);
	}
}
int lab16task1()
{
	double* ptr_array = NULL;
	double* ptr_array2 = NULL;
	int size;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	ptr_array2 = calc_elements(ptr_array, size);
	if (ptr_array2 == NULL)
	{
		free(ptr_array);
		return -1;
	}
	printf("\n");
	put_elements(ptr_array2, size);
	free(ptr_array2);
	free(ptr_array);
	return 0;
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	char c;
	printf("Введите номер задания лабораторной ");
	scanf("%c", &c);
	switch (c)
	{
	case '1':
		lab16task1();
		break;
		//case '2':
		//	lab14task2();
		//	break;
		//case '3':
		//	lab14task3();
		//	break;
	default:
		printf("Неизвестная операция.\n");
	}
}