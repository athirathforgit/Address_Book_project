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
    /* Check whether maximum contact limit reached */
    if (*count >= MAX_CONTACTS)
    {
        printf("Contact List Full\n");
        return;
    }
 
    /* Read and validate contact name */
    while (1)
    {
        /* Get name from user */
        printf("Enter Name: ");
        scanf(" %[^\n]", contacts[*count].name);
 
        /* Exit loop if name is valid */
        if (validate_name(contacts[*count].name))
            break;
 
        /* Display error message */
        printf("Invalid Name\n");
    }
 
    /* Read and validate phone number */
    while(1)
    {
        /* Get phone number from user */
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[*count].phone);
 
        /* Check phone format and duplicate entry */
        if(validate_phone(contacts[*count].phone) &&
           !duplicate_phone(contacts,
                            *count,
                            contacts[*count].phone))
        {
            break;
        }
 
        /* Check whether phone number already exists */
        if(duplicate_phone(contacts,
                           *count,
                           contacts[*count].phone))
        {
            printf("Phone Number Already Exists\n");
        }
        else
        {
            /* Display invalid phone message */
            printf("Invalid Phone Number\n");
        }
    }
 
    /* Read and validate email address */
    while(1)
    {
        /* Get email from user */
        printf("Enter Email: ");
        scanf(" %[^\n]", contacts[*count].email);
 
        /* Check email format and duplicate entry */
        if(validate_email(contacts[*count].email) &&
           !duplicate_email(contacts,
                            *count,
                            contacts[*count].email))
        {
            break;
        }
 
        /* Check whether email already exists */
        if(duplicate_email(contacts,
                           *count,
                           contacts[*count].email))
        {
            printf("Email Already Exists\n");
        }
        else
        {
            /* Display invalid email message */
            printf("Invalid Email\n");
        }
    }
 
    /* Increase contact count after successful insertion */
    (*count)++;
 
    /* Display success message */
    printf("\nContact Added Successfully\n");
}
/*
   Searches for a contact
*/
/*
   Searches contacts using name, phone
   or email.

   If a match is found, the contact's
   index is stored in matched_indexes[].

   Returns:
   Total number of matching contacts found.
*/
int search_contact(struct Contact contacts[],
                   int count,
                   char search_data[],
                   int matched_indexes[])
{
    /* Stores total matches found */
    int match_count = 0;

    /* Check all contacts */
    for(int i = 0; i < count; i++)
    {
        /*
           strstr() returns non-NULL if
           search_data exists in name,
           phone or email.
        */
        if(strstr(contacts[i].name, search_data) ||
           strstr(contacts[i].phone, search_data) ||
           strstr(contacts[i].email, search_data))
        {
            /* Store matching contact index */
            matched_indexes[match_count] = i;

            /* Increase match count */
            match_count++;
        }
    }

    /* Return total matches found */
    return match_count;
}

