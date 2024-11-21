#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int delete_k(double* ptr_arr, int size, int k) {
	int n = size - 1;
	for (int i = k; i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];
	return n;
}
double* full_elements(double* ptr_array, int n)
{
	double z, y = 0;
	z = 2.1 / n;
	for (int i = 0; i < n; i++)
	{
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return ptr_array;
}
int* insert(int* ptr_arr, int* size, int index, int num)
{
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	int* ptr_arr_n = (int*)realloc(ptr_arr, size_n * sizeof(int));
	if (ptr_arr_n == NULL) return ptr_arr_n;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}
double* rand_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x = (rand() % 20001);
		ptr_array[i] = (x - 10000) / 10000;
	}
	return ptr_array;
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		if (ptr_array[i] < 0)
			ptr_array[i] = 0;
	return ptr_array;
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("%+lf \n", ptr_array[i]);
	return 0;
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
int lab16task2()
{
	srand(time(NULL));
	double* ptr_array = NULL;
	double* ptr_array2 = NULL;
	int size, el1, el2, k=-1, num = -999, index=1, m1=1, m2=1;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	ptr_array2 = (double*)malloc((size) * sizeof(double));
	rand_elements(ptr_array, size);
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	put_elements(ptr_array, size);
	printf("\n\n");
	double max = ptr_array[1], min = ptr_array[1];
	for (int i = 0; i < size+1; i++)
	{
		if (ptr_array[i] < min)
		{
			min = ptr_array[i];
			m1 = i;
		}
		if (ptr_array[i] > max)
		{
			max = ptr_array[i];
			m2 = i;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if ((ptr_array[i] != min) && (ptr_array[i] != max))
		{
			k++;
			ptr_array2[k] = ptr_array[i];
		}
		if (ptr_array[i] == min)
		{
			index = k;
		}
	}
	size = delete_k(ptr_array, size, m1);
	size = delete_k(ptr_array, size, m2);
	//ptr_array2 = (double*)realloc(ptr_array2, size * sizeof(int));
	put_elements(ptr_array2, size);
	printf("\n\n");
	insert(ptr_array2, size, index, num);
	insert(ptr_array2, size, index+1, num);
	put_elements(ptr_array2, size);
	free(ptr_array);
	free(ptr_array2);
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
		case '2':
			lab16task2();
			break;
		//case '3':
		//	lab14task3();
		//	break;
	default:
		printf("Неизвестная операция.\n");
	}
}