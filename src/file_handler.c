#include <stdio.h>     // file handling functions
#include <string.h>    // string functions
#include <stdlib.h>     //for using qsort
#include "contact.h"       // Contact structure
#include "file_handler.h"  // function declarations

int compare_contacts(const void *a, const void *b)
{
    struct Contact *c1 = (struct Contact *)a;

    struct Contact *c2 = (struct Contact *)b;

    return strcmp(c1->name, c2->name);
}

// Save all contacts into CSV file
void save_contacts(struct Contact contacts[], int count)
{
    FILE *fp;

    fp = fopen("data/contacts.csv", "w");

    // Check file opened successfully
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    // Write each contact into file
    for(int i = 0; i < count; i++)
    {
        fprintf(fp,
                "%s,%s,%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email);
    }

    fclose(fp);
}



// Load contacts from CSV file
void load_contacts(struct Contact contacts[], int *count)
{
  
    FILE *fp;
    char line[200];

    printf("Loaded Contacts...\n");
    fp = fopen("data/contacts.csv", "r");

    // If file doesn't exist
    if(fp == NULL)
    {
        return;
    }

    *count = 0;

    // Read file line by line
    while(fgets(line, sizeof(line), fp))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Split CSV data into structure fields
        sscanf(line,
               "%49[^,],%14[^,],%49[^\n]",
               contacts[*count].name,
               contacts[*count].phone,
               contacts[*count].email);

               printf("LOADED : %s\n",contacts[*count].name);

        (*count)++;

    }
    // Sort contacts alphabetically
    qsort(contacts,*count,sizeof(struct Contact),compare_contacts);


    fclose(fp);
}
