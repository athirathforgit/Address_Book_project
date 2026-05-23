/*#ifndef is used because a header file can be included multiple times indirectly, 
and that causes duplicate definitions */
#ifndef CONTACT_H
#define CONTACT_H
 
#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50
 
struct Contact
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
 
};
#endif