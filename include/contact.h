/* 
   CONTACT_H

   This header file contains:
   - Macro definitions for array sizes
   - Structure definition for storing contact details

   Header guards are used to prevent multiple inclusion
   of the same header file during compilation.
*/

#ifndef CONTACT_H
#define CONTACT_H

/* Maximum number of contacts that can be stored */
#define MAX_CONTACTS 100

/* Maximum size for storing contact name */
#define NAME_LEN 50

/* Maximum size for storing phone number
   Extra space is kept for safety and null character */
#define PHONE_LEN 15

/* Maximum size for storing email address */
#define EMAIL_LEN 50

/* 
   Structure to store a single contact

   Each contact contains:
   - Name
   - Phone number
   - Email address
*/
struct Contact
{
    char name[NAME_LEN]; /* Stores contact name */
    char phone[PHONE_LEN]; /* Stores phone number */
    char email[EMAIL_LEN]; /* Stores email address */
};

#endif