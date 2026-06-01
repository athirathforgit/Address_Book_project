/* Standard input-output functions */
#include<stdio.h>

/* String handling functions */
#include<string.h>

/* Contains validation function declarations */
#include"validation.h"


/* 
   Validates contact name

   Rules:
   - Name should not be empty
   - Only alphabets and spaces are allowed

   Returns:
   - 1 if valid
   - 0 if invalid
*/
int validate_name(char name[])
{
    int i;

    /* Check for empty string */
    if(strlen(name) == 0)
    {
        return 0;
    }

    /* Check each character */
    for(i = 0; name[i] != '\0'; i++)
    {
        /* Allow uppercase letters */
        if((name[i] >= 'A' && name[i] <= 'Z') ||

           /* Allow lowercase letters */
           (name[i] >= 'a' && name[i] <= 'z') ||

           /* Allow spaces */
            name[i] == ' ')
        {
            continue;
        }

        /* Invalid character found */
        else
        {
            return 0;
        }
    }

    /* Name is valid */
    return 1;
}


/* 
   Validates phone number

   Rules:
   - Must contain exactly 10 digits
   - Only numeric characters are allowed

   Returns:
   - 1 if valid
   - 0 if invalid
*/
int validate_phone(char phone[])
{
    int i;

    /* Check phone number length */
    if(strlen(phone) != 10)
    {
        return 0;
    }

    /* Check each character is digit */
    for(i = 0; phone[i] != '\0'; i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            return 0;
        }
    }

    /* Phone number is valid */
    return 1;
}


/* 
   Validates email address

   Rules:
   - Must contain '@'
   - Must contain '.'
   - Spaces are not allowed

   Returns:
   - 1 if valid
   - 0 if invalid
*/
int validate_email(char email[])
{
    int i;

    /* Stores position of '@' symbol */
    int at_pos = -1;

    /* Stores position of last '.' symbol */
    int dot_pos = -1;

    /* Counts total '@' symbols */
    int at_count = 0;

    /* Find length of email */
    int len = strlen(email);

    /* Check for empty email */
    if(len == 0)
    {
        return 0;
    }

    /* Scan each character of email */
    for(i = 0; email[i] != '\0'; i++)
    {
        /* Reject spaces in email */
        if(email[i] == ' ')
        {
            return 0;
        }

        /* Count '@' and store its position */
        if(email[i] == '@')
        {
            at_count++;

            at_pos = i;
        }

        /* Store latest '.' position */
        if(email[i] == '.')
        {
            dot_pos = i;
        }
    }

    /* Email must contain exactly one '@' */
    if(at_count != 1)
    {
        return 0;
    }

    /* Check characters exist before '@' */
    if(at_pos <= 0)
    {
        return 0;
    }

    /* Check '.' comes after '@'
       and at least one character exists between them */
    if(dot_pos < at_pos + 2)
    {
        return 0;
    }

    /* Check at least two characters exist after '.' */
    if(dot_pos >= len - 2)
    {
        return 0;
    }

    /* Email is valid */
    return 1;
}
/* 
   Checks whether phone number already exists

   Returns:
   1 -> Duplicate Found
   0 -> Unique Number
*/
int duplicate_phone(struct Contact contacts[],
                    int count,
                    char phone[])
{
    /* Check all existing contacts */
    for(int i = 0; i < count; i++)
    {
        /* Compare phone numbers */
        if(strcmp(contacts[i].phone, phone) == 0)
        {
            return 1;
        }
    }

    /* No duplicate found */
    return 0;
}

/* 
   Checks whether email already exists

   Returns:
   1 -> Duplicate Found
   0 -> Unique Email
*/
int duplicate_email(struct Contact contacts[],
                    int count,
                    char email[])
{
    /* Check all existing contacts */
    for(int i = 0; i < count; i++)
    {
        /* Compare email addresses */
        if(strcmp(contacts[i].email, email) == 0)
        {
            return 1;
        }
    }

    /* No duplicate found */
    return 0;
}