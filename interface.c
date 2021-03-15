#include<stdio.h>
int searchcase() {
	printf("Please choose an option\n");
	printf("1) Search by book title\n");
	printf("2) Search by year\n");
	printf("3) Search by author\n");
	printf("4)Quit\n");
	
	int index = 0;
	scanf("%i", &index);
	while (1) {
		switch (index) {
		case 1:
		{
			findname();
			break;
		}
		case 2: {
			findyear();
			break;
		}
		case 3:
		{
			findauthor();
			break;
		}
		
		case 4:return 1;
		}
		break;
	}
	return 0;
}
void librariancase() 
{
	int index;
	while (1) 
	{
	printf("Please choose an option\n");
	printf("1) Add a book\n");
	printf("2) Remove a book\n");
	printf("3)Search for books\n");
	printf("4)Display all books\n");
	printf("5)Quit\n");
	scanf("%i", &index);
	
		switch (index) 
		{
		case 1:
		{
			addbook();
			break;
		}
		case 2:
		{
			removebook();

				break;
		}
		case 3:
		{
			searchcase();
			break;
		}
		case 4: {
			show();
			break;
		}
		case 5:return 0;
		}
	}
}
	int firstcase() 
	{
		int index,swi;
		while (1) {
			printf("Welcome to the library\n");
			while (1) {
				printf("Please choose an option\n");
				printf("1) Register an account\n");
				printf("2) Log in\n");
				printf("3)Administrator only\n");
				printf("4)Quit\n");
				scanf("%i", &index);

				switch (index) {
				case 1:
				{
					registers();
					break;
				}
				case 2:
				{
					int id;
					id = login();
					while (1)
					{
						printf("Please choose an option\n");
						printf("1) Borrow a book\n");
						printf("2) Return a book\n");
						printf("3) Display all books\n");
						printf("4) Quit\n");
						scanf("%i", &index);
						switch (index)
						{
						case 1:
						{
							if (searchcase() != 1) {
								printf("Please choose the book id:\n");
								scanf("%i", &index);
								borrow(id, index);
							}
							break;
						}
						case 2:
						{
							retur(id);
							break;
						}
						case 3: {
							show();
							break;}
						case 4: {
							swi = -1;
							return 0;
						}


						}

					}
				}
				case 3:
				{
					if (librarian() == 1) {
						librariancase();
					}
					break;
				}
				case 4: {
					return 1;
				}
				}
			}
		}
		if (swi == -1)
		{
			return 1;
		}
	}
		