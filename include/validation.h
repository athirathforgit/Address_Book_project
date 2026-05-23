/*#ifndef is used because a header file can be included multiple times indirectly, 
and that causes duplicate definitions */
#ifndef VALIDATION_H
#define VALIDATION_H

#include "contact.h"

int validate_name(char name[]);

int validate_phone(char phone[]);

int validate_email(char email[]);

int duplicate_phone(struct Contact contacts[],
    int count,
    char phone[]);

int duplicate_email(struct Contact contacts[],
    int count,
    char email[]);

#endif