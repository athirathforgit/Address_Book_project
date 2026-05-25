#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "contact.h"

void save_contacts(struct Contact contacts[], int count);

void load_contacts(struct Contact contacts[], int *count);

#endif