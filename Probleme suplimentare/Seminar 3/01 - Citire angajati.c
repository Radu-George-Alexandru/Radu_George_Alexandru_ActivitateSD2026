#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* copiazaText(const char* text) {
    if (text == NULL) return NULL;
    char* copie = (char*)malloc(strlen(text) + 1);
    strcpy(copie, text);
    return copie;
}

typedef struct Angajat {
    int id;
    int varsta;
    float salariu;
    char* nume;
    char* departament;
    char grad;
} Angajat;

int citireAngajatFisier(FILE* f, Angajat* a) {
    char buffer[256];
    char sep[] = ",\n";

    if (fgets(buffer, sizeof(buffer), f) == NULL) return 0;

    char* token = strtok(buffer, sep);
    if (!token) return 0;
    a->id = atoi(token);

    token = strtok(NULL, sep);
    if (!token) return 0;
    a->varsta = atoi(token);

    token = strtok(NULL, sep);
    if (!token) return 0;
    a->salariu = (float)atof(token);

    token = strtok(NULL, sep);
    if (!token) return 0;
    a->nume = copiazaText(token);

    token = strtok(NULL, sep);
    if (!token) return 0;
    a->departament = copiazaText(token);

    token = strtok(NULL, sep);
    if (!token) return 0;
    a->grad = token[0];

    return 1;
}

void adaugaAngajatInVector(Angajat** vector, int* nr, Angajat a) {
    Angajat* temp = (Angajat*)malloc(sizeof(Angajat) * ((*nr) + 1));
    for (int i = 0; i < *nr; i++) {
        temp[i] = (*vector)[i];
    }
    temp[*nr] = a;
    free(*vector);
    *vector = temp;
    (*nr)++;
}

