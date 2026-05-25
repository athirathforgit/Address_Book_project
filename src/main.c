#include <stdio.h>
#include "contact.h"
#include "operations.h"
#include "file_handler.h"

int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int choice,count=0;/*count shound be 0 else it  will be storing some garbage value*/
 
    while(1)
    {
        printf("\nADDRESS BOOK MENU\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List All Contacts\n");
        printf("6. Save & Exit\n");
 
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid Choice. Please Enter 1-6\n");

            while(getchar() != '\n');

            continue;
        }
         //here all are declaration
        switch(choice)
        {
            case 1:
                add_contact(contacts,&count);
                break;
 
            case 2:
                search_contact(contacts, count);
                break;
 
            case 3:
                edit_contact(contacts, count);
                break;
 
            case 4:
                delete_contact(contacts, &count);
                break;
 
            case 5:
                list_contacts(contacts, count);
                break;
 
             case 6:

                save_contacts(contacts, count);

                printf("Contacts Saved Successfully\n");

                printf("Exiting...\n");

                return 0;

            default:

                printf("Invalid choice\n");
        }
    }
}
