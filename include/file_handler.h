/*
   FILE_HANDLER_H

   This header file contains function declarations
   related to file handling operations.

   These functions are used to:
   - Save contacts into a CSV file
   - Load contacts from a CSV file

   Header guards prevent multiple inclusion
   of this file during compilation.
*/

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "contact.h"

/*
   Saves all contacts from memory into a file.

   Parameters:
   - contacts : Array of contact structures
   - count    : Number of contacts currently stored
*/
void save_contacts(struct Contact contacts[], int count);

/*
   Loads contacts from file into memory.

   - Parameters:
   - contacts : Array where contacts will be stored
   - count    : Pointer used to update total contacts loaded
*/
void load_contacts(struct Contact contacts[], int *count);

#endif