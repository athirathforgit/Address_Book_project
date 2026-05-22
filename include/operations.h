#ifndef OPERATIONS_H
#define OPERATIONS_H
 
#include "contact.h"
 
void add_contact(struct Contact contacts[], int * count);
 
void search_contact(struct Contact contacts[], int count);
 
void edit_contact(struct Contact contacts[], int count);
 
void delete_contact(struct Contact contacts[], int *count);
 
void list_contacts(struct Contact contacts[], int count);
 
#endif