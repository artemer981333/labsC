//var 8

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 100

struct way
{
	char* name;
	int length;
	int amStops;
	int cost;
};

typedef struct way ways;

void input(ways* way);
void output(const ways* way);
int compare(const ways* way1, const ways* way2);

void input(ways *way)
{
	printf("Введите название маршрута, длину, кол-во остановок и стоимость:\n");
	way->name = (char *)malloc(NAME_LEN * sizeof(char));
	scanf("%s", way->name);
	scanf("%d", &way->length);
	scanf("%d", &way->amStops);
	scanf("%d", &way->cost);
}

void output(const ways* way)
{
	printf("Вывод:\nname = %s\nlength = %d\nstops = %d\ncost = %d\n", way->name, way->length, way->amStops, way->cost);
}

int compare(const ways* way1, const ways* way2)
{
	return way2->cost - way1->cost;
}

int main(int argc, char** argv)
{
	ways *way;
	int amount;
	setlocale(LC_ALL, "ru");
	printf("вар 8\n");
	printf("Введите кол-во путей\n");
	scanf("%d", &amount);

	for (int i = 0; i < amount; i++)
	{
		input(&way[i]);
	}

	for (int i = 0; i < amount; i++)
	{
		output(&way[i]);
	}

	printf("Сортировка начата\n");

	qsort(way, amount, sizeof(ways), (int(*) (const void *, const void *))compare);

	printf("Сортировка завершена\n");

	for (int i = 0; i < amount; i++)
	{
		output(&way[i]);
	}

	for (int i = 0; i < amount; i++)
	{
		free(way[i].name);
	}
}
