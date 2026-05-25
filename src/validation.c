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

    /* Flag to check '@' symbol */
    int at_found = 0;

    /* Flag to check '.' symbol */
    int dot_found = 0;

    /* Check each character */
    for(i = 0; email[i] != '\0'; i++)
    {
        /* Check for '@' */
        if(email[i] == '@')
        {
            at_found = 1;
        }

        /* Check for '.' */
        else if(email[i] == '.')
        {
            dot_found = 1;
        }

        /* Spaces are not allowed */
        else if(email[i] == ' ')
        {
            return 0;
        }
    }

    /* Email is valid only if both exist */
    if(at_found && dot_found)
    {
        return 1;
    }

    /* Invalid email */
    return 0;
}