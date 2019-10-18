//var 8

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 100
#define DEFAULT_FILE_NAME "out.txt"

char* input(const char* fileName);
void output(const char* fileName, char* text);
void deleteSymbols(char* text, char symbol);

char* input(const char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (f == NULL)
		return NULL;
	char* text = malloc(sizeof(char));
	text[0] = '\0';
	int i = 0;
	while(!feof(f))
	{
		text = realloc(text, sizeof(char*) * (i + 2));
		text[i+1] = '\0';
		fscanf(f, "%c", &text[i]);
		i++;
	}
	fclose(f);
	return text;
}

void output(const char* fileName, char* text)
{
	FILE* f;
	f = fopen(fileName, "w");
	if (f == NULL)
		return;
	//while(*text != '\0')
	//{
		fprintf(f, "%s\n", text);
	//	text++;
	//}
	fclose(f);	
}

void deleteSymbols(char* text, char symbol)
{
	while(*text != '\0')
	{
		if (*text == symbol)
		{
			char* p = text;
			do
			{
				*p = p[1];
				p++;
			}
			while(*p != '\0');
		}
		else
			text++;
	}
}

int main(int argc, char** argv)
{
	char* text;
	setlocale(LC_ALL, "ru");

	text = input(argv[1] + 1);

	deleteSymbols(text, argv[2][1]);

	if (argc < 4)
		output(DEFAULT_FILE_NAME, text);
	else
		output(argv[3] + 1, text);
	
	free(text);
}
