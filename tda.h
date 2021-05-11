#pragma once

typedef struct {
    char name[20];
    int id;
} Contact;

typedef struct {
    Contact contacts[20];
    int nbrContact;   
} List;

// fonction principale pour le test
void tda();

/**
 * @brief Get the Name object
 * 
 * @param l la list des contacts
 * @param pos la position dans le tableau
 * @return  le nom du contact
 */
char* getName(List* l, int pos);