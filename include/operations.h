/*
   Header guard prevents multiple inclusion
   of this header file during compilation
*/
#ifndef OPERATIONS_H
#define OPERATIONS_H

/* Includes structure definition of Contact */
#include "contact.h"

/* Adds a new contact into the contact array */
void add_contact(struct Contact contacts[], int *count);

/* Searches for a contact using name */
int search_contact(struct Contact contacts[],
                   int count,
                   char search_data[],
                   int matched_indexes[]);

void search_contact_display(struct Contact contacts[],
                            int count);

/* Edits existing contact details */
void edit_contact(struct Contact contacts[], int count);

/* Deletes a contact from the array */
void delete_contact(struct Contact contacts[], int *count);

/* Displays all contacts in formatted form */
void list_contacts(struct Contact contacts[], int count);

#endif