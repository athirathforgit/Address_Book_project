#include <stdio.h>
#include<string.h>
#include "operations.h"
#include "validation.h"
 
void add_contact(struct Contact contacts[], int * count)
{
    if(*count >= MAX_CONTACTS)
    {
        printf("Contact List Full\n");
        return;
    }
    /* reading name*/
   while(1)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", contacts[*count].name);

        if(validate_name(contacts[*count].name))
    {
        break;
    }

        printf("Invalid Name\n");
}

    /*reading phone number*/
    while(1)
    {
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[*count].phone);

    if(validate_phone(contacts[*count].phone))
        {
            break;
        }

    printf("Invalid Phone Number\n");
}

/*reading Email*/
while(1)
{
    printf("Enter Email: ");
    scanf(" %[^\n]", contacts[*count].email);

    if(validate_email(contacts[*count].email))
    {
        break;
    }

    printf("Invalid Email\n");
}

/*taking the count of added number*/
     (*count)++;

     printf("\n Contact Added Successfully \n");
}
void search_contact(struct Contact contacts[], int count)
{
    if(count == 0)
    {
        printf("\nNo Contacts Available\n");

        return;
    }

    char search_name[NAME_LEN];

    int found = 0;

    printf("Enter Name to Search: ");

    scanf(" %[^\n]", search_name);

    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");

        return;
    }

    for(int i = 0; i < count; i++)
    {
        if(strstr(contacts[i].name, search_name))
        {
            printf("\nContact Found\n");

            printf("Name   : %s\n", contacts[i].name);

            printf("Phone  : %s\n", contacts[i].phone);

            printf("Email  : %s\n", contacts[i].email);

            found = 1;

            break;
        }
    }

    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}
void edit_contact(struct Contact contacts[], int count)
{

    if(count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    char search_name[NAME_LEN];
    int found = 0;

    printf("Enter Name to Edit: ");
    scanf(" %[^\n]", search_name);

    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        int same = 1;

        for(int j = 0;
            search_name[j] != '\0' || contacts[i].name[j] != '\0';
            j++)
        {
            if(search_name[j] != contacts[i].name[j])
            {
                same = 0;
                break;
            }
        }

        if(same)
        {
            found = 1;

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", contacts[i].name);

            while(!validate_name(contacts[i].name))
            {
                printf("Invalid Name\n");

                printf("Enter New Name: ");
                scanf(" %[^\n]", contacts[i].name);
            }

            printf("Enter New Phone: ");
            scanf(" %[^\n]", contacts[i].phone);

            while(!validate_phone(contacts[i].phone))
            {
                printf("Invalid Phone Number\n");

                printf("Enter New Phone: ");
                scanf(" %[^\n]", contacts[i].phone);
            }

            printf("Enter New Email: ");
            scanf(" %[^\n]", contacts[i].email);

            while(!validate_email(contacts[i].email))
            {
                printf("Invalid Email\n");

                printf("Enter New Email: ");
                scanf(" %[^\n]", contacts[i].email);
            }

            printf("\nContact Updated Successfully\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

 
void delete_contact(struct Contact contacts[], int *count)
{

    if(*count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    char search_name[NAME_LEN];
    int found = 0;

    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", search_name);

    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");
        return;
    }

    for(int i = 0; i < *count; i++)
    {
        int same = 1;

        for(int j = 0;
            search_name[j] != '\0' || contacts[i].name[j] != '\0';
            j++)
        {
            if(search_name[j] != contacts[i].name[j])
            {
                same = 0;
                break;
            }
        }

        if(same)
        {
            found = 1;

            for(int k = i; k < *count - 1; k++)
            {
                contacts[k] = contacts[k + 1];
            }

            (*count)--;

            printf("\nContact Deleted Successfully\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

 
void list_contacts(struct Contact contacts[], int count)
{
    if(count == 0)
    {
        printf("\nAddress book is empty\n");
        return;
    }

    struct Contact temp;

    /* Bubble Sort */
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            int k = 0;
            int swap_needed = 0;

            while(1)
            {
                char ch1 = contacts[j].name[k];
                char ch2 = contacts[j + 1].name[k];

                /* convert uppercase to lowercase */
                if(ch1 >= 'A' && ch1 <= 'Z')
                {
                    ch1 = ch1 + 32;
                }

                if(ch2 >= 'A' && ch2 <= 'Z')
                {
                    ch2 = ch2 + 32;
                }

                if(ch1 > ch2)
                {
                    swap_needed = 1;
                    break;
                }

                else if(ch1 < ch2)
                {
                    break;
                }

                else if(ch1 == '\0' && ch2 == '\0')
                {
                    break;
                }

                k++;
            }

            if(swap_needed)
            {
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }

    /* Table Header */
    printf("\n+----+------------------+------------+----------------------+\n");

    printf("| %-2s | %-16s | %-10s | %-20s |\n","#", "Name", "Phone", "Email");

    printf("+----+------------------+------------+----------------------+\n");

    /* Print Contacts */
    for(int i = 0; i < count; i++)
    {
        printf("| %-2d | %-20s | %-13s | %-28s |\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }

    /* Footer Line */
    printf("+----+----------------------+---------------+------------------------------+\n");

    printf("Total contacts: %d / %d\n",
           count,
           MAX_CONTACTS);
}
