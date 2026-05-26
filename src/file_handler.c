/* Standard input-output functions */
#include <stdio.h>

/* String handling functions */
#include <string.h>

/* Standard library functions
   Used here for qsort() */
#include <stdlib.h>

/* Contains Contact structure definition */
#include "contact.h"

/* Contains file handling function declarations */
#include "file_handler.h"

/*
   Comparison function used by qsort()

   Compares contact names alphabetically
   and returns:
   - negative value if c1 < c2
   - positive value if c1 > c2
   - 0 if both are equal
*/


/*
   Saves all contacts into CSV file

   Parameters:
   - contacts : array containing all contacts
   - count    : total number of contacts
*/
void save_contacts(struct Contact contacts[], int count)
{
    FILE *fp;

    /* Open CSV file in write mode */
    fp = fopen("data/contacts.csv", "w");

    /* Check whether file opened successfully */
    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    /* Write each contact into CSV file */
    for (int i = 0; i < count; i++)
    {
        fprintf(fp,
                "%s,%s,%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email);
    }

    /* Close file after writing */
    fclose(fp);
}

/*
   Loads contacts from CSV file into memory

   Parameters:
   - contacts : array where contacts are stored
   - count    : pointer used to update total contacts loaded
*/
void load_contacts(struct Contact contacts[], int *count)
{
    FILE *fp;

    /* Stores each line read from file */
    char line[200];

    printf("Loaded Contacts...\n");

    /* Open CSV file in read mode */
    fp = fopen("data/contacts.csv", "r");

    /* If file does not exist, return */
    if (fp == NULL)
    {
        return;
    }

    /* Initialize contact count */
    *count = 0;

    /* Read file line by line */
    while (fgets(line, sizeof(line), fp))
    {
        /* Remove newline character from line */
        line[strcspn(line, "\n")] = '\0';

        /*
           Extract CSV values and store into structure

           %49[^,]  -> reads name until comma
           %14[^,]  -> reads phone until comma
           %49[^\n] -> reads email until newline
        */
        sscanf(line,
               "%49[^,],%14[^,],%49[^\n]",
               contacts[*count].name,
               contacts[*count].phone,
               contacts[*count].email);

        /* Display loaded contact name */
        printf("LOADED : %s\n", contacts[*count].name);

        /* Increase contact count */
        (*count)++;
    }

    /* Sort contacts alphabetically after loading */
    
    /* Close file after reading */
    fclose(fp);
}