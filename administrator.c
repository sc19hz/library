#include<stdio.h>
#include <windows.h>
#include"book_management.h"
#include"administrator.h"

int um = 0;
int librarian() {
	long pas = 0;
	while (pas != 7355607) {
		printf("Input the librarian password:\n");
		scanf("%i", &pas);
		if (pas != 7355607)
			printf("The password is wrong, please try again\n");
	}
	return 1;

}
void show() {
	Book a;
	int i, j = 0;
	FILE* fp;
	fp = fopen("book.bin", "r");
	firstrow();
	fread(&a, sizeof(struct _Book), 1, fp);
	while (1) {
		printf("%i", a.id);
		printf("\t");
		i = 0;
		while (a.bt[i] != '\0') {
			printf("%c", a.bt[i]);
			i++;
		}
		i = 0;

		printf("\t\t\t");
		for (i = 0;i <= a.numa;i++)
		{
			while (a.au[i][j] != '\0')
			{

				printf("%c", a.au[i][j]);
				j++;
			}
			if (i < a.numa)
				printf(",");

			j = 0;
		}
		printf("\t\t\t\t\t");
		printf("%i", a.year);
		printf("\t");
		printf("%i\n", a.copies);


		fread(&a, sizeof(struct _Book), 1, fp);
		if (feof(fp)) {
			fclose(fp);
			break;
		}
	}

}

void firstrow() {
	printf("ID\tTilte\t\t\tAuthors\t\t\t\t\tyear\tcopies\n");
}
void findauthor() {
	int i = 0, j = 0, k = 0, p = 0;
	Book a;
	char temp[20];
	getchar();
	printf("Input the author you want to find\n");
	gets(temp);
	FILE* fp;
	fp = fopen("book.bin", "r");
	fread(&a, sizeof(struct _Book), 1, fp);
	while (1) {
		if (compare(temp, a.au, a.numa) == 1) {
			k = 1;
			
			if (p == 0)firstrow();
			p++;
			printf("%i", a.id);
			printf("\t");
			i = 0;
			while (a.bt[i] != '\0') {
				printf("%c", a.bt[i]);
				i++;
			}
			i = 0;

			printf("\t\t\t");
			for (i = 0;i <= a.numa;i++)
			{
				while (a.au[i][j] != '\0')
				{

					printf("%c", a.au[i][j]);
					j++;
				}
				if (i < a.numa)
					printf(",");

				j = 0;
			}
			printf("\t\t\t\t\t");
			printf("%i", a.year);
			printf("\t");
			printf("%i\n", a.copies);
		}
		fread(&a, sizeof(struct _Book), 1, fp);
		if (feof(fp))
			break;
	};
	if (k == 0) {
		printf("no book found\n");
	}
}
int compare(char name1[20], char name2[5][20], int nu) {
	char te[20];

	int i = 0, j = 0, k = 0;
	for (i = 0;i <= nu;i++) {
		if (strcmp(name1, name2[i]) == 0) {
			return 1;
		}

	}
	return 0;



}

