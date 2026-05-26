/* Standard input-output functions */
#include <stdio.h>

/* String handling functions */
#include <string.h>

/* Contains function declarations for contact operations */
#include "operations.h"

/* Contains validation function declarations */
#include "validation.h"

/*
   Adds a new contact into the contact list
*/
void add_contact(struct Contact contacts[], int *count)
{
    if (*count >= MAX_CONTACTS)
    {
        printf("Contact List Full\n");
        return;
    }

    while (1)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", contacts[*count].name);

        if (validate_name(contacts[*count].name))
            break;

        printf("Invalid Name\n");
    }

    while (1)
    {
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[*count].phone);

        if (validate_phone(contacts[*count].phone))
            break;

        printf("Invalid Phone Number\n");
    }

    while (1)
    {
        printf("Enter Email: ");
        scanf(" %[^\n]", contacts[*count].email);

        if (validate_email(contacts[*count].email))
            break;

        printf("Invalid Email\n");
    }

    (*count)++;

    printf("\nContact Added Successfully\n");
}

/*
   Searches for a contact
*/
void search_contact(struct Contact contacts[], int count)
{
    if (count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    char search_data[50];
    int found = 0;

    printf("Enter Name / Phone / Email to Search: ");
    scanf(" %[^\n]", search_data);

    for (int i = 0; i < count; i++)
    {
        if (strstr(contacts[i].name, search_data) ||
            strstr(contacts[i].phone, search_data) ||
            strstr(contacts[i].email, search_data))
        {
            printf("\nContact Found\n");

            printf("Name   : %s\n", contacts[i].name);
            printf("Phone  : %s\n", contacts[i].phone);
            printf("Email  : %s\n", contacts[i].email);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

/*
   Edits existing contact details
*/
void edit_contact(struct Contact contacts[], int count)
{
    if (count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    char search_data[50];

    int matched_indexes[MAX_CONTACTS];
    int match_count = 0;

    printf("Enter Name / Phone / Email to Edit: ");
    scanf(" %[^\n]", search_data);

    for (int i = 0; i < count; i++)
    {
        if (strstr(contacts[i].name, search_data) ||
            strstr(contacts[i].phone, search_data) ||
            strstr(contacts[i].email, search_data))
        {
            matched_indexes[match_count] = i;
            match_count++;
        }
    }

    if (match_count == 0)
    {
        printf("\nContact Not Found\n");
        return;
    }

    printf("\nMatching Contacts:\n");

    for (int i = 0; i < match_count; i++)
    {
        int index = matched_indexes[i];

        printf("\n%d.\n", i + 1);
        printf("Name   : %s\n", contacts[index].name);
        printf("Phone  : %s\n", contacts[index].phone);
        printf("Email  : %s\n", contacts[index].email);
    }

    int choice;

    printf("\nEnter List Number to Edit: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > match_count)
    {
        printf("\nInvalid Choice\n");
        return;
    }

    int selected_index = matched_indexes[choice - 1];

    int edit_choice;

    printf("\nWhat Do You Want To Edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. All Details\n");

    printf("Enter Your Choice: ");
    scanf("%d", &edit_choice);

    if (edit_choice == 1)
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", contacts[selected_index].name);

        while (!validate_name(contacts[selected_index].name))
        {
            printf("Invalid Name\n");

            printf("Enter New Name: ");
            scanf(" %[^\n]", contacts[selected_index].name);
        }
    }

    else if (edit_choice == 2)
    {
        printf("\nEnter New Phone: ");
        scanf(" %[^\n]", contacts[selected_index].phone);

        while (!validate_phone(contacts[selected_index].phone))
        {
            printf("Invalid Phone Number\n");

            printf("Enter New Phone: ");
            scanf(" %[^\n]", contacts[selected_index].phone);
        }
    }

    else if (edit_choice == 3)
    {
        printf("\nEnter New Email: ");
        scanf(" %[^\n]", contacts[selected_index].email);

        while (!validate_email(contacts[selected_index].email))
        {
            printf("Invalid Email\n");

            printf("Enter New Email: ");
            scanf(" %[^\n]", contacts[selected_index].email);
        }
    }

    else if (edit_choice == 4)
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", contacts[selected_index].name);

        while (!validate_name(contacts[selected_index].name))
        {
            printf("Invalid Name\n");

            printf("Enter New Name: ");
            scanf(" %[^\n]", contacts[selected_index].name);
        }

        printf("Enter New Phone: ");
        scanf(" %[^\n]", contacts[selected_index].phone);

        while (!validate_phone(contacts[selected_index].phone))
        {
            printf("Invalid Phone Number\n");

            printf("Enter New Phone: ");
            scanf(" %[^\n]", contacts[selected_index].phone);
        }

        printf("Enter New Email: ");
        scanf(" %[^\n]", contacts[selected_index].email);

        while (!validate_email(contacts[selected_index].email))
        {
            printf("Invalid Email\n");

            printf("Enter New Email: ");
            scanf(" %[^\n]", contacts[selected_index].email);
        }
    }

    else
    {
        printf("\nInvalid Edit Choice\n");
        return;
    }

    printf("\nContact Updated Successfully\n");
}

/*
   Deletes a contact
*/
void delete_contact(struct Contact contacts[], int *count)
{
    if (*count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    char search_name[NAME_LEN];

    int found = 0;

    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", search_name);

    if (validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");
        return;
    }

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(search_name, contacts[i].name) == 0)
        {
            found = 1;

            for (int k = i; k < *count - 1; k++)
            {
                contacts[k] = contacts[k + 1];
            }

            (*count)--;

            printf("\nContact Deleted Successfully\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("\nContact Not Found\n");
    }
}

/*
   Displays all contacts
*/
void list_contacts(struct Contact contacts[], int count)
{
    if (count == 0)
    {
        printf("\nAddress book is empty\n");
        return;
    }

    printf("\n+----+----------------------+---------------+------------------------------+\n");

    printf("| %-2s | %-20s | %-13s | %-28s |\n",
           "#",
           "Name",
           "Phone",
           "Email");

    printf("+----+----------------------+---------------+------------------------------+\n");

    for (int i = 0; i < count; i++)
    {
        printf("| %-2d | %-20s | %-13s | %-28s |\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }

    printf("+----+----------------------+---------------+------------------------------+\n");

    printf("Total contacts: %d / %d\n",
           count,
           MAX_CONTACTS);
}