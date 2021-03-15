#include<stdio.h>
#include <windows.h>
#include"register.h"
#include"book_management.h"
int showbook(struct user *u) {
	if (u->numbor == 0) {
		printf("There is no book to return.\n");
		return 0;
	}
	else {
		printf("Below is the list of Books you are currently borrowing:\n");
		FILE* fp;
		Book b;
		printf("ID\tTilte\t\t\tAuthors\t\t\t\t\tyear\n");
		int i = 0,j=0,k;
		
		for (i = 0;i <5;i++) {
			fp = fopen("book.bin", "r");
			k=i;

			fread(&b, sizeof(struct _Book), 1, fp);
			while (1) 
			{
				i=k;
				if (u->borbook[i] != b.id) {
					if (!feof(fp)) {
						fread(&b, sizeof(struct _Book), 1, fp);
					}
					else {
						break;
					}
				}
				else {
					i = 0;
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
					printf("%i\n", b.year);
					break;
				}
				if (feof(fp))
					break;
			}
			i = k;
			fclose(fp);
		}
		fclose(fp);
		return 1;

		
	}
}
void retur(id) {
	int number = 0,i=0;
	Book a, b;
	users m, n;
	FILE* fb;
	FILE* fu;
	FILE* ft;
	fu = fopen("user.bin", "r");
	fread(&m, sizeof(struct user), 1, fu);
	
		while(1)
		if (m.sid != id) {
			if (!feof(fu)) {
				fread(&m, sizeof(struct user), 1, fu);
			}
		}
		else {
			fclose(fu);
			struct users* p = &m;
			if (showbook(p) == 1) {
				
				printf("Input the book id that you want to return\n");
				scanf("%i", &number);
				fb = fopen("book.bin", "r");
				fread(&a, sizeof(struct _Book), 1, fb);
				while (1) {
					if (number != a.id) {
						if (!feof(fb)) {
							fread(&a, sizeof(struct _Book), 1, fb);
						}
					}
					else {
						fclose(fb);
						for (i = 0;i < 5;i++)
						{
							if (m.borbook[i] == number)
							{
								break;

							}
							
						}
						m.borbook[i] = 0;
						m.numbor--;
						a.copies++;
						if (a.copies == a.icopies)
							a.bor = 0;
						fb = fopen("book.bin", "rt+");
						ft = fopen("temp.bin", "wt");
						while (fread(&b, sizeof(struct _Book), 1, fb))
						{
							if (strcmp(a.bt, b.bt) != 0)
							{
								fwrite(&b, sizeof(struct _Book), 1, ft);
							}
							else {
								fwrite(&a, sizeof(struct _Book), 1, ft);
							}
						}
						fclose(fb);
						fclose(ft);
						remove("book.bin");
						printf("Waiting...\n");
						Sleep(300);
						rename("temp.bin", "book.bin");
						Sleep(300);
						fu = fopen("user.bin", "rt+");
						ft = fopen("temp.bin", "wt");
						while (fread(&n, sizeof(struct user), 1, fb))
						{
							if (m.sid != n.sid)
							{
								fwrite(&n, sizeof(struct user), 1, ft);
							}
							else {
								fwrite(&m, sizeof(struct user), 1, ft);
							}
						}
						fclose(fb);
						fclose(ft);
						remove("user.bin");

						Sleep(300);
						rename("temp.bin", "user.bin");
						Sleep(300);
						
						printf("You have success returned the book.");
						return 0;
					}
				}
			}
			else {
				return 0;
			}
		}
	
}
void borrow(long id,int bid) {
	int i = 0;
	Book a,b;
	users m,n;
	FILE* fb;
	FILE* fu;
	FILE* ft;
	fb = fopen("book.bin", "r");
	fread(&a, sizeof(struct _Book), 1, fb);
	while (1) {
		if (a.id != bid)
		{
			if (!feof(fb)) {
				fread(&a, sizeof(struct _Book), 1, fb);
			}
			else {
				printf("sorry,no books are found\n");
				return 0;
			}
			
		}
		else {
			if (a.copies == 0) {
				printf("Sorry,you can not borrow this book\n");
				return 0;
			}
			else {
				a.copies = a.copies - 1;
				a.bor = 1;
				fclose(fb);
				fu = fopen("user.bin", "r");
				fread(&m, sizeof(struct user), 1, fu);
				while (1) {
					if (m.sid != id) {
						if (!feof(fu)) {
							fread(&m, sizeof(struct user), 1, fu);
						}
					}
					else {
						if (m.numbor == 5) {
							printf("Sorry,you have reached the limit of the books you can borrow.\n");
							return 0;
						}
						for (i = 0;i < m.numbor;i++) {
							if (m.borbook[i] == bid) {
								printf("Sorry,you have borrowed this book yet.\n");
								return 0;
							}
						}
						for (i = 0;i < 5;i++) {
							if (m.borbook[i] == 0) {
								m.borbook[i] = bid;
								break;
							}
						}
						
						m.numbor++;
						fclose(fu);
						fb = fopen("book.bin", "rt+");
						ft = fopen("temp.bin", "wt");
						while (fread(&b, sizeof(struct _Book), 1, fb))
						{
							if (strcmp(a.bt, b.bt) != 0)
							{
								fwrite(&b, sizeof(struct _Book), 1, ft);
							}
							else {
								fwrite(&a, sizeof(struct _Book), 1, ft);
							}
						}
						fclose(fb);
						fclose(ft);
						remove("book.bin");
						printf("Waiting...\n");
						Sleep(300);
						rename("temp.bin", "book.bin");
						Sleep(300);
						fu = fopen("user.bin", "rt+");
						ft = fopen("temp.bin", "wt");
						while (fread(&n, sizeof(struct user), 1, fb))
						{
							if (m.sid!=n.sid)
							{
								fwrite(&n, sizeof(struct user), 1, ft);
							}
							else {
								fwrite(&m, sizeof(struct user), 1, ft);
							}
						}
						fclose(fb);
						fclose(ft);
						remove("user.bin");
						Sleep(300);
						rename("temp.bin", "user.bin");
						Sleep(300);
						
						printf("You have successfully borrow this book.");
						return 0;

					}
				}

				
			}
		}
	}
}