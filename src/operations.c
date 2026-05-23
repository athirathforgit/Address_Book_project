#include <stdio.h>
#include "operations.h"
 
void add_contact(struct Contact contacts[], int * count)
{
    printf("\nEnter Name: ");/*reading name to the structure array */
    scanf(" %[^\n]",contacts[*count].name);

    printf("\nEnter Phone: ");/*reading phone number to the structure array*/
     scanf(" %[^\n]",contacts[*count].phone);

    printf("\nEnter Email: ");/*reading Email to the structure array*/
     scanf(" %[^\n]",contacts[*count].email);

     (*count)++;

     printf("\n Contact Added Successfully \n");
}
 
void search_contact(struct Contact contacts[], int count)
{
    printf("Search Contact feature coming soon\n");
}
 
void edit_contact(struct Contact contacts[], int count)
{
    printf("Edit Contact feature coming soon\n");
}
 
void delete_contact(struct Contact contacts[], int * count)
{
    printf("Delete Contact feature coming soon\n");
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
        printf("\n Contact %d \n",i + 1);/*here count is 0 but in contact start from 1 so for 
                                            printing purpose we are adding i+1 */
        
        printf("Name   : %s \n",contacts[i].name);
        printf("Phone  : %s \n",contacts[i].phone);
        printf("Email  : %s \n",contacts[i].email);

    }

}
