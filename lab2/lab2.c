//var 7

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char** input(int n);
void output(char** str_array, int amount);
int count_nums(const char* str);
int compare(const char** str1, const char** str2);
void sort(char** str_array, int amount);

char** input(int n)
{
	char** str_array;

	//printf("Введите %d строк\n", n);

	str_array = malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		str_array[i] = malloc(N * sizeof(char));
		//printf("Введите %d строку:", i+1);
		fgets(str_array[i], N, stdin);
		printf("%d\n", count_nums(str_array[i]));
		//printf("%s\n", str_array[i]);
	}
	return str_array;
}

void output(char** str_array, int amount)
{
	printf("Вывод:\n");
	for (int i = 0; i < amount; i++)
	{
		printf("%s", str_array[i]);
	}
	printf("\n\n");
}

int count_nums(const char* str)
{
	int len = strlen(str);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
	}
	return count;
}

int compare(const char** str1, const char** str2)
{
	//printf("%s%s", *str1, *str2);
	return count_nums(*str1) - count_nums(*str2);
}

int main(int argc, char** argv)
{
	int amount;
	char** str_array;
	setlocale(LC_ALL, "ru");
	printf("вар 7\n");
	printf("Введите количество строк\n");
	scanf("%d", &amount);
	getchar();

	//printf("%d\n", amount);
	str_array = input(amount);

	output(str_array, amount);

	printf("Сортировка начата\n");

	qsort(str_array, amount, sizeof(char*), (int(*) (const void *, const void *))compare);

	printf("Сортировка завершена\n");

	output(str_array, amount);

	for (int i = 0; i < amount; i++)
	{
		free(str_array[i]);
	}
	free(str_array);
}
