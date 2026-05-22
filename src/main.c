#include <stdio.h>
#include "contact.h"
#include "operations.h"

int main()
{
    int choice;
 
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
        scanf("%d", &choice);
 
        switch(choice)
        {
            case 1:
                add_contact();
                break;
 
            case 2:
                search_contact();
                break;
 
            case 3:
                edit_contact();
                break;
 
            case 4:
                delete_contact();
                break;
 
            case 5:
                list_contact();
                break;
 
            case 6:
                printf("Exiting...\n");
                return 0;
 
            default:
                printf("Invalid choice\n");
        }
    }
}
