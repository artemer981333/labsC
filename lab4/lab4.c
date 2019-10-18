//var 8

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 100

char** input(const char* fileName);
void output(const char* fileName, char** text);
_Bool checkString(char* string, char symbol);
void deleteSymbols(char** text, char symbol);

char** input(const char* fileName)
{
	FILE* f = fopen("fileName", "r");
	if (f == NULL)
		return NULL;
	char** text = malloc(sizeof(char*));
	text[0] = NULL;
	int i = 0;
	while(feof(f) != EOF)
	{
		text = realloc(text, sizeof(char*) * (i + 2));
		text[i] = malloc(sizeof(char) * STR_LEN);
		fgets(text[i], STR_LEN, f);
		printf("%s\n", text[i]);
		i++;
	}
	fclose(f);
	return text;
}

void output(const char* fileName, char** text)
{
	printf("Ввод\n");
	FILE* f = fopen(fileName, "w");
	if (f == NULL)
		return;
	while(*text != NULL)
	{
		printf("Вывод\n");
		fputs(*text, f);
		puts(*text);
		text++;
	}
	fclose(f);	
}

_Bool checkString(char* string, char symbol)
{
	char* p;
	p = string;
	while(*p != '\0')
	{
		if (*p == symbol)
			return 0;
	}
	return 1;
}

void deleteSymbols(char** text, char symbol)
{
	printf("Начато удаление\n");
	printf("%s\n", *text);
	while(*text != NULL)
	{
		printf("Проверка\n");		
		if (!checkString(*text, symbol))
		{
			printf("Удаление строки\n");
			free(*text);
			char** pp = text;
			do
			{
				*pp = pp[1];
				pp++;
			}
			while(*pp != NULL);
		}
		text++;
	}
}

int main(int argc, char** argv)
{
	char** text;
	setlocale(LC_ALL, "ru");

	printf("Ввод %s\n", argv[1]);
	text = input(argv[1]);

	printf("Вывод\n");
	output("new.txt", text);

	printf("Удаление\n");
	deleteSymbols(text, argv[2][0]);

	printf("Новое имя\n");
	char* newName;
	strcpy(newName, "");
	if (strchr(argv[1], '.') != NULL)
		strncat(newName, argv[1], strchr(argv[0], '.') - argv[1]);
	else
		strcat(newName, argv[1]);
	strcat(newName, ".new");
	
	printf("Вывод\n");
	output(newName, text);
}
