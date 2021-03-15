#include <stdio.h>
typedef struct user
{
    char uname[11]; //student name (can not be repeated)
    char password[20]; //
    unsigned int sid;//student id(can not be repeated)
    int numbor;
    int borbook[5];

}users;
int showbook(struct user* u);
void borrow(int id,int bid);
void retur(int id);
void clear();