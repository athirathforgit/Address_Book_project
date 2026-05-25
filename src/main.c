/* Standard input-output functions */
#include <stdio.h>

/* Contains Contact structure definition */
#include "contact.h"

/* Contains contact operation function declarations */
#include "operations.h"

/* Contains file handling function declarations */
#include "file_handler.h"


/* Program execution starts from main() */
int main()
{
    /* Array used to store all contacts */
    struct Contact contacts[MAX_CONTACTS];

    /* 
       choice -> stores user menu choice
       count  -> stores current number of contacts

       count is initialized to 0 to avoid garbage value
    */
    int choice, count = 0;

    /* Load contacts from CSV file into memory */
    load_contacts(contacts, &count);
    
    /* Infinite loop for menu-driven program */
    while(1)
    {
        /* Display menu options */
        printf("\nADDRESS BOOK MENU\n");

        printf("1. Add Contact\n");

        printf("2. Search Contact\n");

        printf("3. Edit Contact\n");

        printf("4. Delete Contact\n");

        printf("5. List All Contacts\n");

        printf("6. Save & Exit\n");
 
        printf("Enter your choice: ");

        /* 
           Validate menu input

           scanf() returns:
           - 1 if integer input is successful
           - 0 if invalid input is entered
        */
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid Choice. Please Enter 1-6\n");

            /* Clear invalid input from buffer */
            while(getchar() != '\n');

            continue;
        }

        /* Perform operation based on user choice */
        switch(choice)
        {
            /* Add new contact */
            case 1:
                add_contact(contacts, &count);
                break;
 
            /* Search existing contact */
            case 2:
                search_contact(contacts, count);
                break;
 
            /* Edit contact details */
            case 3:
                edit_contact(contacts, count);
                break;
 
            /* Delete contact */
            case 4:
                delete_contact(contacts, &count);
                break;
 
            /* Display all contacts */
            case 5:
                list_contacts(contacts, count);
                break;
 
            /* Save contacts and exit program */
            case 6:

                save_contacts(contacts, count);

                printf("Contacts Saved Successfully\n");

                printf("Exiting...\n");

                return 0;

            /* Handles invalid menu choices */
            default:

                printf("Invalid choice\n");
        }
    }
}