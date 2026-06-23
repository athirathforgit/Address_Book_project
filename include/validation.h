/*
   VALIDATION_H

   Contains function declarations used for
   validating contact details like:
   - Name
   - Phone number
   - Email address

   Also contains functions to check
   duplicate phone numbers and emails.
*/

/* Prevents multiple inclusion of header file */
#ifndef VALIDATION_H
#define VALIDATION_H

/* Includes Contact structure definition */
#include "contact.h"

/* Validates contact name */
int validate_name(char name[]);

/* Validates phone number */
int validate_phone(char phone[]);

/* Validates email address */
int validate_email(char email[]);

/* Checks whether phone number already exists */
int duplicate_phone(struct Contact contacts[],
                    int count,
                    char phone[]);

/* Checks whether email already exists */
int duplicate_email(struct Contact contacts[],
                    int count,
                    char email[]);
                    
int duplicate_phone_edit(struct Contact contacts[],
                         int count,
                         char phone[],
                         int selected_index);
#endif