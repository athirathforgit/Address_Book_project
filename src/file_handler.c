#include <stdio.h>
#include "contact.h"

void save_contact(Contact c)
{
    FILE *fp;

    fp = fopen("data/contacts.csv", "a");

    if(fp == NULL)
    {
        printf("File not opened\n");
        return;
    }

    fprintf(fp,
            "%s,%s,%s\n",
            c.name,
            c.phone,
            c.email);

    fclose(fp);

    printf("Contact Saved Successfully\n");
}
