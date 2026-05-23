#include <stdio.h>
#include "operations.h"
#include "validation.h"
 
void add_contact(struct Contact contacts[], int * count)
{
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
        /*here count is 0 but in contact start from 1 so for
         printing purpose we are adding i+1 */
        printf("\n Contact %d \n",i + 1);
        
        printf("Name   : %s \n",contacts[i].name);
        printf("Phone  : %s \n",contacts[i].phone);
        printf("Email  : %s \n",contacts[i].email);

    }

}
