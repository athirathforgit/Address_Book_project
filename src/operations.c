/* Standard input-output functions */
#include <stdio.h>

/* String handling functions */
#include<string.h>

/* Contains function declarations for contact operations */
#include "operations.h"

/* Contains validation function declarations */
#include "validation.h"
 

/* 
   Adds a new contact into the contact list

   Parameters:
   - contacts : array storing all contacts
   - count    : pointer storing current contact count
*/
void add_contact(struct Contact contacts[], int * count)
{
    /* Check whether contact list is full */
    if(*count >= MAX_CONTACTS)
    {
        printf("Contact List Full\n");
        return;
    }

    /* Read and validate contact name */
    while(1)
    {
        printf("Enter Name: ");

        scanf(" %[^\n]", contacts[*count].name);

        /* Break loop if name is valid */
        if(validate_name(contacts[*count].name))
        {
            break;
        }

        printf("Invalid Name\n");
    }

    /* Read and validate phone number */
    while(1)
    {
        printf("Enter Phone: ");

        scanf(" %[^\n]", contacts[*count].phone);

        /* Break loop if phone number is valid */
        if(validate_phone(contacts[*count].phone))
        {
            break;
        }

        printf("Invalid Phone Number\n");
    }

    /* Read and validate email address */
    while(1)
    {
        printf("Enter Email: ");

        scanf(" %[^\n]", contacts[*count].email);

        /* Break loop if email is valid */
        if(validate_email(contacts[*count].email))
        {
            break;
        }

        printf("Invalid Email\n");
    }

    /* Increase contact count after successful addition */
    (*count)++;

    printf("\nContact Added Successfully\n");
}


/* 
   Searches for a contact using name

   Parameters:
   - contacts : array storing all contacts
   - count    : total number of contacts
*/
void search_contact(struct Contact contacts[], int count)
{
    /* Check whether contact list is empty */
    if(count == 0)
    {
        printf("\nNo Contacts Available\n");

        return;
    }

    char search_name[NAME_LEN];

    int found = 0;

    printf("Enter Name to Search: ");

    scanf(" %[^\n]", search_name);

    /* Validate search input */
    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");

        return;
    }

    /* Search contact using strstr() */
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

    /* Display message if contact not found */
    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}


/* 
   Edits existing contact details

   Parameters:
   - contacts : array storing all contacts
   - count    : total number of contacts
*/
void edit_contact(struct Contact contacts[], int count)
{
    /* Check whether contact list is empty */
    if(count == 0)
    {
        printf("\nNo Contacts Available\n");

        return;
    }

    char search_name[NAME_LEN];

    int found = 0;

    printf("Enter Name to Edit: ");

    scanf(" %[^\n]", search_name);

    /* Validate search name */
    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");

        return;
    }

    /* Search for matching contact */
    for(int i = 0; i < count; i++)
    {
        int same = 1;

        /* Manual string comparison */
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

        /* If contact found */
        if(same)
        {
            found = 1;

            /* Read and validate new name */
            printf("\nEnter New Name: ");

            scanf(" %[^\n]", contacts[i].name);

            while(!validate_name(contacts[i].name))
            {
                printf("Invalid Name\n");

                printf("Enter New Name: ");

                scanf(" %[^\n]", contacts[i].name);
            }

            /* Read and validate new phone number */
            printf("Enter New Phone: ");

            scanf(" %[^\n]", contacts[i].phone);

            while(!validate_phone(contacts[i].phone))
            {
                printf("Invalid Phone Number\n");

                printf("Enter New Phone: ");

                scanf(" %[^\n]", contacts[i].phone);
            }

            /* Read and validate new email */
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

    /* Display message if contact not found */
    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

 
/* 
   Deletes a contact from the contact list

   Parameters:
   - contacts : array storing all contacts
   - count    : pointer storing total contact count
*/
void delete_contact(struct Contact contacts[], int *count)
{
    /* Check whether contact list is empty */
    if(*count == 0)
    {
        printf("\nNo Contacts Available\n");

        return;
    }

    char search_name[NAME_LEN];

    int found = 0;

    printf("Enter Name to Delete: ");

    scanf(" %[^\n]", search_name);

    /* Validate search name */
    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");

        return;
    }

    /* Search matching contact */
    for(int i = 0; i < *count; i++)
    {
        int same = 1;

        /* Manual string comparison */
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

        /* If contact found */
        if(same)
        {
            found = 1;

            /* Shift remaining contacts left */
            for(int k = i; k < *count - 1; k++)
            {
                contacts[k] = contacts[k + 1];
            }

            /* Reduce contact count */
            (*count)--;

            printf("\nContact Deleted Successfully\n");

            break;
        }
    }

    /* Display message if contact not found */
    if(found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

 
/* 
   Displays all contacts in formatted table

   Parameters:
   - contacts : array storing all contacts
   - count    : total number of contacts
*/
void list_contacts(struct Contact contacts[], int count)
{
    /* Check whether contact list is empty */
    if(count == 0)
    {
        printf("\nAddress book is empty\n");

        return;
    }

    struct Contact temp;

    /* 
       Bubble sort contacts alphabetically
       based on contact name
    */
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

                /* Convert uppercase to lowercase */
                if(ch1 >= 'A' && ch1 <= 'Z')
                {
                    ch1 = ch1 + 32;
                }

                if(ch2 >= 'A' && ch2 <= 'Z')
                {
                    ch2 = ch2 + 32;
                }

                /* Decide whether swapping is needed */
                if(ch1 > ch2)
                {
                    swap_needed = 1;

                    break;
                }

                else if(ch1 < ch2)
                {
                    break;
                }

                /* Stop comparison at end of both strings */
                else if(ch1 == '\0' && ch2 == '\0')
                {
                    break;
                }

                k++;
            }

            /* Swap contacts if required */
            if(swap_needed)
            {
                temp = contacts[j];

                contacts[j] = contacts[j + 1];

                contacts[j + 1] = temp;
            }
        }
    }

    /* Print table header */
    printf("\n+----+------------------+------------+----------------------+\n");

    printf("| %-2s | %-16s | %-10s | %-20s |\n",
           "#",
           "Name",
           "Phone",
           "Email");

    printf("+----+------------------+------------+----------------------+\n");

    /* Print all contacts */
    for(int i = 0; i < count; i++)
    {
        printf("| %-2d | %-20s | %-13s | %-28s |\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }

    /* Print footer line */
    printf("+----+----------------------+---------------+------------------------------+\n");

    /* Display total contact count */
    printf("Total contacts: %d / %d\n",
           count,
           MAX_CONTACTS);
}