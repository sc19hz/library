#include<stdio.h>
#include"register.h"

void clear(struct user *u) {
    int i = 0;
    for (i = 0;i < 5;i++) {
        u->borbook[i]= 0;
    }
}
void registers() //register
{
    int k = 0,h=1;//index for same
    users m, n;//n for refrence
    FILE* fu;
    char temp[20];
   
    printf("Register your account\n");
    fu = fopen("user.bin", "r");

    fread(&n, sizeof(struct user), 1, fu);
    while (k == 0 && h == 1) {
        h = 0;
        printf("Input your username\n");
        scanf("%s", &m.uname);


        while (1)
        {
            if (strcmp(m.uname,n.uname))//if not same
            {
                if (!feof(fu)) //not the end of the file


                {
                    fread(&n, sizeof(struct user), 1, fu);
                }
                else {
                    k = 1;
                    
                    break;
                }
            }
            else

            {
                printf("This username has already been used\n");

                h = 1;
           
                break;
            }
        }
    }
    k = 0;
    h = 1;
    fclose(fu);
    fu = fopen("user.bin", "r");//re-read the file
    while (k == 0 && h == 1) {
        h = 0;
        fread(&n, sizeof(struct user), 1, fu);
        printf("Input yor student id\n");
        getchar();
        scanf("%i", &m.sid);
        while (1)
        {
            if (m.sid!=n.sid)
            {
                if (!feof(fu))


                {
                    fread(&n, sizeof(struct user), 1, fu);
                }
                else {
                    k = 1;
                    break;
                }
            }
            else

            {
                printf("This id has already been registered\n");

                h = 1;
                break;
            }
        }
    }
    fclose(fu);
    printf("Input your password\n");
   
    scanf("%s", &m.password);
    m.numbor = 0;
    struct users* p = &m;
    clear(p);
    
        
            fu = fopen("user.bin", "a");
            fwrite(&m, sizeof(struct user), 1, fu);
            printf("Your account has successfully registered\n");
      
            fclose(fu);
            return;
        }
        
    
int login()//login
{
    users m, n;//n for refrence
    int k = 0, h = 1;//index for same
    FILE* fu;
    printf("User log in\n");

    fu = fopen("user.bin", "r");

    fread(&n, sizeof(struct user), 1, fu); 
    while (k == 0 && h == 1) 
    {
        h = 0;
        printf("Please input your username\n");
        scanf("%s", &m.uname);

        while (1)
        {
            if (strcmp(m.uname, n.uname) == 0)         //if same
            {
                k = 1;
                break;
                
            }

            else
            {
                if (!feof(fu))  //not the end of the file                         

                {
                    fread(&n, sizeof(struct user), 1, fu);
                }

                else
                {
                    printf("This username is not exist, please try again\n");
                    h = 1;
                    break;
                }
            }
        }
    }
    printf("Please input your password\n");
    scanf("%s", &m.password);
    do {

        if (strcmp(m.password, n.password) == 0)  //password same

        {
            fclose(fu);
            printf("User log in successfully\n");

            return n.sid;
        }
        else
        {
            printf("Wrong password, please try again\n");
            scanf("%s", &m.password);
        }
    } while (1);
    
}

