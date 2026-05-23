#include <stdio.h>
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
    char search_name[NAME_LEN];
    int found = 0;

    printf("Enter Name to Search: ");
    scanf(" %[^\n]", search_name);

    for(int i = 0; i < count; i++)
    {
        int same = 1;

        for(int j = 0; search_name[j] != '\0' || contacts[i].name[j] != '\0';j++)
        {
            if(search_name[j] != contacts[i].name[j])
            {
                same = 0;
                break;
            }
        }

        if(same)
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
    char search_name[NAME_LEN];
    int found = 0;

    printf("Enter Name to Edit: ");
    scanf(" %[^\n]", search_name);

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
    char search_name[NAME_LEN];
    int found = 0;

    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", search_name);

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
        printf("\n No Contacts Available \n");/*To show if there is no contact available*/
        return ;

    }

    printf("\n------ CONTACT LIST ------\n");

    for(int i = 0;i < count;i++)
    {
        /*here count is 0 but in contact start from 1 so for
         printing purpose we are adding i+1 */
        printf("\n Contact %d \n",i + 1);
        
        printf("Name   : %s \n",contacts[i].name);
        printf("Phone  : %s \n",contacts[i].phone);
        printf("Email  : %s \n",contacts[i].email);

    }

}
