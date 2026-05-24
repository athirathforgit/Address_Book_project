#include<stdio.h>
#include<string.h>

#include"validation.h"

int validate_name(char name[])
{
    int i;

    if(strlen(name) == 0)
    {

        return 0;

    }

    for(i = 0;name[i] != '\0';i++)
    {

    if((name[i] >= 'A' && name[i] <= 'Z') ||
       (name[i] >= 'a' && name[i] <= 'z') ||
        name[i] == ' ')
        {

            continue;
        }
        else
        {
            
            return 0;
        }
    }
    return 1;

}


int validate_phone(char phone[])
{
    int i;

    if(strlen(phone) != 10)
    {
        return 0;
    }

    for(i = 0; phone[i] != '\0'; i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            return 0;
        }
    }

    return 1;

}


int validate_email(char email[])
{

    int i;
    int at_found = 0;
    int dot_found = 0;


    for(i=0;email[i] != '\0';i++)
    {

        if(email[i] == '@')
        {
            at_found=1;
        }

        else if(email[i] == '.' )
        {
            dot_found=1;
        }

        else if(email[i] ==' ')
        {
            return 0;
        }
    }

    if(at_found && dot_found)
    {
        return 1;
    }
    return 0;
}