void edit_contact(struct Contact contacts[], int count)
{
    /* Check whether any contacts exist */
    if (count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    /* Stores search text entered by user */
    char search_data[50];

   /* Stores indexes of matching contacts */
   int matched_indexes[MAX_CONTACTS];

   /* Total matching contacts found */
   int match_count = 0;

   /* Accept search text from user */
   printf("Enter Name / Phone / Email to Edit: ");
   scanf(" %[^\n]", search_data);

   /* Find all matching contacts */
   match_count = search_contact(
                contacts,
                count,
                search_data,
                matched_indexes);
                /* No matching contact found */
                if (match_count == 0)
                {
                    printf("\nContact Not Found\n");
                    return;
                }

    /* Display all matching contacts */
    printf("\nMatching Contacts:\n");

    for (int i = 0; i < match_count; i++)
    {
        /*
           Retrieve actual contact index
           from matched_indexes array.
        */
        int index = matched_indexes[i];

        printf("\n%d.\n", i + 1);//serial number printing

        printf("Name   : %s\n", contacts[index].name);
        printf("Phone  : %s\n", contacts[index].phone);
        printf("Email  : %s\n", contacts[index].email);
    }

    int choice;

    /* Ask user which matching contact to edit */
    printf("\nEnter List Number to Edit: ");
    scanf("%d", &choice);

    /* Validate selected list number */
    if (choice < 1 || choice > match_count)
    {
        printf("\nInvalid Choice\n");
        return;
    }

    /*
       Convert displayed serial number
       into actual contact array index.

       Example:
       Choice = 1 -> matched_indexes[0]
       Choice = 2 -> matched_indexes[1]
    */
    int selected_index = matched_indexes[choice - 1];

    int edit_choice;

    /* Display edit menu */
    printf("\nWhat Do You Want To Edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. All Details\n");

    printf("Enter Your Choice: ");
scanf("%d", &edit_choice);

/* Edit only name */
if(edit_choice == 1)
{
    printf("\nEnter New Name: ");
    scanf(" %[^\n]", contacts[selected_index].name);

    /* Validate entered name */
    if(!validate_name(contacts[selected_index].name))
    {
        printf("Invalid Name\n");
        return;
    }
}

/* Edit only phone */
else if(edit_choice == 2)
{
    printf("\nEnter New Phone: ");
    scanf(" %[^\n]", contacts[selected_index].phone);

    /* Validate phone format */
    if(!validate_phone(contacts[selected_index].phone))
    {
        printf("Invalid Phone Number\n");
        return;
    }

    /* Check duplicate phone */
    if(duplicate_phone(contacts,
                       count,
                       contacts[selected_index].phone))
    {
        printf("Phone Number Already Exists\n");
        return;
    }
}

/* Edit only email */
else if(edit_choice == 3)
{
    printf("\nEnter New Email: ");
    scanf(" %[^\n]", contacts[selected_index].email);

    /* Validate email format */
    if(!validate_email(contacts[selected_index].email))
    {
        printf("Invalid Email\n");
        return;
    }

    /* Check duplicate email */
    if(duplicate_email(contacts,
                       count,
                       contacts[selected_index].email))
    {
        printf("Email Already Exists\n");
        return;
    }
}
/* Edit name, phone number and email address */
else if(edit_choice == 4)
{
    /* Accept and validate new name */
    printf("\nEnter New Name: ");
    scanf(" %[^\n]", contacts[selected_index].name);

    /* Stop update if entered name is invalid */
    if(!validate_name(contacts[selected_index].name))
    {
        printf("Invalid Name\n");
        return;
    }

    /* Accept new phone number */
    printf("Enter New Phone: ");
    scanf(" %[^\n]", contacts[selected_index].phone);

    /* Check whether phone number format is valid */
    if(!validate_phone(contacts[selected_index].phone))
    {
        printf("Invalid Phone Number\n");
        return;
    }

    /* Ensure phone number is not already used */
    if(duplicate_phone(contacts,
                       count,
                       contacts[selected_index].phone))
    {
        printf("Phone Number Already Exists\n");
        return;
    }

    /* Accept new email address */
    printf("Enter New Email: ");
    scanf(" %[^\n]", contacts[selected_index].email);

    /* Check whether email format is valid */
    if(!validate_email(contacts[selected_index].email))
    {
        printf("Invalid Email\n");
        return;
    }

    /* Ensure email address is unique */
    if(duplicate_email(contacts,
                       count,
                       contacts[selected_index].email))
    {
        printf("Email Already Exists\n");
        return;
    }
}
else
{
    printf("\nInvalid Edit Choice\n");
    return;
}

/* Contact updated successfully */
printf("\nContact Updated Successfully\n");
}

/*
   Deletes a contact
*/
void delete_contact(struct Contact contacts[], int *count)
{
    /* Check whether any contacts exist */
    if (*count == 0)
    {
        printf("\nNo Contacts Available\n");
        return;
    }

    /* Stores name entered by user */
    char search_name[NAME_LEN];

    /* Stores indexes of matching contacts */
    int matched_indexes[MAX_CONTACTS];

    /* Total matching contacts found */
    int match_count;

    /* Accept contact name from user */
    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", search_name);

    /* Validate entered name */
    if(validate_name(search_name) == 0)
    {
        printf("\nInvalid Name\n");
        return;
    }

    /*
       Search contact using helper function.

       Matching contact indexes are stored
       inside matched_indexes[].
    */
    match_count = search_contact(
                    contacts,
                    *count,
                    search_name,
                    matched_indexes);

    /* No matching contact found */
    if(match_count == 0)
    {
        printf("\nContact Not Found\n");
        return;
    }

    /*
       Retrieve actual contact index.

       For delete operation, first match
       is selected.
    */
    int index = matched_indexes[0];

    /*
       Shift all contacts after the deleted
       contact one position to the left.
    */
    for(int k = index; k < *count - 1; k++)
    {
        contacts[k] = contacts[k + 1];
    }

    /* Reduce total contact count */
    (*count)--;

    printf("\nContact Deleted Successfully\n");
}
  
/*
   Displays all contacts
*/
void list_contacts(struct Contact contacts[], int count)
{
    // Check if address book is empty
    if (count == 0)
    {
        printf("\nAddress book is empty\n");
        return; // Exit function if no contacts exist
    }
 
    // Print top border of table
    printf("\n+----+----------------------+---------------+------------------------------+\n");
 
    // Print table headings
    printf("| %-2s | %-20s | %-13s | %-28s |\n",
           "#",       // Serial number column
           "Name",   // Name column
           "Phone",  // Phone number column
           "Email"); // Email column
 
    // Print separator line
    printf("+----+----------------------+---------------+------------------------------+\n");
 
    // Loop through all contacts
    for (int i = 0; i < count; i++)
    {
        // Print each contact details in table format
        printf("| %-2d | %-20s | %-13s | %-28s |\n",
               i + 1,                // Contact number (starts from 1)
               contacts[i].name,    // Contact name
               contacts[i].phone,   // Contact phone number
               contacts[i].email);  // Contact email
    }
 
    // Print bottom border of table
    printf("+----+----------------------+---------------+------------------------------+\n");
 
    // Display total number of contacts stored
    printf("Total contacts: %d / %d\n",
           count,         // Current number of contacts
           MAX_CONTACTS); // Maximum allowed contacts
}