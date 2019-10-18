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
	FILE* f = fopen(fileName, "r");
	if (f == NULL)
		return NULL;
	char** text = malloc(sizeof(char*));
	text[0] = NULL;
	int i = 0;
	while(!feof(f))
	{
		text = realloc(text, sizeof(char*) * (i + 2));
		text[i] = malloc(sizeof(char) * STR_LEN);
		text[i+1] = NULL;
		fgets(text[i], STR_LEN, f);
		i++;
	}
	fclose(f);
	return text;
}

void output(const char* fileName, char** text)
{
	FILE* f;
	f = fopen(fileName, "w");
	if (f == NULL)
		return;
	while(*text != NULL)
	{
		fputs(*text, f);
		text++;
	}
	fclose(f);	
}

_Bool checkString(char* string, char symbol)
{
	while(*string != '\0')
	{
		if (*string == symbol)
			return 0;
		string++;
	}
	return 1;
}

void deleteSymbols(char** text, char symbol)
{
	while(*text != NULL)
	{
		if (!checkString(*text, symbol))
		{
			free(*text);
			char** pp = text;
			do
			{
				*pp = pp[1];
				pp++;
			}
			while(*pp != NULL);
		}
		else
			text++;
	}
}

int main(int argc, char** argv)
{
	char** text;
	char* newName;
	setlocale(LC_ALL, "ru");

	text = input(argv[1] + 1);

	deleteSymbols(text, argv[2][1]);

	newName = malloc(sizeof(char) * STR_LEN);
	strcpy(newName, "");
	if (strchr(argv[1] + 1, '.') != NULL)
		strncat(newName, argv[1] + 1, strchr(argv[1] + 1, '.') - argv[1] - 1);
	else
		strcat(newName, argv[1] + 1);
	strcat(newName, ".new");
	
	output(newName, text);

	int i = 0;
	while(text[i] != NULL)
	{
		free(text[i]);
		i++;
	}
	free(text);
	free(newName);
}