void findyear() {
	int k = 1, k1 = 0;
	int i = 0, j = 0;
	Book a, b;
	getchar();
	printf("Input the year you want to find\n");
	scanf("%i", &a.year);

	FILE* fp;
	fp = fopen("book.bin", "r");
	fread(&b, sizeof(struct _Book), 1, fp);
	while (1)
	{
		if (a.year != b.year)
		{
			if (!feof(fp))
			{
				fread(&b, sizeof(struct _Book), 1, fp);
			}
			else {
				if (k != 2)k = 0;
				break;
			}
		}
		else {
			if (k1 == 0) {
				firstrow();
				k = 2;
			}
			k1++;

			printf("%i", b.id);
			printf("\t");
			i = 0;
			while (b.bt[i] != '\0') {
				printf("%c", b.bt[i]);
				i++;
			}
			i = 0;

			printf("\t\t\t");
			for (i = 0;i <= b.numa;i++)
			{
				while (b.au[i][j] != '\0')
				{

					printf("%c", b.au[i][j]);
					j++;
				}
				if (i < b.numa)
					printf(",");

				j = 0;
			}
			printf("\t\t\t\t\t");
			printf("%i", b.year);
			printf("\t");
			printf("%i\n", b.copies);


			fread(&b, sizeof(struct _Book), 1, fp);
			if (feof(fp))
				break;





		}
	}
	if (k == 0) {
		printf("sorry, no books are found\n");
	}

	fclose(fp);
}
void findname() {
	int k = 1, k1 = 0;
	int i = 0, j = 0;
	Book a, b;
	if (k1 == 0)getchar();
	printf("Input the book you want to find\n");
	gets(a.bt);

	FILE* fp;
	fp = fopen("book.bin", "r");
	fread(&b, sizeof(struct _Book), 1, fp);
	while (1)
	{
		if (strcmp(a.bt, b.bt))
		{
			if (!feof(fp))
			{
				fread(&b, sizeof(struct _Book), 1, fp);
			}
			else {
				if(k!=2)k = 0;
				break;
			}
		}
		else {
			if (k1 == 0) {
				firstrow();
			}
			k1++;
			k = 2;
			printf("%i", b.id);
			printf("\t");
			while (b.bt[i] != '\0') {
				printf("%c", b.bt[i]);
				i++;
			}
			i = 0;

			printf("\t\t\t");
			for (i = 0;i <= b.numa;i++)
			{
				while (b.au[i][j] != '\0')
				{

					printf("%c", b.au[i][j]);
					j++;
				}
				if (i < b.numa)
					printf(",");

				j = 0;
			}
			printf("\t\t\t\t\t");
			printf("%i", b.year);
			printf("\t");
			printf("%i\n", b.copies);


			fread(&b, sizeof(struct _Book), 1, fp);


			if (feof(fp))
				break;

		}
	}
	if (k == 0) {
		printf("sorry, no books are found\n");
	}

	fclose(fp);
}

void addbook() {
	FILE* fs;
	fs = fopen("num.bin", "r");
	fscanf(fs, "%i", &um);
	fclose(fs);
	getchar();
	Book b;
	FILE* file;
	int i = 0, j = 0, k = 0, cou = 0;
	char temp[100];
	printf("Input the name of the book\n");
	gets(b.bt);
	printf("Input the author of the book\n");
	gets(temp);
	printf("Input the year of the book\n");
	scanf("%i", &b.year);
	printf("Input the copies of the book\n");
	scanf("%i", &b.copies);
	b.icopies = b.copies;
	char* p = temp;
	while (*p != '\0')
	{
		if (*p == ',') {
			cou++;
		}
		p++;
	}
	b.numa = cou;

	while (temp[i] != '\0') {
		if (temp[i] != ',') {
			b.au[j][k] = temp[i];
			i++;
			k++;
		}
		else {
			b.au[j][k] = '\0';
			k = 0;
			j++;
			i++;
		}

	}
	b.au[j][k] = '\0';


	i = 0, j = 0;


	b.bor = 0;
	um++;
	b.id = um;
	FILE* fm;
	fm = fopen("num.bin", "w");

	fprintf(fm, "%i", um);
	fclose(fm);

	file = fopen("book.bin", "a");
	fwrite(&b, sizeof(struct _Book), 1, file);
	fclose(file);
	return &b;



}
void removebook() {
	getchar();
	int num = 0, k = 0;
	Book a, b;
	FILE* fr, * ft;
	printf("Input the book you want to remove\n");
	gets(a.bt);
	fr = fopen("book.bin", "r");
	fread(&b, sizeof(struct _Book), 1, fr);
	while (1) {
		if (strcmp(a.bt, b.bt))
		{
			if (!feof(fr))
			{
				fread(&b, sizeof(struct _Book), 1, fr);
			}
			else {
				break;
			}
		}
		else
		{        //match the name
			if (b.bor == 1)
			{
				printf("This book can not be removed\n");//someone has borrowed it
				break;
			}

			else
			{
				fclose(fr);
				fr = fopen("book.bin", "rt+");
				ft = fopen("temp.bin", "wt");
				while (fread(&b, sizeof(struct _Book), 1, fr))
				{
					if (strcmp(a.bt, b.bt) != 0)
					{
						fwrite(&b, sizeof(struct _Book), 1, ft);
						num++;
					}

				}
				printf("Waiting...\n");
				Sleep(1000);
				fclose(fr);
				
				fclose(ft);
				Sleep(1000);
				remove("book.bin");
				Sleep(1000);
				rename("temp.bin", "book.bin");
				k = 1;
				break;
			}

		}
	}
	if (k == 1)printf("success\n");
	if (k == 0)printf("fail\n");
}



